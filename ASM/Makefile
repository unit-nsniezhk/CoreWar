NAME =  asm
FLAGS = -Wall -Werror -Wextra
ASM_FILES = $(addprefix src/, main.c)
INCLUDES = -I ./includes
LIBFTPRINTF_LIB = ./../libftprintf/libftprintf.a

all: $(NAME)
$(NAME): $(ASM_OFILES)
	@make all -C ./../libftprintf
	@gcc $(FLAGS) $(INCLUDES) -o $(NAME) $(ASM_FILES) $(LIBFTPRINTF_LIB)
	@echo "\033[0;94mASM compiled.\033[0m "
clean:
	@make clean -C ./../libftprintf
	@echo "\033[1;91mLib has been CLEANED\033[0m "
fclean: clean
	@make fclean -C ./../libftprintf
	@echo "\033[1;91m./asm has been DELETED\033[0m "
	@rm -f $(NAME)
re:
	@make fclean
	@make
ra:
	@gcc $(FLAGS) $(INCLUDES) -o $(NAME) $(ASM_FILES) $(LIBFTPRINTF_LIB)
	@echo "\033[0;94mASM compiled.\033[0m "
