FLAGS = -Werror -Wall -Wextra

speed_convert = mkm-to-kph.c -o speed
switch_compile_cmd = switch-fallthrough.c -o switch-fallthrough
pwd_compile = pwd.c -o pwd
leap_year = leap-year.c -o leap
keyboard = keyboard-bytes.c -o keyboard

GCC = gcc
cc = zig cc
FG = -Wall -Wextra -Wpedantic -Wconversion
ER = -Werror
BASE = -Wall -Wextra
C99 = -std=c99

base:
	$(cc) $(speed_convert) $(FG) $(ER) $(C99)
	$(cc) $(switch_compile_cmd) $(FG) $(ER) $(C99)
	$(cc) $(keyboard) $(BASE) $(ER) $(C99)
	$(cc) $(leap_year) $(FG) $(ER) $(C99)
	$(cc) $(pwd_compile) $(BASE) $(ER)

clean: 
	@rm switch-fallthrough
	@rm leap
	@rm pwd
	@rm keyboard
	@rm speed

binary: compilation
	gcc switch-fallthrough.o -o setup $(FLAGS)

