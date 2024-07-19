NAME			=	fractal
LIBFT_DIR		=	srcs/libft

SRCS			=	srcs/display.c \
					srcs/events.c \
					srcs/init.c \
					srcs/math_util.c \
					srcs/render.c \
					srcs/mandel.c \
					srcs/main.c

LIBFT			=	$(LIBFT_DIR)/libft.a
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
LDFLAGS			=	-Imlx -lmlx -framework OpenGL -framework AppKit
OBJS			=	$(SRCS:%.c=%.o)

$(LIBFT):
		$(MAKE) -C $(LIBFT_DIR)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(LDFLAGS)

all:	$(NAME)

clean:
		rm -f $(OBJS)
		$(MAKE) -C $(LIBFT_DIR) clean

fclean:	clean
		rm -f $(NAME)
		$(MAKE) -C $(LIBFT_DIR) fclean

re:		fclean all

.PHONY: all clean fclean re