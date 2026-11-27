
CC = cc
CFLAGS = -Wall -Werror -Wextra

AR = ar
ARFLAGS = rcs
RM = rm -f

NAME = libftprintf.a

SOURCES = MainPath/arg_print.c \
          MainPath/bsc_print.c \
          MainPath/check_conv.c \
          MainPath/chk_prc.c \
          MainPath/ft_printf.c \
          types/ft_adrprt.c \
          types/ft_itoa_diux.c \
          types/ft_itoa_X.c \
          types/ft_putchar.c \
          types/ft_putstr.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

test: $(OBJECTS)
	$(CC) $(CFLAGS) -I. main.c $(OBJECTS) -o test

$(NAME): $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c Makefile ft_printf.h
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re test
