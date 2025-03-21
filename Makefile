##
## EPITECH PROJECT, 2024
## makefile
## File description:
## makefile
##

CC      =	gcc

NASM	=	nasm

LD	=	ld

RM	=	rm -f

BINARY	=	a.out

NAME	=	libasm.so

DEBUG_NAME	=	debug_$(NAME)

NASM_FLAGS	=	-f elf64

LD_FLAGS = -shared

SRC	=	$(shell find ./src/ -name '*.asm')

OBJ	=	$(SRC:.asm=.o)

CFLAGS    =    -W -Wall -Wextra -Werror

TEST_NAME	=	unit_tests

SRC_TESTS	=	$(shell find tests/ -name '*.c')

TEST_FLAGS	=	--coverage -lcriterion -ldl

OBJ_TESTS	=	*.gcno *.gcda

%.o: %.asm
	$(NASM) $(NASM_FLAGS) -o $@ $<

all:	$(OBJ)
	$(LD) $(LD_FLAGS) $(OBJ) -o $(NAME)

debug: NASM_FLAGS += -g
debug: re
	$(LD) $(LD_FLAGS) $(OBJ) -o $(DEBUG_NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(BINARY)
	$(RM) $(NAME)
	$(RM) $(DEBUG_NAME)

re:	fclean all

tests_run:	all
	$(CC) $(SRC_TESTS) $(TEST_FLAGS) -o $(TEST_NAME)
	./$(TEST_NAME) && gcovr -e tests/ && gcovr -b -e tests/

tests_clean:
	$(RM) $(OBJ_TESTS)

tests_fclean: tests_clean
	$(RM) $(TEST_NAME)

tests_re: fclean all

clean_all: fclean tests_fclean
