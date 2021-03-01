# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: gbouwen <gbouwen@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/07/29 09:29:26 by gbouwen       #+#    #+#                  #
#    Updated: 2021/02/26 14:38:12 by gbouwen       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = philo_one
CC = gcc
FLAGS = -Wall -Wextra -Werror
SOURCE_C =	main.c \
			helper/ft_atoi.c \
			helper/init_struct.c \
			validate_arguments/validate_all_arguments.c \
			validate_arguments/incorrect_amount_of_arguments.c \
			validate_arguments/validate_single_argument.c \
			execution/execution_loop.c

OBJECT_FILES = $(SOURCE_C:.c=.o)

GREEN = \033[0;38;5;114m
RED = \033[38;5;124m
BLUE = \033[38;5;153m
NORMAL = \033[38;5;255m

all: $(NAME)

%.o: %.c
	@echo "$(GREEN)Created object file:$(NORMAL)	$@"
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJECT_FILES)
	@echo "-----------------------------------"
	@echo "$(BLUE)Created executable:$(NORMAL)	$(NAME)"
	@echo "-----------------------------------"
	@$(CC) $(FLAGS) $(OBJECT_FILES) $(LIBRARIES) -o $(NAME)

clean:
	@echo "$(RED)Removed all .o files$(NORMAL)"
	@echo "-----------------------------------"
	@/bin/rm -f $(OBJECT_FILES)

fclean: clean
	@echo "$(RED)Removed executable:$(NORMAL)	$(NAME)"
	@echo "-----------------------------------"
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
