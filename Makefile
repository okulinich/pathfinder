NAME = pathfinder

INC = pathfinder.h
OBJH = obj/pathfinder.h

SRC = mx_errors.c mx_errors2.c mx_find_my_way.c mx_main.c mx_printerr.c mx_prints.c mx_paths.c mx_graph.c mx_fill_graph.c mx_find_occur.c mx_atoi.c mx_check_all.c mx_check_num_isl.c

OBJ = mx_errors.o mx_errors2.o mx_find_my_way.o mx_main.o mx_printerr.o mx_prints.o mx_paths.o mx_graph.o mx_fill_graph.o mx_find_occur.o mx_atoi.o mx_check_all.o mx_check_num_isl.o

CFLAG = -std=c11 -Wall -Wextra -Wpedantic -Werror

all: install clean

install:
	@make -sC libmx
	@cp $(addprefix src/, $(SRC)) .
	@cp $(addprefix inc/, $(INC)) .
	@clang $(CFLAGS) -c $(SRC) -I $(INC)
	@clang $(CFLAGS) libmx/libmx.a $(OBJ) -o $(NAME)
	@mkdir -p obj
	@mv $(OBJ) ./obj
uninstall: clean
	@make uninstall -sC libmx
	@rm -rf $(NAME)
clean:
	@make clean -sC libmx
	@rm -rf $(INC) $(SRC) ./obj
reinstall: uninstall install
