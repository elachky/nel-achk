CLIENT := client
SERVER := server

INCLUDE = -I./includes -I./src/libft/
CC = gcc
LIBFT = src/libft/libft.a
FLAG = -Wall -Werror -Wextra
HDR = includes/
LIBFT_PATH = src/libft/

SRC	:=	 src/encode.c src/decode.c
OBJ := $(SRC:.c=.o)

%.o : %.c $(HDR)
	$(CC) $(FLAG) $(INCLUDE) -c $< -o $@

all : ${LIBFT} ${SERVER} $(CLIENT)

$(SERVER) : $(SRC) ${LIBFT} ${HDR} ${OBJ}
	make -C ${LIBFT_PATH}
	$(CC) $(FLAG) $(INCLUDE) server.o $(SRC) $(LIBFT) -o $(SERVER)

$(CLIENT) : $(SRC) $(LIBFT) ${HDR}
	$(CC) $(FLAG) $(INCLUDE) client.o $(SRC) $(LIBFT) -o $(CLIENT)

${LIBFT} : 
	make -C ${LIBFT_PATH}

clean:
	make clean -C ${LIBFT_PATH}
	rm -rf $(OBJ) client.o server.o

fclean: clean
	make fclean -C ${LIBFT_PATH}
	rm -rf $(SERVER) $(CLIENT)

re: fclean all # to review