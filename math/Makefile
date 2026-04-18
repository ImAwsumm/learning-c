ZIG = zig cc 
GCC = gcc

FG = -Wall -Wextra -Wpedantic

PRIME_SQRT = check-if-prime.c -o check-if-prime

DIVIDE_SRC = dividing.c -o div

base:
	$(ZIG) $(PRIME_SQRT) $(FG) -Werror
	$(ZIG) $(DIVIDE_SRC) $(FG) -Werror

gcc:
	$(GCC) $(PRIME_SQRT) $(FG)
	$(GCC) $(DIVIDE_SRC) $(FG)

all:
	$(ZIG) $(PRIME_SQRT) $(FG)
	$(ZIG) $(DIVIDE_SRC) $(FG)
