# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/29 11:44:50 by mmoramov          #+#    #+#              #
#    Updated: 2022/11/05 17:15:20 by mmoramov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a
HEADER = ft_printf.h
C_FLAGS = -Wall -Wextra -Werror -MMD
RM = rm -f
SRC_LIBFT = libft/libft.a 
MAKE_LIBFT = make -C libft

# Colors
BLACK = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

SRC_FILES = ft_printf ft_vprintf ft_putchar ft_putnbr ft_putnbrbase	*ft_choosebase ft_putstr ft_putptr

SRC = $(addsuffix .c, $(SRC_FILES))
OBJ = $(SRC:.c=.o)
DEP = $(SRC:.c=.d)

all: make_libs $(NAME)

make_libs: 
	@$(MAKE_LIBFT)

-include ${DEP}

%.o: %.c
	$(CC) $(C_FLAGS) -c $< -o $@

$(NAME):: $(OBJ) ./$(SRC_LIBFT)
	cp $(SRC_LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJ)
	@echo "$(BLUE)Everything has been compilated.$(BLACK)"

$(NAME)::
	@echo "$(BLUE)No actions needed.$(BLACK)"

.PHONY: all clean fclean re

clean:
	$(RM) $(OBJ) $(DEP)
	$(MAKE_LIBFT) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE_LIBFT) fclean
	@echo "$(MAGENTA)Everything has been cleaned.$(BLACK)"
	
re: fclean all

