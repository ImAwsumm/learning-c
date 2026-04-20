FLAGS = -Werror -Wall -Wextra
switch_compile_cmd = switch-fallthrough.c -o switch-fallthrough
GCC = gcc
ZIG = zig cc
FG = -Wall -Wextra -Wpedantic -std=c99
ER = -Werror

compilation:
	@#gcc $(FLAGS) -c switch-fallthrough.c
	gcc switch-fallthrough.c -o switch-fallthrough

all:
	gcc $(switch_compile_cmd) $(FG)

base:
	$(ZIG) $(switch_compile_cmd) $(FG) $(ER)


clean: 
	@rm switch-fallthrough.o

binary: compilation
	gcc switch-fallthrough.o -o setup $(FLAGS)
