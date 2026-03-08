CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
TESTS = -DTEST_DIVIDE -DTEST_INTERLEAVE -DTEST_SHUFFLE
GCC = gcc $(CFLAGS)
EXEC = hw8
OBJS =  main.o shuffle.o
VALGRIND = valgrind --tool=memcheck --leak-check=yes

$(EXEC): $(OBJS) shuffle.h
	$(GCC) $(OBJS) -o $(EXEC)

%.o : %.c
	$(GCC) -c $<

test: $(EXEC)
	./hw8 3 1 | sort > outputs/output_3_1
	./hw8 3 2 | sort > outputs/output_3_2
	./hw8 4 2 | sort > outputs/output_4_2
	./hw8 6 2 | sort > outputs/output_6_2
	diff -w outputs/output_3_1 expected/expected_3_1
	diff -w outputs/output_3_2 expected/expected_3_2
	diff -w outputs/output_4_2 expected/expected_4_2
	diff -w outputs/output_6_2 expected/expected_6_2


	echo "test finished"

memory: $(EXEC)
	$(VALGRIND) --log-file=memory/log1 ./hw8 3 1
	$(VALGRIND) --log-file=memory/log2 ./hw8 3 2
	$(VALGRIND) --log-file=memory/log3 ./hw8 4 2
	$(VALGRIND) --log-file=memory/log4 ./hw8 6 2

clean:
	/bin/rm -f *.o
	/bin/rm -f $(EXEC)
	/bin/rm -f log? output?