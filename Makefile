CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_hexa.c ft_putchar.c ft_putnbr.c\
		ft_putnbruns.c ft_putstr.c ft_printf.c

SRCS_BONUS = ft_bonus.c ft_hexa_bonus ft_putnbr_bonus.c

OBJS= $(SRCS:.c=.o)

OBJS_BONUS= $(SRCS_BONUS:.c=.o) 

NAME = libftprintf.a

all : $(NAME)


$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

Bonus : $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS_BONUS)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@ 	

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

fclean:clean
	rm -f $(NAME)

re: clean all


.Phony:clean