CC = cc 
CFLAGS = -Wall -Wextra -Werror
CFS = ft_printf.c ft_printarg.c ft_printchar.c ft_printstr.c ft_printnbr.c ft_printhex.c ft_printunbr.c
OFS = $(CFS:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OFS)
	ar -rcs $(NAME) $(OFS)

%.o:%.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OFS)

fclean: clean
	rm -f $(NAME)

re: fclean all
