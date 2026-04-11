# ***
# *** Do NOT modify this file
# ***

CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
GCC = gcc $(CFLAGS)
EXEC = hw14
OBJS = hw14.o
VALGRIND = valgrind --tool=memcheck --leak-check=yes --verbose

$(EXEC): $(OBJS) huffman.h
	$(GCC) $(OBJS) -o $(EXEC)

test: $(EXEC)
	./$(EXEC) testcases/basic basic_sorted basic_huffman basic_header
	./$(EXEC) testcases/gophers gophers_sorted gophers_huffman gophers_header
	./$(EXEC) testcases/woods woods_sorted woods_huffman woods_header
	./$(EXEC) testcases/para para_sorted para_huffman para_header
	./$(EXEC) testcases/prideandprejudice prideandprejudice_sorted prideandprejudice_huffman prideandprejudice_header

check: test
	diff -u expected/basic_sorted basic_sorted
	diff -u expected/basic_huffman basic_huffman
	cmp expected/basic_header basic_header
	diff -u expected/gophers_sorted gophers_sorted
	diff -u expected/gophers_huffman gophers_huffman
	cmp expected/gophers_header gophers_header
	diff -u expected/woods_sorted woods_sorted
	diff -u expected/woods_huffman woods_huffman
	cmp expected/woods_header woods_header
	diff -u expected/para_sorted para_sorted
	diff -u expected/para_huffman para_huffman
	cmp expected/para_header para_header
	diff -u expected/prideandprejudice_sorted prideandprejudice_sorted
	diff -u expected/prideandprejudice_huffman prideandprejudice_huffman
	cmp expected/prideandprejudice_header prideandprejudice_header

memory: $(EXEC)
	$(VALGRIND) --log-file=log-basic ./$(EXEC) testcases/basic basic_sorted basic_huffman basic_header
	$(VALGRIND) --log-file=log-gophers ./$(EXEC) testcases/gophers gophers_sorted gophers_huffman gophers_header
	$(VALGRIND) --log-file=log-woods ./$(EXEC) testcases/woods woods_sorted woods_huffman woods_header

%.o : %.c
	$(GCC) -c $<

clean:
	/bin/rm -f *.o
	/bin/rm -f $(EXEC)
	/bin/rm -f basic_sorted basic_huffman basic_header
	/bin/rm -f gophers_sorted gophers_huffman gophers_header
	/bin/rm -f woods_sorted woods_huffman woods_header
	/bin/rm -f para_sorted para_huffman para_header
	/bin/rm -f prideandprejudice_sorted prideandprejudice_huffman prideandprejudice_header
	/bin/rm -f log-basic log-gophers log-woods
