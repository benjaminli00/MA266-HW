CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
TESTS = -DTEST_DIVIDE -DTEST_INTERLEAVE -DTEST_SHUFFLE
GCC = gcc $(CFLAGS) $(TESTS)
EXEC = hw7
OBJS =  main.o shuffle.o
VALGRIND = valgrind --tool=memcheck --leak-check=yes

$(EXEC): $(OBJS) shuffle.h
	$(GCC) $(OBJS) -o $(EXEC)

%.o : %.c
	$(GCC) -c $<

test: $(EXEC)
	./hw7 4 | sort > outputs/output4 
	./hw7 8 | sort > outputs/output8
	./hw7 11 | sort > outputs/output11
	diff -w outputs/output4 expected/expected4
	diff -w outputs/output8 expected/expected8
	diff -w outputs/output11 expected/expected11


	echo "test finished"

memory: $(EXEC)
	$(VALGRIND) --log-file=memory/log1 ./hw7 4
	$(VALGRIND) --log-file=memory/log2 ./hw7 8
	$(VALGRIND) --log-file=memory/log3 ./hw7 11

clean:
	/bin/rm -f *.o
	/bin/rm -f $(EXEC)
	/bin/rm -f log? output?