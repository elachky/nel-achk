NAME := push_swap

INCLUDE = -I./headers/ -I./utils/ -I./stack/
CC = gcc
LIBS = -L./utils/ -lutils -L./stack/ -lstack
CC = gcc
FLAG = -Wall -Werror -Wextra
HDR = headers/push_swap.h

SRC	:=	main.c \
		src/check_args.c src/tokenize.c src/set_on_stack.c\

OBJ := $(SRC:.c=.o)

%.o : %.c
	$(CC) -g $(FLAG) $(INCLUDE) -c $< -o $@

$(NAME) : $(OBJ) $(HDR)
	make -C ./utils/
	make -C ./stack
	$(CC) $(FLAG) $(INCLUDE) $(OBJ) $(LIBS) -o $(NAME)

all : $(NAME)

clean:
	make clean -C ./utils
	make clean -C ./stack
	rm -rf $(OBJ)

fclean: clean
	make fclean -C ./utils
	make fclean -C ./stack
	rm -rf $(NAME)

re: fclean all