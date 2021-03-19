# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytaousi <ytaousi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/10 21:31:31 by ytaousi           #+#    #+#              #
#    Updated: 2019/10/22 14:47:49 by ytaousi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = get_next_line.c ft_bzero.c ft_memset.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c ft_isprint.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_tolower.c ft_toupper.c ft_strlen.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c \
		ft_calloc.c ft_strdup.c ft_atoi.c ft_itoa.c ft_strncmp.c ft_strfree.c \
		ft_strlcpy.c ft_strlcat.c ft_substr.c ft_strjoin.c ft_split.c \
		ft_strnstr.c ft_strchr.c ft_strrchr.c ft_strtrim.c ft_strmapi.c ft_strlast.c \

SRCS_BONUS = ft_putlst_endl_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstadd_front_bonus.c \
			  ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstlast_bonus.c \
			  ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \

CFLAGS = -Wall -Werror -Wextra

OBJECTS = $(SRCS:.c=.o)

OBJECTS_BONUS = $(SRCS_BONUS:.c=.o)

all : $(NAME) 

$(NAME) : $(OBJECTS)
	ar -rc $(NAME) $(OBJECTS) && ranlib $(NAME)
$(OBJECTS) :
	gcc $(CFLAGS) -c $(SRCS)
bonus : $(OBJECTS_BONUS)
	ar -rc $(NAME) $(OBJECTS_BONUS) && ranlib $(NAME)
$(OBJECTS_BONUS) :
	gcc $(CFLAGS) -c $(SRCS_BONUS)
clean :
	rm -f $(OBJECTS) $(OBJECTS_BONUS)
fclean : clean
	rm -f $(NAME)
re : fclean all

.PHONY : clean fclean re all bonus
