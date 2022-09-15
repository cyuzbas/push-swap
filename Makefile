# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: cyuzbas <cyuzbas@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2022/08/30 16:44:44 by cyuzbas       #+#    #+#                  #
#    Updated: 2022/09/14 16:25:33 by cicekyuzbas   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror 
# -g -fsanitize=address

SRCS	=	push_swap.c check_input.c\
			push.c swap.c calculate.c \
			rotate.c reverse_rotate.c\
			parse.c order.c sort.c\
			utils.c

HEADER	=	push_swap.h

OBJS	=	$(SRCS:.c=.o)

LIBFT_DIR = libft

LIBFT = libft.a

all:		$(NAME)

$(NAME):	$(OBJS)
	$(MAKE) bonus -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_DIR)/$(LIBFT)

%.o: %.c  $(HEADER)
	$(CC) -c $< -o $(<:.c=.o)

clean:		
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean:		clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re:			fclean all

.PHONY: all clean fclean re 