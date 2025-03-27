NAME            =       fractol

GREEN           =       \033[0;32m
CYAN            =       \033[0;36m
YELLOW          =       \033[1;33m
MAGENTA         =       \033[0;35m
BOLD            =       \033[1m
RESET           =       \033[0m

LIBFT_DIR       =       srcs/libft
MLX_DIR         =       srcs/mlx

SRCS            =       srcs/events.c \
			srcs/init.c \
			srcs/math_util.c \
			srcs/render.c \
			srcs/fractal.c \
			srcs/util.c \
			srcs/main.c \

LIBFT           =       $(LIBFT_DIR)/libft.a
MLX             =       $(MLX_DIR)/libmlx.a
CC              =       cc
CFLAGS          =       -Wall -Wextra -Werror -I$(MLX_DIR)
LDFLAGS         =       -L$(MLX_DIR) -lmlx -L/usr/X11R6/lib -lXext -lX11 -lm -lz
OBJS            =       $(SRCS:%.c=%.o)

TOTAL_FILES     = $(words $(SRCS))
COMPILED        = 0

define update_progress
	@$(eval COMPILED=$(shell echo $$(($(COMPILED)+1))))
	@printf "\r$(YELLOW)Compiling [%-20s] %d%% (%d/%d)$(RESET)" \
		"$$(printf '█%.0s' $$(seq 1 $$(($(COMPILED)*20/$(TOTAL_FILES)))))" \
		$$(($(COMPILED)*100/$(TOTAL_FILES))) \
		$(COMPILED) \
		$(TOTAL_FILES)
endef

all: $(MLX) $(LIBFT) $(NAME)

$(MLX):
	@echo "$(CYAN)$(BOLD)Cloning and building mlx...$(RESET)"
	@git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR) || true
	@$(MAKE) -C $(MLX_DIR)

$(LIBFT):
	@echo "$(CYAN)$(BOLD)Building libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	$(call update_progress)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@echo "\n$(GREEN)$(BOLD)Linking $@...$(RESET)"
	@$(CC) $(CFLAGS) $(IFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(LDFLAGS)
	@echo "$(MAGENTA)$(BOLD)"
	@echo "    ____                __        __"
	@echo "   / __/________ ______/ /_____ _/ /"
	@echo "  / /_/ ___/ __ \`/ ___/ __/ __ \`/ / "
	@echo " / __/ /  / /_/ / /__/ /_/ /_/ / /  "
	@echo "/_/ /_/   \__,_/\___/\__/\__,_/_/   "
	@echo "$(RESET)"
	@echo "$(GREEN)$(BOLD)Build complete! ✨$(RESET)"

clean:
	@echo "$(CYAN)Cleaning up...$(RESET)"
	@sleep 1
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean
	@echo "$(GREEN)Clean complete! 🧹$(RESET)"

fclean: clean
	@echo "$(CYAN)Removing executable and cleaning libraries...$(RESET)"
	@sleep 1
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -rf $(MLX_DIR)
	@echo "$(GREEN)Full clean complete! 🧼$(RESET)"

re: fclean all

.PHONY: all clean fclean re
