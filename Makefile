NAME		=	fractol

GREEN		=	\033[0;32m
CYAN		=	\033[0;36m
YELLOW		=	\033[1;33m
MAGENTA		=	\033[0;35m
BOLD		=	\033[1m
RESET		=	\033[0m	

LIBFT_DIR	=	srcs/libft
MINILIB_DIR =	minilibx-linux

SRCS		=	srcs/events.c \
				srcs/init.c \
				srcs/math_util.c \
				srcs/render.c \
				srcs/fractal.c \
				srcs/util.c \
				srcs/main.c 

LIBFT		=	$(LIBFT_DIR)/libft.a
MINILIB		=	$(MINILIB_DIR)/libmlx.a

CC			=	cc
CFLAGS		=	-O3 -Wall -Wextra -Werror -g -fsanitize=address
LDFLAGS 	=	-L$(MINILIB_DIR) -lmlx -lX11 -lXext -lm
OBJS		=	$(SRCS:%.c=%.o)

TOTAL_FILES	= $(words $(SRCS))
COMPILED	= 0

define update_progress
	@$(eval COMPILED=$(shell echo $$(($(COMPILED)+1))))
	@printf "\r$(YELLOW)Compiling [%-20s] %d%% (%d/%d)$(RESET)" \
		"$$(printf '█%.0s' $$(seq 1 $$(($(COMPILED)*20/$(TOTAL_FILES)))))" \
		$$(($(COMPILED)*100/$(TOTAL_FILES))) \
		$(COMPILED) \
		$(TOTAL_FILES)
endef

$(NAME): $(OBJS) $(LIBFT) $(MINILIB)
	@echo "\n$(GREEN)$(BOLD)Linking $@...$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MINILIB) $(LDFLAGS)
	@echo "$(MAGENTA)$(BOLD)"
	@echo "    ____                __        __"
	@echo "   / __/________ ______/ /_____ _/ /"
	@echo "  / /_/ ___/ __ \`/ ___/ __/ __ \`/ / "
	@echo " / __/ /  / /_/ / /__/ /_/ /_/ / /  "
	@echo "/_/ /_/   \__,_/\___/\__/\__,_/_/   "
	@echo "$(RESET)"
	@echo "$(GREEN)$(BOLD)Build complete! ✨$(RESET)"

$(LIBFT):
	@echo "$(CYAN)$(BOLD)\nBuilding libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)

$(MINILIB):
	@echo "$(CYAN)$(BOLD)\nBuilding minilibx...$(RESET)"
	@$(MAKE) -C $(MINILIB_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	$(call update_progress)

all: $(NAME)

clean:
	@echo "$(CYAN)Cleaning up...$(RESET)"
	@sleep 0.5
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(GREEN)Clean complete! 🧹$(RESET)"

fclean: clean
	@echo "$(CYAN)Removing executable and cleaning libft...$(RESET)"
	@sleep 0.5
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)Full clean complete! 🧼$(RESET)"

re: fclean all

.PHONY: all clean fclean re
