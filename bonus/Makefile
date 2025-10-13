# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 15:15:47 by klima-do          #+#    #+#              #
#    Updated: 2025/10/13 16:42:32 by klima-do         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----------------------------- CONFIGURAÇÕES -------------------------------- #
NAME = ../checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I../srcs -I../Libft

# ----------------------------- DIRETÓRIOS ---------------------------------- #
LIBFT = ../Libft/libft.a

# ----------------------------- ARQUIVOS ------------------------------------ #
SRC_FILES = \
	push.c \
	swap.c \
	rotate.c \
	reverse_rotate.c \
	checker_results.c \
	checker.c \
	run_cust_sort_bonus.c \
	main.c \
	is_order.c\
	validators.c\
	check_args.c
OBJS = $(SRC_FILES:.c=.o)

# ----------------------------- REGRAS PRINCIPAIS ---------------------------- #
all: $(NAME)

$(LIBFT):
	@echo "📚 Compilando Libft..."
	@$(MAKE) -s -C ../Libft

$(NAME): $(LIBFT) $(OBJS)
	@echo "🔗 Linkando $(NAME)..."
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "✅ Checker compilado!"

# ----------------------------- LIMPEZA -------------------------------------- #
clean:
	@echo "🧹 Limpando objetos..."
	@rm -f $(OBJS)
	@$(MAKE) -s -C ../Libft clean

fclean: clean
	@echo "🧼 Limpando binários..."
	@rm -f $(NAME)
	@$(MAKE) -s -C ../Libft fclean

re: fclean all

.PHONY: all clean fclean re
