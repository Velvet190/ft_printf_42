*This project has been created as part of the 42 curriculum by vlaval-a.*

# ft_printf

## Description

**ft_printf** is a re-implementation of the C function `printf()`, packaged as a static library (`libftprintf.a`). The goal is to learn how **variadic functions** work in C (`<stdarg.h>`) and to write a clean, extensible format-string parser that prints through `write()`.

```c
int ft_printf(const char *, ...);
```

It returns the number of characters printed (or `-1` if the format string is `NULL`). As required by the subject, the buffer management of the original `printf()` is **not** implemented: everything is written directly with `write()`.

| Specifier | Output |
|:---:|---|
| `%c` | A single character |
| `%s` | A string (`(null)` if the pointer is `NULL`) |
| `%p` | A `void *` in hexadecimal, prefixed with `0x` (`(nil)` if `NULL`, as glibc does on Linux) |
| `%d` `%i` | A signed decimal integer |
| `%u` | An unsigned decimal integer |
| `%x` `%X` | An unsigned integer in lowercase / uppercase hexadecimal |
| `%%` | A percent sign |

Flags, width, precision and length modifiers (bonus) are **not** implemented.

### Repository content

```text
.
├── Makefile
├── README.md
├── ft_printf.h          # prototypes of the whole project
├── MainPath/
│   ├── ft_printf.c      # entry point: va_start / va_end
│   ├── chk_prc.c        # checks whether the format contains a '%'
│   ├── bsc_print.c      # format string parsing loop
│   ├── arg_print.c      # dispatches a conversion to its printing function
│   └── check_conv.c     # checks that a character is a supported specifier
└── types/
    ├── ft_putchar.c     # %c and %%
    ├── ft_putstr.c      # %s
    ├── ft_adrprt.c      # %p
    ├── ft_itoa_diux.c   # %d, %i, %u, %x
    └── ft_itoa_X.c      # %X
```

## Instructions

Build the library (compiled with `cc -Wall -Wextra -Werror`, archived with `ar`):

```bash
make          # creates libftprintf.a at the root, without useless relinking
make clean    # removes the object files
make fclean   # removes the object files and libftprintf.a
make re       # fclean + all
```

Use it in your own program:

```c
#include "ft_printf.h"

int main(void)
{
	ft_printf("Hello %s, %d messages, id: %x\n", "world", 42, 255);
	return (0);
}
```

```bash
cc main.c -I. -L. -lftprintf -o program && ./program
```

To test it, compare the output **and** the return value with the original `printf()` on the same arguments.

## Algorithm and data structures

**Parsing.** `ft_printf` calls `va_start`, then `chk_prc` checks whether the format contains a `%`: if not, the string is simply printed. Otherwise `bsc_print` makes a single left-to-right pass over the format:

- a normal character is written directly with `write`;
- a `%` followed by a character sends that character to `arg_print`, which uses an `if / else if` chain to pick the printing function and fetches the argument with `va_arg`, using the **exact type passed by the caller** (`int` for `%c %d %i`, `unsigned int` for `%u %x %X`, `char *` for `%s`, `void *` for `%p`).

Each function returns the number of characters it wrote, and the values are summed into the return value. **Why:** parsing and printing are separate, so a new conversion only needs one new branch in `arg_print` and one printing function; a single pass is linear and needs no structure to remember the format.

**Number conversion.** `ft_itoa_signd` (`%d %i`), `ft_itoa_unsignd` (`%u %x`, and `%p` through `ft_adrprt`) and `ft_itoa_unsigndmajx` (`%X`) use the same method, parameterized by the base:

1. count the digits by dividing by the base (plus one slot for `0` or the `-` sign);
2. `malloc` exactly that length + 1;
3. fill the string recursively: the function calls itself on `value / base` first, then writes the digit, so the most significant digit comes first without reversing the string;
4. `write` it, `free` it, and return its length.

Specific choices: signed values go through a `long` before being negated so that `INT_MIN` works; `%X` builds the lowercase string then converts it to uppercase before writing; `%p` uses an `unsigned long` (64 bits) and prints `0x` + hexadecimal, or `(nil)` for `NULL`.

**Data structure.** The only structure is a temporary heap-allocated `char` array sized exactly for the number, freed before the function returns (no leak, no overflow, no fixed-size buffer).

## Resources

- `man 3 printf`, `man 3 stdarg`, `man 2 write`
- [GNU C Library manual, "Variadic Functions"](https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html)
- ISO/IEC 9899 (C standard), `<stdarg.h>`
- The 42 Norm

**Use of AI.** AI (Claude) was used to review the project against the subject (Norm, Makefile, required files, README) and to help write and structure this README. The code of the library was written by me and tested by comparing it with the original `printf()`.