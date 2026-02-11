# ***
# *** Do NOT modify this file
# ***

CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
TESTS = -DTEST_READ -DTEST_WRITE -DTEST_QSORT -DTEST_SORTID -DTEST_SORTNAME -DTEST_SORTED
GCC = gcc $(CFLAGS) $(TESTS)
EXEC = hw5
OBJS =  hw5.o student.o
VALGRIND = valgrind --tool=memcheck --leak-check=yes --verbose

$(EXEC): $(OBJS) hw5.h
	$(GCC) $(OBJS) -o $(EXEC) 

test: $(EXEC)
	./$(EXEC) testcases/input1 id1 name1
	./$(EXEC) testcases/input2 id2 name2
	./$(EXEC) testcases/input3 id3 name3
	./$(EXEC) testcases/input4 id4 name4

testid: test
	diff -w id1 expected/id1
	diff -w id2 expected/id2
	diff -w id3 expected/id3
	diff -w id4 expected/id4

testname: test
	diff -w name1 expected/name1
	diff -w name2 expected/name2
	diff -w name3 expected/name3
	diff -w name4 expected/name4

memory: $(EXEC)
	$(VALGRIND) --log-file=log1 ./$(EXEC) testcases/input1 id1 name1
	$(VALGRIND) --log-file=log2 ./$(EXEC) testcases/input2 id2 name2
	$(VALGRIND) --log-file=log3 ./$(EXEC) testcases/input3 id3 name3
	$(VALGRIND) --log-file=log4 ./$(EXEC) testcases/input4 id4 name4

%.o : %.c
	$(GCC) -c $< 

clean:
	/bin/rm -f *.o
	/bin/rm -f $(EXEC)
	/bin/rm -f id? name? log?
