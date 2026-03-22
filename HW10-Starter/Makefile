CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
GCC = gcc $(CFLAGS)
EXEC = hw10

TESTFLAGS = -DTEST_ELIMINATE -DTEST_CREATELIST -DTEST_DELETENODE -DDEBUG

all: main.c hw10.c
	$(GCC) $(TESTFLAGS) -o $(EXEC) main.c hw10.c
	

testall: test1 test2 test3 

test1: all
	./$(EXEC) 6 3 > output1          
	diff -w output1 testcases/expected1

test2: all
	./$(EXEC) 4 6 > output2
	diff -w output2 testcases/expected2

test3: all
	./$(EXEC) 25 7 > output3
	diff -w output3 testcases/expected3

# Run valgrind once on a larger input to check for leaks (no output diff)
valgrind: all
	valgrind -s --errors-for-leak-kinds=all --leak-check=full --show-leak-kinds=all --error-exitcode=2 ./$(EXEC) 5000 17 > /dev/null


clean:
	rm -f $(EXEC)
	rm -f *.o
	rm -f output? log?
