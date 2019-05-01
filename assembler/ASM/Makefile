#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amartyne <amartyne@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/21 17:20:34 by amartyne          #+#    #+#              #
#    Updated: 2019/04/21 17:20:35 by amartyne         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =  asm

FLAGS = -Wall -Werror -Wextra

ASM_FILES = ./src/main.c ./src/read_file.c

INCLUDES = -I ./includes

LIBFT_LIB = ./../libft/libft.a

OUT = $(ASM_FILES:.c=.o)

all: $(NAME)

%.o:%.c $(INCLUDES)
	gcc $(FLAGS) -o $@ $<

./libft/libft.a:
	make -C ../../libft

$(NAME): $(OUT) ./libft/libft.a
	gcc -o $(NAME) $(FLAGS) -L ../../libft -lft -lm  $(ASM_FILES)
	@echo "\033[0;94mASM compiled.\033[0m "

clean:
	@make clean -C ../../libft
	@rm -f *.o
	@echo "\033[1;91mLib has been CLEANED\033[0m "

fclean: clean
	@make fclean -C ../../libft
	@echo "\033[1;91m./asm has been DELETED\033[0m "
	@rm -f $(NAME)

re:
	@make fclean
	@make

