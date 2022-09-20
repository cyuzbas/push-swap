# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: cyuzbas <cyuzbas@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2022/08/30 16:44:44 by cyuzbas       #+#    #+#                  #
#    Updated: 2022/09/20 17:11:41 by cyuzbas       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

GREEN	= \033[38;5;2m
NORMAL	= \033[38;5;255m
RED		= \033[38;5;1m
BLUE	= \033[38;5;4m
YELLOW	= \033[1;33m

NAME	=	push_swap

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -g -fsanitize=address

SRCS	=	push_swap.c\
			check_input.c\
			push.c \
			swap.c \
			rotate.c\
			reverse_rotate.c\
			parse.c\
			order.c\
			calculate.c\
			sort.c\
			utils.c\

HEADER	=	push_swap.h

OBJ_DIR	=	obj

OBJS	=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

LIBFT_DIR = libft

LIBFT = libft.a

all:	$(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $@

$(NAME):	$(OBJS)
	@make -C $(LIBFT_DIR) > /dev/null
	$(CC) $(CFLAGS) $^ -o $@ $(LIBFT_DIR)/$(LIBFT)
	@echo "$(GREEN) Created push_swap executable.$(NORMAL)"

$(OBJS): $(OBJ_DIR)/%.o : %.c $(HEADER)
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rdf $(OBJ_DIR)		
	@$(MAKE) -C $(LIBFT_DIR) clean > /dev/null
	@echo "$(RED) Deleted all object files.$(NORMAL)"

fclean:		clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean  > /dev/null
	@echo "$(RED) Deleted all executables.$(NORMAL)"

re:			fclean all

.PHONY: all clean fclean re 