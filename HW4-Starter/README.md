# Homework 4: Function Pointer

## Goals

This assignment continues from the previous assignment (HW3).  In
HW3, the function (we have five examples `func1`, `func2`, ... `func5`, remember?) to be integrated is not part of the arguments to `integrate`.
This assignment makes the function part of the argument. As a result,
the integration function is more flexible because everything needed
is passed as arguments.


You will learn how to:
* Create a type for functions that have the same types of arguments and return value
* Make a structure with an attribute as a function pointer
* Write a function that takes a pointer to this structure (modified from HW3)
* Write a function that integrates multiple functions
* Read data from a file and write output to another file
* Detect errors and return proper code (`true`, `false`, `EXIT_SUCCESS`, or `EXIT_FAILURE`)
* Write Makefile to test

Please be aware that this you need to write a lot more for this
assignment. **Please start early.** You are encouraged to study HW1 - HW3
thoroughly before starting this assignment. This assignment is
designed with the assumption that you are familiar with the details
in HW1 - HW3.


## Background

### 1. Function pointer

In HW3 you have seen how to use a pointer to store the address of a structure object. 
Here in this assignment, you will learn to use a pointer to store the address of a function.

Every function in a C program refers to a specific **address**. It is possible to create pointers to store functions' starting addresses, and then call functions by using those addresses, instead of the function name directly.

In C, a function pointer is declared by this syntax:

`typedef type (* typename) (arguments)`

For example:

`typedef int (* funcptr)(int, int);`

creates a type for pointers to functions that take two integers
as input arguments and return one integer.

Here is an example of creating and using function pointers:

```
// create a function pointer type called "funcptr"
// funcptr functions take two arguments (both are int) and return an int
typedef int (* funcptr)(int, int); 

funcptr f = foo; // f now refers to the function foo

int x = f(3, 4); // equivalent to: int x = foo(3, 4);
```

In this assignment, you need to create a type called `funcptr` (**you must
use this name**) for the functions you want to integrate.
A function of type `funcptr` should take as argument one `double`, and return one `double`.

With this type, it is possible to create an array `funcptr funcs[5]` containing five functions called
`func1`, `func2`, ..., `func5`. The program can go through these five functions in the same way
as going through normal array elements. 
For example, `funcs[0]` refers to the first element in this function array, which is `func1`.

### 2. Function pointer as attribute/field

An important concept in developing high-quality software is making a
function's behavior controlled by the argument(s) and nothing else. In
HW3, the function to be integrated was not in the argument -- we assumed it was a function called `func`.
This can easily create confusion. Similarly, global variables and static
variables can create confusion because they can make functions behave
in ways that are not completely controlled by the input arguments.
Thus, you should avoid using global and static variables.

After creating the type for function pointers, it is possible to make a
function pointer an attribute of a structure.  Now, everything needed
to run the integration function is passed into the integration
function as the argument. 

### 3. Reading and writing files

This assignment asks you to read and write data from files. The key to working with files is to 
understand the basic file manipulation API (an "Application Program Interface" -- the functions that provide certain behavior):

1) `FILE *`: All files are manipulated through pointers to FILE structures. We will call the pointer to a FILE structure a file "handle".

In the following we use `FILE * fp;` to declares a file handle called `fp` as an example.

2) `FILE * fopen(const char * path, const char * mode)`: Open a file whose file name is stored in the character array `path`.
The character array `mode` indicates how you want to access the file. The `mode` in `fopen()` has several possible values. For example:

* `"r"`: open the file for reading, starting at the beginning of the file. The file must exist.
* `"w"`: open the file for writing, starting at the beginning of the file. This deletes any content already in the file.
* `"a"`: open the file for appending, starting at the end of the current contents of the file. The file is created if it does not exist.

For example, the following opens file `"input.txt"` in the read-only mode starting from the beginning of the file. The file `"input.txt"` must exist.
```
FILE *fp;
fp = fopen("input.txt", "r");
```

There are other modes for `fopen` available (such as `"r+"`, `"w+"`, `"a+"`). You can find out more by typing `man fopen` on the ecegrid machines.

3) `int fscanf(FILE * file, const char * format, ...)`: This works just like `scanf`, but reads from the file pointer file.

* For example, `fscanf(fp, "%lf\n", &d)` reads a double (%lf) from the input file `fp` and stores the result in `d`. You can find out more by typing `man fscanf` on the ecegrid machines.

4) `int fprintf(FILE * file, const char * format, ...)`: This works just like `printf`, but writes to the file pointer file. Note that for fprintf to work, the file you pass should have been opened in a mode that allows writing.

* For example, `fprintf(fp, "%d", 2021);` writes a integer (%d) 2021 to the file `fp`. You can find out more by typing `man fprintf` on the ecegrid machines.

