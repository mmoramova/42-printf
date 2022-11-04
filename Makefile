# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/29 11:44:50 by mmoramov          #+#    #+#              #
#    Updated: 2022/11/04 17:34:04 by mmoramov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a
HEADER = ft_printf.h
C_FLAGS = -Wall -Wextra -Werror
RM = rm -f

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

SRC_FILES = ft_printf

SRC = $(addsuffix .c, $(SRC_FILES))
OBJ = $(SRC:.c=.o)
INCLUDE = -I ./

all: $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(C_FLAGS) $(INCLUDE) -c $< -o $@

$(NAME):: $(OBJ) $(HEADER)
	ar -rcs $(NAME) $(OBJ)
	@echo "$(BLUE)Everything has been compilated.$(BLACK)"

$(NAME)::
	@echo "$(BLUE)No actions needed.$(BLACK)"

.PHONY: all clean fclean re

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	@echo "$(MAGENTA)Everything has been cleaned.$(BLACK)"
	
re: fclean all

