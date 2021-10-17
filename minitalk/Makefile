CLIENT := client
SERVER := server

INCLUDE = -I./ -I./libft
CC = gcc
LIBS = -L./libft -libft
CC = gcc
FLAG = -Wall -Werror -Wextra
HDR = minitalk.h

SRC	:=	client.c server.c

OBJ := $(SRC:.c=.o)

%.o : %.c $(HDR)
	$(CC) -g $(FLAG) $(INCLUDE) -c $< -o $@

$(SERVER) : $(OBJ) $(HDR)
	make -C ./libft
	$(CC) $(FLAG) $(INCLUDE) $(OBJ) $(LIBS) -o $(SERVER)

$(CLIENT) : $(OBJ) $(HDR)
	$(CC) $(FLAG) $(INCLUDE) $(OBJ) $(LIBS) -o $(CLIENT)

all : ${CLIENT} ${SERVER}

clean:
	make clean -C ./libft
	rm -rf $(OBJ)

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)

re: fclean all