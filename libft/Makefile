# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: cyuzbas <cyuzbas@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2021/10/11 12:51:21 by cyuzbas       #+#    #+#                  #
#    Updated: 2022/09/20 17:10:49 by cyuzbas       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME    	= 	libft.a
CC			= 	gcc
CFLAGS		= 	-Wall -Wextra -Werror

SRCS    	=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
				ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
				ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
				ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
				ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
				ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
				ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
				ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
				ft_strcmp.c ft_tolower.c ft_toupper.c ft_abs.c\
				ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
				ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
				ft_lstmap.c ft_lstnew.c ft_lstsize.c

HEADER		=	libft.h

OBJ_DIR		=	obj

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(OBJ_DIR) ${NAME}

$(OBJ_DIR):
	@mkdir -p $@

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}

$(OBJS): $(OBJ_DIR)/%.o : %.c $(HEADER)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -rdf $(OBJ_DIR)
	rm -f $(SRCS:.c=.o)

fclean: clean
	@rm -rdf $(OBJ_DIR)
	rm -f ${NAME}
	
re: fclean all

.PHONY: all clean fclean re 