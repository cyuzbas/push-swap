# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: cyuzbas <cyuzbas@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2022/08/30 16:44:44 by cyuzbas       #+#    #+#                  #
#    Updated: 2022/08/30 16:47:58 by cyuzbas       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -g -fsanitize=address

SRCS	=	push_swap.c \
			utils.c

HEADER	=	push_swap.h

OBJS	=	$(SRCS:.c=.o)

LIBFT_DIR = libft

LIBFT = libft.a

all:		$(NAME)

$(NAME):	$(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_DIR)/$(LIBFT)

%.o: %.c  $(HEADER)
	$(CC) -c $< -o $(<:.c=.o)

# bonus:
# 	$(MAKE) WITH_BONUS=1 all

clean:		
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean:		clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re:			fclean all

.PHONY: all clean fclean re bonus