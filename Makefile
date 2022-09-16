# Colors
GREEN	= \033[38;5;2m
NORMAL	= \033[38;5;255m
RED		= \033[38;5;1m
BLUE	= \033[38;5;4m
YELLOW	= \033[1;33m

# Compiler settings
NAME	= push_swap
CC		= gcc
FLAGS	= -Wall -Wextra -Werror

# Source, tests, header and object files
SRC_FILES		=	check_input.c\
					push.c\
					swap.c\
					push_swap.c\
					calculate.c\
					rotate.c\
					reverse_rotate.c\
					parse.c\
					order.c\
					sort.c\
					utils.c
HEADER_FILES	=  push_swap.h
OBJ_DIR			= obj
OBJ				= $(SRC_FILES:%.c=$(OBJ_DIR)/%.o)

#Libft
LIBFT_DIR = libft

LIBFT = libft.a

# Build release
all: $(OBJ_DIR) $(LIBFT) $(NAME) 

$(LIBFT):
	@make -C $(LIBFT_DIR) bonus > /dev/null
# Build normal
$(OBJ_DIR):
	@mkdir -p $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $^ -o $@ $(LIBFT_DIR)/$(LIBFT)
	@echo "$(GREEN) Created push_swap executable.$(NORMAL)"

$(OBJ): $(OBJ_DIR)/%.o : %.c $(HEADER_FILES)
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rdf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean > /dev/null
	@echo "$(RED) Deleted all object files.$(NORMAL)"
	
fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) clean > /dev/null
	@echo "$(RED) Deleted all executables.$(NORMAL)"
re: clean fclean all
.PHONY: clean fclean re