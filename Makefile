CLIENT 				=	client
SERVER				=	server

INCLUDES			=	-I includes -I $(LIBFT_DIR)/includes/

LIBFT				=	$(LIBFT_DIR)libft.a
LIBFT_DIR			=	libft
LIB_FLAGS			=	-L $(LIBFT_DIR) -lft

CC					=	gcc
CFLAGS				=	-Wall -Wextra -Werror
RM					=	/bin/rm -f
NORM				=	norminette

DIR_SRCS			=	srcs
DIR_OBJS			=	objs
CLIENT_SUBDIRS		=	client
SERVER_SUBDIRS		=	server

CLIENT_SRCS_PATHS	=	$(foreach dir, $(CLIENT_SUBDIRS), $(addprefix $(DIR_SRCS)/, $(dir)))
CLIENT_OBJS_PATHS	=	$(foreach dir, $(CLIENT_SUBDIRS), $(addprefix $(DIR_OBJS)/, $(dir)))
CLIENT_SRCS			=	$(foreach dir, $(CLIENT_SRCS_PATHS), $(wildcard $(dir)/*.c))
CLIENT_OBJS			=	$(subst $(DIR_SRCS), $(DIR_OBJS), $(CLIENT_SRCS:.c=.o))

SERVER_SRCS_PATHS	=	$(foreach dir, $(SERVER_SUBDIRS), $(addprefix $(DIR_SRCS)/, $(dir)))
SERVER_OBJS_PATHS	=	$(foreach dir, $(SERVER_SUBDIRS), $(addprefix $(DIR_OBJS)/, $(dir)))
SERVER_SRCS			=	$(foreach dir, $(SERVER_SRCS_PATHS), $(wildcard $(dir)/*.c))
SERVER_OBJS			=	$(subst $(DIR_SRCS), $(DIR_OBJS), $(SERVER_SRCS:.c=.o))

$(DIR_OBJS)/%.o :	$(DIR_SRCS)/%.c
					mkdir -p $(DIR_OBJS) $(CLIENT_OBJS_PATHS) $(SERVER_OBJS_PATHS)
					$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all:				$(CLIENT) $(SERVER)

$(LIBFT):
					make -C $(LIBFT_DIR)

$(CLIENT):			$(CLIENT_OBJS) $(LIBFT)
					$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJS) $(LIB_FLAGS)
$(SERVER):			$(SERVER_OBJS) $(LIBFT)
					$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJS) $(LIB_FLAGS)

clean:
					make clean -C $(LIBFT_DIR)
					$(RM) $(CLIENT_OBJS) $(CLIENT_OBJS)
					$(RM) -r $(DIR_OBJS)

fclean:				clean
					make fclean -C $(LIBFT_DIR)
					$(RM) $(SERVER) $(CLIENT)

re:					fclean all

norm:
					$(NORM) */*.h */*/*.c

.PHONY:				all clean fclean re norm