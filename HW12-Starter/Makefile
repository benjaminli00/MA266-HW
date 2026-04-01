CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
GCC = gcc $(CFLAGS) $(TESTFLAGS)
EXEC = hw12

TESTFLAGS = -DTEST_BUILDTREE

$(EXEC): main.c tree.c tree.h
	$(GCC) -o $(EXEC) main.c tree.c

%.o : %.c
	$(GCC) -c $<

test%: $(EXEC)
	./$(EXEC) testcases/test$*in testcases/test$*post output$*
	diff -w output$* expected/expected$*
	echo "test$* passed!"


clean:
	/bin/rm -f *.o
	/bin/rm -f $(EXEC)
	/bin/rm -f output? log?

all: test1 test2 test3 test4 test5 test6
