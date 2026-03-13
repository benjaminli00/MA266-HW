GCC = gcc -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror main.c flesch.c -o flesch
EXEC = flesch

$(EXEC): flesch.h flesch.c main.c
	$(GCC)

test%: $(EXEC)
	./$(EXEC) inputs/input_$*.txt

testall: $(EXEC)
	./$(EXEC) inputs/input_1.txt > output1.txt
	./$(EXEC) inputs/input_2.txt > output2.txt
	./$(EXEC) inputs/input_3.txt > output3.txt
	./$(EXEC) inputs/input_4.txt > output4.txt
	./$(EXEC) inputs/input_5.txt > output5.txt
	./$(EXEC) inputs/input_6.txt > output6.txt
	./$(EXEC) inputs/input_7.txt > output7.txt
	./$(EXEC) inputs/input_8.txt > output8.txt

	diff -Bb output1.txt expected/expected_1.txt
	diff -Bb output2.txt expected/expected_2.txt
	diff -Bb output3.txt expected/expected_3.txt
	diff -Bb output4.txt expected/expected_4.txt
	diff -Bb output5.txt expected/expected_5.txt
	diff -Bb output6.txt expected/expected_6.txt
	diff -Bb output7.txt expected/expected_7.txt
	diff -Bb output8.txt expected/expected_8.txt
	
%.o : %.c
	$(GCC) -c $<

clean:
	/bin/rm -f *.o
	/bin/rm -f $(EXEC)
	/bin/rm -f $(EXEC)_check
	/bin/rm -f path? log?
	/bin/rm -f output*
