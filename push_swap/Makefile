NAME := push_swap




INCLUDE = -I./headers/ -I./utils/
CC = gcc
LIBS = -L./utils/ -lutils
CC = gcc
# FLAG = -Wall -Werror -Wextra
HDR = headers/push_swap.h

SRC	:=	main.c \
		src/check_args.c src/tokenize.c \

OBJ := $(SRC:.c=.o)

%.o : %.c
	$(CC) -g $(FLAG) $(INCLUDE) -c $< -o $@

$(NAME) : $(OBJ) $(HDR)
	make -C ./utils/
	$(CC) $(FLAG) $(INCLUDE) $(OBJ) $(LIBS) -o $(NAME)

all : $(NAME)

clean:
	make clean -C ./utils
	rm -rf $(OBJ)

fclean: clean
	make fclean -C ./utils
	rm -rf $(NAME)

re: fclean all