# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/19 16:27:07 by klima-do          #+#    #+#              #
#    Updated: 2025/10/02 16:28:01 by klima-do         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC_DIR = srcs
UTIL_DIR = utils

SRC_FILES = push.c\
			swap.c\
			rotate.c\
			reverse_rotate.c\
			check_args.c\
			buble_sort.c\
			radix_sort.c\
			sort_small.c\
			stack_to_array.c\
			$(UTIL_DIR)/print_stack.c\
			$(UTIL_DIR)/validators.c\
			$(UTIL_DIR)/is_order.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES)) main.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I. -I$(LIBFT_DIR)

all: $(NAME)

$(LIBFT):
	@echo "📚 Compilando Libft..."
	@$(MAKE) -s -C $(LIBFT_DIR)

%.o: %.c
	@echo "⚙️  Compilando $<..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	@echo "🔗 Linkando $(NAME)..."
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	@echo "🧹 Limpando objetos..."
	@rm -f $(OBJS)
	@$(MAKE) -s -C $(LIBFT_DIR) clean

fclean: clean
	@echo "🧹 Limpando binário..."
	@rm -f $(NAME)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
re: fclean all
	@$(MAKE) -s -C $(LIBFT_DIR) re
.PHONY: all clean fclean re