# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 19:27:46 by mmoramov          #+#    #+#              #
#    Updated: 2022/11/05 14:33:37 by mmoramov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = libft.h
C_FLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC_FILES = ft_isalpha   ft_toupper    ft_isdigit    ft_tolower \
			ft_isalnum   ft_strchr     ft_isascii    ft_strrchr \
			ft_isprint   ft_strncmp    ft_strlen     ft_memchr  \
			ft_memset    ft_memcmp     ft_bzero      ft_strnstr \
			ft_memcpy    ft_atoi       ft_memmove    ft_calloc  \
			ft_strlcpy   ft_strdup     ft_strlcat    ft_substr  \
			ft_strjoin   ft_strtrim    ft_split      ft_itoa    \
			ft_strmapi   ft_striteri   ft_putchar_fd            \
			ft_putstr_fd ft_putendl_fd ft_putnbr_fd	\
			ft_lstnew ft_lstadd_front ft_lstsize   \
			ft_lstlast ft_lstadd_back ft_lstdelone \
			ft_lstclear ft_lstiter ft_lstmap

SRC = $(addsuffix .c, $(SRC_FILES))
OBJ = $(SRC:.c=.o)

INCLUDE = -I ./

all: $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(C_FLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJ) $(HEADER)
	ar -rcs $(NAME) $(OBJ)

.PHONY: all clean fclean re

clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
	
re: fclean all

