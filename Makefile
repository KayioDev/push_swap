# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/19 16:27:07 by klima-do          #+#    #+#              #
#    Updated: 2025/10/13 16:24:18 by klima-do         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----------------------------- CONFIGURAÇÕES -------------------------------- #

NAME		= push_swap
BONUS_NAME	= checker
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I. -I$(LIBFT_DIR)

# ----------------------------- DIRETÓRIOS ---------------------------------- #

SRC_DIR		= srcs
UTIL_DIR	= $(SRC_DIR)/utils
LIBFT_DIR	= Libft
LIBFT		= $(LIBFT_DIR)/libft.a
BONUS_DIR	= bonus

# ----------------------------- ARQUIVOS ------------------------------------ #

SRC_FILES = \
	push.c \
	swap.c \
	rotate.c \
	reverse_rotate.c \
	check_args.c \
	buble_sort.c \
	radix_sort.c \
	sort_small.c \
	stack_to_array.c \
	find_utils.c \
	position_utils.c \
	cost_utils.c \
	move_utils.c \
	sort_chunks.c \
	utils/print_stack.c \
	utils/validators.c \
	utils/is_order.c \
	run_radix.c \
	run_cust_sort.c \
	main.c

OBJS = $(addprefix $(SRC_DIR)/, $(SRC_FILES:.c=.o))

# ----------------------------- REGRAS PRINCIPAIS ---------------------------- #

all: $(NAME)

bonus:
	@echo "📚 Compilando Checker..."
	@$(MAKE) -s -C $(BONUS_DIR)
	@echo "✅ Checker compilado!"

$(LIBFT):
	@echo "📚 Compilando Libft..."
	@$(MAKE) -s -C $(LIBFT_DIR)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "⚙️  Compilando $<..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	@echo "🔗 Linkando $(NAME)..."
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "✅ push_swap compilado!"

# ----------------------------- LIMPEZA -------------------------------------- #

clean:
	@echo "🧹 Limpando objetos..."
	@rm -f $(OBJS)
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@$(MAKE) -s -C $(BONUS_DIR) clean

fclean: clean
	@echo "🧼 Limpando binários..."
	@rm -f $(NAME)
	@rm -f $(BONUS_DIR)/$(BONUS_NAME)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@$(MAKE) -s -C $(BONUS_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
