FLAGS = -Werror -Wall -Wextra

speed_convert = mkm-to-kph.c -o speed
switch_compile_cmd = switch-fallthrough.c -o switch-fallthrough
pwd_compile = pwd.c -o pwd
leap_year = leap-year.c -o leap
keyboard = keyboard-bytes.c -o keyboard

GCC = gcc
ZIG = zig cc
FG = -Wall -Wextra -Wpedantic
ER = -Werror
C99 = -std=c99

compilation:
	@#gcc $(FLAGS) -c switch-fallthrough.c
	gcc switch-fallthrough.c -o switch-fallthrough

all:
	gcc $(switch_compile_cmd) $(FG)
	gcc $(pwd_compile) $(FG)
	gcc $(keyboard) $(FG)
	gcc $(leap_year) $(FG)

base:
	$(ZIG) $(speed_convert) $(FG) $(ER) $(C99)
	$(ZIG) $(switch_compile_cmd) $(FG) $(ER) $(C99)
	$(ZIG) $(keyboard) $(FG) $(ER) $(C99)
	$(ZIG) $(leap_year) $(FG) $(ER)
	$(ZIG) $(pwd_compile) $(FG) $(ER) 


clean: 
	@rm switch-fallthrough
	@rm leap
	@rm pwd
	@rm keyboard

binary: compilation
	gcc switch-fallthrough.o -o setup $(FLAGS)

