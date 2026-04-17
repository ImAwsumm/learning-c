ALL_FLAGS = -Wall -Wextra -Wpedantic -std=c99

GCC = gcc
ZIG = zig cc

delete = delete.c -o del
kill_p = russian-roulette.c -o kill-process


all:
	$(GCC) $(delete) $(ALL_FLAGS)
	$(GCC) $(kill_p) $(ALL_FLAGS)

zig:
	$(ZIG) $(delete) $(ALL_FLAGS)
	$(ZIG) $(kill_p) $(ALL_FLAGS) -Werror

clean:
	@rm kill-process
	@rm del
