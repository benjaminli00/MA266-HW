# ***
# *** Do NOT modify this file
# ***

CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
GCC = gcc $(CFLAGS)
EXEC = hw9
OBJS = hw9.o maze.o mazehelper.o path.o solver.o
VALGRIND = valgrind --tool=memcheck --leak-check=yes --verbose

$(EXEC): $(OBJS) maze.h mazehelper.h path.h solver.h
	$(GCC) $(OBJS) -o $(EXEC)

test: $(EXEC)
	./$(EXEC) testcases/maze1 path1
	./$(EXEC) testcases/maze2 path2
	./$(EXEC) testcases/maze3 path3
	./$(EXEC) testcases/maze4 path4
	./$(EXEC) testcases/maze5 path5

check:
	$(GCC) -DCHECK_PATH $(CFLAGS) -o $(EXEC)_check hw9.c maze.c mazehelper.c path.c solver.c
	./$(EXEC)_check testcases/maze1 path1
	./$(EXEC)_check testcases/maze2 path2
	./$(EXEC)_check testcases/maze3 path3
	./$(EXEC)_check testcases/maze4 path4
	./$(EXEC)_check testcases/maze5 path5

memory: $(EXEC)
	$(VALGRIND) --log-file=log1 ./$(EXEC) testcases/maze1 path1
	$(VALGRIND) --log-file=log2 ./$(EXEC) testcases/maze2 path2
	$(VALGRIND) --log-file=log3 ./$(EXEC) testcases/maze3 path3
	$(VALGRIND) --log-file=log4 ./$(EXEC) testcases/maze4 path4
	$(VALGRIND) --log-file=log5 ./$(EXEC) testcases/maze5 path5

%.o : %.c
	$(GCC) -c $<

clean:
	/bin/rm -f *.o
	/bin/rm -f $(EXEC)
	/bin/rm -f $(EXEC)_check
	/bin/rm -f path? log?
