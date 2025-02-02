# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldurmish <ldurmish@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 20:52:11 by ledio             #+#    #+#              #
#    Updated: 2025/01/20 22:22:36 by ldurmish         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

# Compiler settings
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I includes -I libft/includes
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Color codes
RESET = \033[0m
RED = \033[0;31m
GREEN = \033[0;32m

# Source files for push_swap
SRCS = src/check_cheapest_moves.c src/check_max_and_min_in_a.c \
       src/check_max_and_min_in_b.c src/doubly_ll.c src/errors.c \
       src/find_cheapest_move.c src/new_elements_stack_b.c \
       src/new_min_max_in_a.c src/new_num_in_stack_a.c src/push_to_a.c \
       src/push.c src/reverse_rotate.c src/rotate.c src/sort.c \
       src/sorting_algorithm.c src/swap.c src/utils.c src/push_swap.c


BONUS_SRCS = bonus/checker_bonus.c bonus/checker_verbose_bonus.c bonus/clear_all_bonus.c bonus/doubly.ll_bonus.c \
			bonus/errors_bonus.c bonus/push_bonus.c bonus/reverse_rotate_bonus.c \
			bonus/rotate_bonus.c bonus/swap_bonus.c bonus/utils_bonus.c \

# Object files
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# Main target
all: $(LIBFT) $(NAME)

# Compile libft
$(LIBFT):
	@echo "$(GREEN)Compiling libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)

# Compile push_swap
$(NAME): $(OBJS)
	@echo "$(GREEN)Compiling push_swap...$(RESET)"
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "$(GREEN)push_swap compiled successfully!$(RESET)"

# Compile bonus
bonus: $(LIBFT) $(BONUS_OBJS)
		@echo "$(GREEN)Compiling checker ...$(RESET)"
		$(CC) $(CFLAGS) $(INCLUDES) $(BONUS_OBJS) -L$(LIBFT_DIR) -lft -o $(BONUS_NAME);
		@echo "$(GREEN)checker compiled successfully$(RESET)"

# Compile individual object files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean object files
clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -f $(OBJS) $(BONUS_OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(GREEN)Object files removed successfully...!$(RESET)"

# Remove executables and object files
fclean: clean
	@echo "$(RED)Removing executables...$(RESET)"
	@rm -f $(NAME) $(BONUS_NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)Executables removed successfully...!$(RESET)"

# Rebuild everything
re: fclean all

leaks: re
	valgrind --leak-check=full ./push_swap

.PHONY: all bonus clean fclean re