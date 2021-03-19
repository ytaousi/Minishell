NAME = minishell

libft = libft/libft.a

SRCS = utils.c minishell.c environements.c builtins.c $(libft)

OBJECTS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(libft) $(SRC)
	@gcc -Wall -Werror -Wextra $(SRCS) -o $(NAME) -fsanitize=address
$(libft) :
	@make -C libft/
	@make clean -C libft/

clean:
	@rm -rf $(OBJECTS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
	@make re -C libft/
.phony : all clean fclean re
