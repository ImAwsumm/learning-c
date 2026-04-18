ZIG = zig cc 

FG = -Wall -Wextra -Wpedantic

PRIME_SQRT = check-if-prime.c -o check-if-prime

DIVIDE_SRC = dividing.c -o div

base:
	$(ZIG) $(PRIME_SQRT) $(FG) -Werror
all:
	$(ZIG) $(PRIME_SQRT) $(FG)
	$(ZIG) $(DIVIDE_SRC) $(FG)
