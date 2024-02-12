NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
ARC = ar rc
RM = rm -f
SRCS = printstrings.c print_ndigits.c ft_printf.c print_hexadecimal.c
OBJS = $(SRCS:%.c=%.o)

all : $(NAME)

%.o : %.c libftprintf.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(ARC) $(NAME) $(OBJS)
	
clean :
	$(RM) $(OBJS)

fclean : clean 
	$(RM) $(NAME)

re : fclean all

.PHONY: clean