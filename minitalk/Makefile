CLIENT := client
SERVER := server

INCLUDE = -I./includes -I./src/libft/
CC = gcc
LIBFT = src/libft/libft.a
FLAG = -Wall -Werror -Wextra
HDR = includes/
LIBFT_PATH = src/libft/

CSRC	:=	 src/encode.c client.c
COBJ := $(CSRC:.c=.o)
SSRC	:=	 src/decode.c server.c
SOBJ := $(SSRC:.c=.o)

%.o : %.c $(HDR)
	$(CC) $(FLAG) $(INCLUDE) -c $< -o $@

all : ${LIBFT} ${SERVER} $(CLIENT)

$(SERVER) : $(SRC) ${HDR} ${SOBJ}
	$(CC) $(FLAG) $(INCLUDE) $(SOBJ) $(LIBFT) -o $(SERVER)

$(CLIENT) : $(SRC) ${HDR} ${COBJ}
	$(CC) $(FLAG) $(INCLUDE) $(COBJ) $(LIBFT) -o $(CLIENT)

${LIBFT} : 
	make -C ${LIBFT_PATH}

clean:
	make clean -C ${LIBFT_PATH}
	rm -rf $(COBJ) $(SOBJ)

fclean: clean
	make fclean -C ${LIBFT_PATH}
	rm -rf $(SERVER) $(CLIENT)

re: fclean all # to review