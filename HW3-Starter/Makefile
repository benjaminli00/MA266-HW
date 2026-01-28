CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
# Enable verbose debug prints in hw3.c (guarded by #ifdef DEBUG)
# Usage: make DEBUG=1 <target>
DEBUG ?= 0
ifeq ($(DEBUG),1)
  CFLAGS += -DDEBUG
endif
GCC = gcc $(CFLAGS)
OBJS =  hw3.o integrator.c
FUNCS = func1.o func2.o func3.o func4.o func5.o

# This Makefile can be shortened by using loop. 
# It shows all steps to explain what it does

all: hw3a hw3b

# build hw3 using integrate1, and all five functions
# creates 5 different executables, because of the dependences
hw3a: hw3-func1-1 hw3-func2-1 hw3-func3-1 hw3-func4-1 hw3-func5-1
	
# build hw3 using integrate2, and all five functions
# creates 5 different executables, because of the dependences
hw3b: hw3-func1-2 hw3-func2-2 hw3-func3-2 hw3-func4-2 hw3-func5-2
	

# build each of the executables for integrate1
hw3-func1-1: hw3a.o integrator.o func1.o
	$(GCC) hw3a.o integrator.o func1.o -o hw3-func1-1

hw3-func2-1: hw3a.o integrator.o func2.o
	$(GCC) hw3a.o integrator.o func2.o -o hw3-func2-1	

hw3-func3-1: hw3a.o integrator.o func3.o
	$(GCC) hw3a.o integrator.o func3.o -o hw3-func3-1

hw3-func4-1: hw3a.o integrator.o func4.o
	$(GCC) hw3a.o integrator.o func4.o -o hw3-func4-1 -lm

hw3-func5-1: hw3a.o integrator.o func5.o
	$(GCC) hw3a.o integrator.o func5.o -o hw3-func5-1 -lm

# build each of the executables for integrate2
hw3-func1-2: hw3b.o integrator.o func1.o
	$(GCC) hw3b.o integrator.o func1.o -o hw3-func1-2

hw3-func2-2: hw3b.o integrator.o func2.o
	$(GCC) hw3b.o integrator.o func2.o -o hw3-func2-2	

hw3-func3-2: hw3b.o integrator.o func3.o
	$(GCC) hw3b.o integrator.o func3.o -o hw3-func3-2

hw3-func4-2: hw3b.o integrator.o func4.o
	$(GCC) hw3b.o integrator.o func4.o -o hw3-func4-2 -lm

hw3-func5-2: hw3b.o integrator.o func5.o
	$(GCC) hw3b.o integrator.o func5.o -o hw3-func5-2 -lm


# build hw3 with integrate1
hw3a.o: hw3.c hw3.h
	$(GCC) -c -DINTEGRATE_1 hw3.c -o hw3a.o

# build hw3 with integrate2
hw3b.o: hw3.c hw3.h
	$(GCC) -c -DINTEGRATE_1 -DINTEGRATE_2 hw3.c -o hw3b.o

# compile integrator
integrator.o: integrator.c hw3.h
	$(GCC) -c integrator.c

# compile func1
func1.o: func1.c
	$(GCC) -c func1.c

# compile func2
func2.o: func2.c
	$(GCC) -c func2.c

# compile func3
func3.o: func3.c
	$(GCC) -c func3.c

# compile func4
func4.o: func4.c
	$(GCC) -c func4.c

# compile func5
func5.o: func5.c
	$(GCC) -c func5.c


# test integrate1 using five different functions
# each function is tested using three sets of input data
hw3-test1: hw3a
	mkdir -p outputs
	echo "testing integrate1"
	echo "testing func1"
	./hw3-func1-1 testcases/test-func1-1 > outputs/test-func1-1.out 
	./hw3-func1-1 testcases/test-func1-2 > outputs/test-func1-2.out
	./hw3-func1-1 testcases/test-func1-3 > outputs/test-func1-3.out
	echo "testing func2"
	./hw3-func2-1 testcases/test-func2-1 > outputs/test-func2-1.out
	./hw3-func2-1 testcases/test-func2-2 > outputs/test-func2-2.out
	./hw3-func2-1 testcases/test-func2-3 > outputs/test-func2-3.out
	echo "testing func3"             
	./hw3-func3-1 testcases/test-func3-1 > outputs/test-func3-1.out
	./hw3-func3-1 testcases/test-func3-2 > outputs/test-func3-2.out
	./hw3-func3-1 testcases/test-func3-3 > outputs/test-func3-3.out
	echo "testing func4"             
	./hw3-func4-1 testcases/test-func4-1 > outputs/test-func4-1.out
	./hw3-func4-1 testcases/test-func4-2 > outputs/test-func4-2.out
	./hw3-func4-1 testcases/test-func4-3 > outputs/test-func4-3.out
	echo "testing func5"             
	./hw3-func5-1 testcases/test-func5-1 > outputs/test-func5-1.out
	./hw3-func5-1 testcases/test-func5-2 > outputs/test-func5-2.out
	./hw3-func5-1 testcases/test-func5-3 > outputs/test-func5-3.out

# test integrate2 using five different functions
hw3-test2: hw3b
	mkdir -p outputs
	echo "testing integrate2"
	echo "testing func1"
	./hw3-func1-2 testcases/test-func1-1 > outputs/test-func1-1.out 
	./hw3-func1-2 testcases/test-func1-2 > outputs/test-func1-2.out
	./hw3-func1-2 testcases/test-func1-3 > outputs/test-func1-3.out
	echo "testing func2"             
	./hw3-func2-2 testcases/test-func2-1 > outputs/test-func2-1.out
	./hw3-func2-2 testcases/test-func2-2 > outputs/test-func2-2.out
	./hw3-func2-2 testcases/test-func2-3 > outputs/test-func2-3.out
	echo "testing func3"             
	./hw3-func3-2 testcases/test-func3-1 > outputs/test-func3-1.out
	./hw3-func3-2 testcases/test-func3-2 > outputs/test-func3-2.out
	./hw3-func3-2 testcases/test-func3-3 > outputs/test-func3-3.out
	echo "testing func4"             
	./hw3-func4-2 testcases/test-func4-1 > outputs/test-func4-1.out
	./hw3-func4-2 testcases/test-func4-2 > outputs/test-func4-2.out
	./hw3-func4-2 testcases/test-func4-3 > outputs/test-func4-3.out
	echo "testing func5"             
	./hw3-func5-2 testcases/test-func5-1 > outputs/test-func5-1.out
	./hw3-func5-2 testcases/test-func5-2 > outputs/test-func5-2.out
	./hw3-func5-2 testcases/test-func5-3 > outputs/test-func5-3.out


clean:
	/bin/rm -f *.o
	/bin/rm -f *.gcda *.gcno gmon.out *gcov
	/bin/rm -f hw3-func*
	/bin/rm -rf outputs
