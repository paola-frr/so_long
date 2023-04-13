NAME			= so_long

SRCS 			= 	./main.c \
					./get_map.c \
					./create_window.c \
					./check_input.c \
					./move.c \
					./check_input_utils.c

GNL				=	./get_next_line/get_next_line.c \
					./get_next_line/get_next_line_utils.c

LIBFT			=	libft.a

OBJS			=	${SRCS:.c=.o}

OBJS_GNL		=	${GNL:.c=.o}

CFLAGS = -Wall -Werror -Wextra -g3

CC = cc

LIBRARIES		=	-Llibft -lft -Lmlx -lmlx -lXext -lX11 -lm

INCLUDES		=	-I. -Ilibft -Imlx

all				:	${NAME}

$(NAME): $(OBJS) ${OBJS_GNL}
	@make -C libft
	${CC} ${CFLAGS} $(OBJS) $(INCLUDES) ${OBJS_GNL} ${LIBRARIES} -o $(NAME)

clean			:
					make clean -C libft
					rm -rf ${OBJS} ${OBJS_GNL} ${OBJS_BONUS}

fclean			:	clean
					make fclean -C libft
					rm -rf ${LIBFT}
					rm -rf ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re bonus