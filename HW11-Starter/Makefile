CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
GCC = gcc $(CFLAGS)
EXEC = hw11

TEST_IDS = 1 2 3

all: hw11.c list.c maze.c mazehelper.c path.c solver.c
	$(GCC) -o $(EXEC) hw11.c list.c maze.c mazehelper.c path.c solver.c

test: all
	@status=0; \
	for i in $(TEST_IDS); do \
		./$(EXEC) testcases/maze$$i output$$i; \
		if diff -u expected/expected$$i output$$i > /dev/null; then \
			echo "[PASS] maze$$i"; \
		else \
			echo "[FAIL] maze$$i"; \
			status=1; \
		fi; \
	done; \
	exit $$status

memtest: all
	@status=0; \
	for i in $(TEST_IDS); do \
		valgrind -s --errors-for-leak-kinds=all --leak-check=full --show-leak-kinds=all --error-exitcode=2 ./$(EXEC) testcases/maze$$i vg_output$$i > /dev/null 2> valgrind$$i.log; \
		if [ $$? -eq 0 ]; then \
			echo "[PASS] valgrind maze$$i"; \
		else \
			echo "[FAIL] valgrind maze$$i (see valgrind$$i.log)"; \
			status=1; \
		fi; \
	done; \
	exit $$status

clean:
	rm -f $(EXEC) *.o output* vg_output* valgrind*.log

.PHONY: all test memtest clean
