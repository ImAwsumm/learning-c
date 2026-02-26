FLAGS = -Werror -Wall -Wextra

compilation:
	gcc $(FLAGS) -c switch-fallthrough.c

clean: 
	@rm switch-fallthrough.o

binary: compilation
	gcc $(FLAGS) switch-fallthrough.o -o setup