5) `int feof(FILE * file)`: checks the end-of-file indicator for the given file. This function returns a **non-zero** value when End-of-File indicator is detected, else returns zero.

6) `int fclose(FILE * file):` Close the file. You should always close files when you are done using them.

## What do you need to do?

Your job is to write an integration function using the same integration method as Homework 3: Structs (you can even re-use your code from there). Unlike the integration function in the previous assignment, however, your integration method will need to accept a new kind of structure, one that contains a function pointer pointing to the function you want to integrate. This will require both defining the function pointer type you need, as well as a new structure that contains all the necessary information to perform an integration.

### 1. Files you need to modify

Unlike in previous assignments, this assignment asks you to modify three files. The exact details of what each file should contain are provided in the initial files for the assignment (pay careful attention to the comments in each file!), but briefly, here are the files you need to modify, and what you need to do:

* `hw4.h`: You will define two things: 1) the function pointer type called `funcptr`;
  and 2) a new structure called `Integration` that contains all the components necessary to perform an integration,
  including a pointer to the function to be integrated, as well as a field to store the result of the integration.
* `integrator-hw4.c`: This file contains your integration functions: `integrate`, which takes the structure you defined in `hw4.h` and uses that information to perform a numerical integration, and `runIntegrate`, which takes the name of an input file and an output file as arguments and:
    1) Reads the upper limit, lower limit, and number of intervals from the input file.
    2) Uses `integrate` to numerically integrate five functions (provided for you, called `func1`, `func2`, `func3`, `func4`, and `func5`). 
    3) Writes the results of each integration out to the output file.
* `Makefile`: read below for writing Makefile for testing 

### 2. Improve Makefile

By now, you have seen at least three Makefiles in HW1, HW2, and HW3.
Please read them carefully and understand what they do.

You should have discovered that every Makefile so far has this pattern

```
file.o: file.c
	$(GCC) $(CFLAGS) -c file.c
```	

and file is replaced by specific file names.

If five object files are needed, this pattern has written five times.
This is tedious and error prone (remember DRY vs. WET code in HW3?)

Fortunately, there is a simple way to write this as a rule.

```
%.o : %.c 
	$(GCC) $(CFLAGS) -c $<
```

This means whenever a `.o` file is needed, Makefile will look for the 
corresponding `.c` file and use `gcc` (with the flags) to compile it. 
This can dramatically reduce the effort writing Makefile. 

Besides, `$<` in the target line means the first prerequisite filename. For example
```
all : main.c struct.h
	$(GCC) $(CFLAGS) -o $<
```
is equivalent to
```
all : main.c struct.h
	$(GCC) $(CFLAGS) -o main.c
```

Makefile can do much more than creating executable files. You can run
test cases using Makefile. You have seen this in HW1, HW2, and HW3.  

For example, in HW1, `test` and `test-ascending` show how to run multiple test cases.

Your Makefile for HW4 needs to run the four test cases stored in testcases,
using a target called `testall`.

**Don't forget to define the flags `RUN_INTEGRATE` and `TEST_INTEGRATE` to
make sure that the code you write in integrator-hw4.c gets compiled!**

3. Testing your integrator

Similar as HW3, we provided five functions for testing (`func1`, `func2`, `func3`, `func4`, `func5`).
And we provide you with four testcases in the directory `testcases/`. The format of a test file is:

```
<lower bound (floating point)>
<upper bound (floating point)>
<# intervals (integer)>
<expected answer for func1 (floating point)>
<expected answer for func2 (floating point)>
<expected answer for func3 (floating point)>
<expected answer for func4 (floating point)>
<expected answer for func5 (floating point)>
```

The provided test files (in the directory `testcases/`) all have the answer you are expected to get (the **approximate** integration results that we should get from the homework). Feel free to generate new tests using answers.xlsx, where you can use answers.xlsx to calculate the "correct" answer (the **exact** integration results that is from exact numerical integration) for the functions you are testing. Note that exact numerical integration method is beyond the topic of this class. Thus, for this assignment we simply use [Trapezoidal Rule](https://en.wikipedia.org/wiki/Trapezoidal_rule#Uniform_grid) as the canonical integration method and allow 1% difference error in grading.

## Grading

You will receive zero if your program has error or warning from `gcc`.

You will receive zero if your program terminates abnormally (e.g., segmentation fault).

It is very important that you follow the instructions precisely
(including functions' names and variables' names). Failing to follow
these instructions will likely make you receive zero in this
assignment.

## Submission
Please submit the following files:
1. `hw4.h`
2.  `integrator-hw4.c`

Please make sure to drag these files on Gradescope directly or compress them into a single .zip file. Submissions that do not follow this instruction will not be graded by the auto-grader.