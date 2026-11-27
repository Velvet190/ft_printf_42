*This project has been created as part of the 42 curriculum by vlaval-a.*

# ft_printf

## Description

**ft_printf** is a re-implementation of the C standard library function `printf()`, written in C and packaged as a static library, `libftprintf.a`.

The goal of the project is to learn how **variadic functions** work in C (`<stdarg.h>`) and to build a well-structured, extensible code base that parses a format string and prints formatted output through `write()`.

Prototype:

```c
int ft_printf(const char *, ...);
```

The function returns the number of characters printed, like the original `printf()`. As required by the subject, the buffer management of the original `printf()` is **not** implemented: output is written directly with `write()`.

### Supported conversions

| Specifier | Output |
|:---:|---|
| `%c` | A single character |
| `%s` | A string (`(null)` if the pointer is `NULL`) |
| `%p` | A `void *` pointer in hexadecimal, prefixed with `0x` (`(nil)` if `NULL`, like glibc on Linux) |
| `%d` | A signed decimal integer |
| `%i` | A signed decimal integer |
| `%u` | An unsigned decimal integer |
| `%x` | An unsigned integer in lowercase hexadecimal |
| `%X` | An unsigned integer in uppercase hexadecimal |
| `%%` | A literal percent sign |

Flags, field width, precision and length modifiers (the bonus part) are **not** implemented.

### Project structure

```text
.
├── Makefile
├── README.md
├── ft_printf.h
├── MainPath/
│   ├── ft_printf.c     # entry point (va_start / va_end)
│   ├── bsc_print.c     # format string parsing loop
│   └── arg_print.c     # dispatch of a conversion to its printing function
└── types/
    ├── ft_putchar.c    # %c, %%
    ├── ft_putstr.c     # %s
    ├── ft_adrprt.c     # %p
    ├── ft_itoa_diux.c  # %d, %i, %u, %x
    └── ft_itoa_X.c     # %X
```

## Instructions

### Compilation

The library is compiled with `cc` and the flags `-Wall -Wextra -Werror`:

```bash
make
```

This creates `libftprintf.a` at the root of the repository, using `ar`.

| Command | Effect |
|---|---|
| `make` / `make all` | Builds `libftprintf.a` (no unnecessary relinking) |
| `make clean` | Removes the object files |
| `make fclean` | Removes the object files and `libftprintf.a` |
| `make re` | Rebuilds everything from scratch |

### Usage

Include the header and link the library:

```c
#include "ft_printf.h"

int main(void)
{
	ft_printf("Hello %s, you have %d new messages (id: %x)\n", "world", 42, 255);
	return (0);
}
```

```bash
cc main.c -I. -L. -lftprintf -o program
./program
```

### Testing

You can compare `ft_printf` against the original `printf` on the same arguments, checking both the printed text and the returned value:

```c
int a = printf("%d %x %s|\n", -42, 255, "abc");
int b = ft_printf("%d %x %s|\n", -42, 255, "abc");
/* a and b must be equal, and the two lines must be identical */
```

## Algorithm and data structures

### Overall algorithm

The implementation is a single left-to-right pass over the format string, with no intermediate buffer:

1. `ft_printf` initializes the `va_list` with `va_start`, calls the parser, then releases it with `va_end`.
2. `bsc_print` walks through the format string one character at a time:
   - a normal character is written directly with `write(1, ..., 1)`;
   - a `%` followed by a character consumes both and hands the conversion character to `arg_print`.
3. `arg_print` selects the right function for the conversion character and fetches the matching argument with `va_arg`, using the **exact type that the caller passed** (`int` for `%c`, `%d`, `%i`; `unsigned int` for `%u`, `%x`, `%X`; `char *` for `%s`; `void *` for `%p`).
4. Every printing function returns the number of characters it wrote, and these values are summed to produce the return value of `ft_printf`.

**Why this design:** parsing and printing are separated, so adding a new conversion only means adding one branch in `arg_print` and one printing function, without touching the parser. A single pass over the string is linear in the length of the output and needs no dynamic structure to remember the format.

### Number conversion

All integer conversions share the same method, parameterized by the base (10 or 16):

1. **Count the digits** by dividing the value by the base until it reaches 0 (one extra character is reserved for `0` and for the `-` sign of negative numbers).
2. **Allocate** a string of exactly that length + 1 with `malloc`.
3. **Fill it recursively**: the function calls itself on `value / base` first, then writes the digit `value % base`, so the most significant digit ends up first without needing to reverse the string.
4. **Write** the string with `write`, **free** it, and return its length.

Specific choices:

- Signed numbers are converted through a `long` before being negated, so that `INT_MIN` (whose absolute value does not fit in an `int`) is handled correctly.
- `%X` reuses the lowercase conversion, then switches the letters to uppercase before writing them.
- `%p` converts the pointer to an `unsigned long` (64 bits on the target platform), prints `0x` followed by its hexadecimal form, and prints `(nil)` for a `NULL` pointer, which is what glibc does.
- `%s` prints `(null)` when it receives a `NULL` pointer, which also matches glibc.

**Data structure:** the only data structure is a temporary heap-allocated character array, sized exactly for the number to print. It is freed before the function returns, so there is no memory leak. Choosing the exact size avoids both overflows and any need for a fixed-size buffer. The conversions themselves are recognised with a simple `if / else if` chain on a single character, which is enough for nine specifiers and easy to read.

## Resources

### References

- `man 3 printf`: behavior and format specification of the original function
- `man 3 stdarg`: `va_start`, `va_arg`, `va_copy`, `va_end`
- `man 2 write`: the system call used for all output
- [GNU C Library manual, "Variadic Functions"](https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html)
- ISO/IEC 9899 (C standard), section on `<stdarg.h>`
- The 42 Norm

### Use of AI

AI (Claude) was used for the following tasks only:

- reviewing the project against the subject (Norm, Makefile rules, required files, README requirements) and pointing out problems such as the wrong `va_arg` type for `%x` and `%X`;
- helping to write and structure this README.

The code of the library itself was written by me, and I tested and debugged it by comparing it with the original `printf()`.