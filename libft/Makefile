
CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = libft.a

CFS = ft_printf/ft_printf.c ft_printf/ft_printarg.c ft_printf/ft_printchar.c ft_printf/ft_printstr.c ft_printf/ft_printnbr.c ft_printf/ft_printhex.c ft_printf/ft_printunbr.c\
		ft_putstr_fd.c ft_strlen.c ft_strncmp.c ft_strchr.c ft_strdup.c ft_itoa.c\

OFS = $(CFS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OFS)
	ar -rcs $(NAME) $(OFS)

%.o:%. c
	$(CC) $(CFLAGS) -c $<

clean:
	rm  -f $(OFS) $(BOFS)

fclean: clean 
	rm  -f $(NAME)

re: fclean all
