NAME := pushswap

CC := gcc

INCLUDE := headers

SRC :=	main.c \
		src/check_args.c src/tokenize.c \

OBJ := $(SRC:.c=.o)

%.o : %.c
	$(CC) -g $(FLAG) -I $(INCLUDE) -c $< -o $@

$(NAME) : $(OBJ) $(HEADERS)
	$(CC) -g $(FLAG) -I $(INCLUDE) $(OBJ) $(LIBS) -o $(NAME)

all : $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re