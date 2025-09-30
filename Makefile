# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/19 16:27:07 by klima-do          #+#    #+#              #
#    Updated: 2025/09/19 17:21:50 by klima-do         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC_DIR = srcs
SRC_FILES =

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

fclean: clean
	@echo "🧹 Limpando binário..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re