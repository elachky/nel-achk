NAME := libstack.a

CC := gcc

FLAG = -Wall -Werror -Wextra

HEADERS := ft_stack.h

SRC :=	ft_stack_push.c  ft_stack_destroy.c  ft_stack_rotate.c \
		ft_stack_swap.c ft_stack_revrotate.c ft_stack_pushto.c \
		ft_stack_len.c ft_stack_min.c ft_stack_max.c ft_stack_check_sorted.c \
		ft_stack_value_at.c
		

OBJ := $(SRC:.c=.o)

%.o : %.c $(HEADERS)
	$(CC) -g $(FLAG) -c $< -o $@

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

all : $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all