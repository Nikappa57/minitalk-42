# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgaudino <lgaudino@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 14:48:21 by lgaudino          #+#    #+#              #
#    Updated: 2023/03/22 15:09:56 by lgaudino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server

SRCS = ft_client.c ft_server.c ft_utils.c

OBJ = $(SRCS:%.c=%.o)

SERVEROBJ = ft_server.o ft_utils.o
CLIENTOBJ = ft_client.o ft_utils.o

CC = gcc

RM = rm -rf

all: $(CLIENT) $(SERVER)

$(CLIENT): $(OBJ)
			$(CC) $(CFLAGS) $(CLIENTOBJ) -o $(CLIENT)

$(SERVER): $(OBJ)
			$(CC) $(CFLAGS) $(SERVEROBJ) -o $(SERVER)

$(OBJ): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(CLIENT) $(SERVER)

re:			fclean all

.PHONY: all clean fclean re