# Homework 6: Merge Sort

    /\     _        _     /\
    || ___( \      / )___ ||
    ||(___)\ \    / /(___)||
    \/      \_)()(_/      \/

## Goals

In HW5,
you wrote several routines to sort Student records that you read in from a
file. Your job in that assignment was to write comparison functions to compare
Students by different fields in their records. However, you used the C
standard library's built-in `qsort` function to perform the actual sort. In
this assignment, you will write your own sort function.

In other words, compared with HW5, the only difference in HW6 is that you'll write your own function for sorting.
All other parts are the same. In the case that you were unable to complete your comparison functions for HW5, 
you can still work on HW6 using the *pre-built* object file `student.o` we provided.
See the section **Testing your code** for details.

You will learn:

* Recursion principles
* "Divide-and-conquer" recursion
* Merge sort

## Release and due date

- Release: Monday, February 9 (morning)
- Due: Monday, February 23 at 9:00pm

## Background

### 1. Recursion

In a superficial sense, recursion is what happens whenever a function `f` calls itself, as in the "standard" factorial example:

```
int factorial(int n) {
  if (n == 0) {return 1;}
  else {return n * factorial(n - 1);}
}
```

It is better to think of recursion as a *technique* for solving problems. Many problems can be thought of using the following pattern:

1. Break the problem up into "smaller" version(s) of the same problem.
2. Solve the smaller problem(s) by calling the same function (we call this the 
   *inductive case*)
3. Use the solutions to the smaller problem(s) to solve the original problem.

This seems like a process that doesn't end: to solve a big problem, we break
it up into smaller versions of the problem -- but then we have to solve the
smaller problem, which isn't any different! The key is that you can *repeat*
this process, solving the smaller problems in the same way. At each step, you
get smaller and smaller problems. Eventually, the problem is small enough that
getting the answer is trivial. We call this the *base case*.

We can see this in the `factorial` example: rather than computing `factorial`
of `n`, we realize that `n!` is just `n * (n-1)!` (Step 1: break the problem
up into a smaller version of the same problem) -- so we can call `factorial(n - 1)`
(Step 2: solve the smaller problem by calling the same function). We can 
then multiply this by `n` to find `factorial(n)` (Step 3: use the solution of
the smaller problem to solve the original problem). We also see that the *base
case* is simple: we already know what `0!` is, so there is no need to "break
it up" into a smaller problem -- we can just return 1.

> Note: you could also write factorial with a loop, and the loop version would
probably be faster, so you might wonder why we need recursion. The code you
will write in this assignment is a case where recursion is basically the only
way to write it.

**Induction:** One way to think about how to correctly write a recursive function is to think
*inductively*: We can *assume* that the recursive function already works, but
only if the function is called on a smaller problem than what we're solving.
We can then write the recursive function assuming that it already works. The
only thing we have to make sure we do is write correct *base cases* -- we need
to make sure that for the smallest versions of the function, we compute the
correct answer. (This sounds circular, but it works for the same reason that
inductive proofs work)

### 2. Divide-and-conquer recursion

A very common pattern for recursive problems is *divide-and-conquer*
recursion: to solve a problem on *n* pieces of data (e.g., an array of length
*n*), we break the input up into two pieces, each with *n/2* pieces of data
(e.g., two arrays, each with half the elements), call the recursive function
on these smaller pieces, then write some code to combine the results from
those two functions into the final answer. The base case for this style of
function is what to do when you have only 1 element.

Consider a toy example where we want to sum up all the values in an input
array with n elements. Here, if we divide the array in two and sum those two
sub-arrays, we can add the results to get the sum of the whole array. The base
case is that the sum of an array with just one element is the value of that
element:

```
int sum(int * arr, int nels) {
  if (nels = 1) {return arr[0];}
  
  int sum1 = sum(arr, nels/2); // calculating the sum of the first half of array
  int sum2 = sum(&arr[nels/2], (nels + 1)/2); // calculating the sum of the second half of array
  
  return sum1 + sum2;
}
```

> Note The `(nels + 1)/2` stuff is just a fancy way of dealing with arrays that have
an odd number of elements, where sum2 works over a slightly larger array than
sum1. In integer division, `nels/2` is like computing `floor(n/2)`, and `(nels + 1)/2` is like computing `ceiling(n/2)`. More generally, to compute
`ceiling(a/b)` you can do integer division: `(a + b - 1)/b`.

### 3. Merge sort

Your task in this programming assignment is to write a *merge sort*. Merge
sort is an application of divide and conquer recursion to sort an array. The
heart of merge sort is the `merge` operation, which combines two *already
sorted* arrays to produce a new sorted array. To merge two sorted arrays,
imagine you have two cursors, which start at the beginnings of the two arrays.
Look at the two elements pointed to by the cursor: add whichever element is
smaller to the output array, then move that cursor forward by 1 element. (If
one of the cursors is already at the end of its array, the other cursor always
"wins.")

This `merge` operation gives us a way of combining the solutions of two
smaller problems to solve the larger problem of sorting an array:

1. Divide the array into two pieces
2. Sort the two pieces by recursively calling the same function
3. Use `merge` to merge the two resulting sorted pieces

So what should the *base case* be? How do we make sure we don't keep sorting
smaller and smaller arrays? Note something simple: an array with only one
element is already sorted!

## What do you need to do?

You will need to only modify and submit ONE file: `msort.c`, providing new
definitions of two functions: `merge` and `msort`.

`msort` is the function for merge sort.

The signature of `msort` is:

`void msort(Student * base, int nel, int (*compar)(const void *, const void *))`

Where `compar` is a pointer to a comparison function (you can/should reuse your comparison functions from HW5).

As explained above, the heart of merge sort is a `merge` function, which you will also have to write. The signature of `merge` is:

`Student * merge(Student * base1, int nel1, Student * base2, int nel2, int (*compar)(const void *, const void *))`

Where `merge` returns a *newly allocated* array of `Student`s that is the result of merging the arrays `base1` and `base2`.

You can test whether your merge sort works using the `areStudentsSorted` function from HW5.

### 1. Testing your code 
Note: This assignment builds on HW5, replacing `qsort` with your own sort,
but otherwise leaving the rest of the assignment the same.

Thus, you can consider one of the following two options to test your code:

* **Option 1:** If your HW5 works fine, you can include your own `student.c` from HW5 here.
**Three** minor things you need to modify if you choose to use your own `student.c` from HW5: 
*first*, in the `sortStudents` function of your `student.c`, modify to call `msort` instead of `qsort`, the signature of `msort` is: `void msort(Student * base, int nel, int (*compar)(const void *, const void *))`; 
*second*, remember to `#include "msort.h"` in your `student.c`; *third*, change from `#include "hw5.h"` to `#include "hw6.h"` in your `student.c`.
Then, before testing the code, you can use the command `rm -rf student.o` to delete the pre-built object file `student.o` that is in the repository and use the Makefile (use the command `make TARGET_NAME`) to test the code with your own version of `student.c`.

* **Option 2:** If you were unable to complete your comparison functions for HW5, you may use the *pre-built* object file `student.o` that we provide in this repository.
You can then link this file in your Makefile instead of compiling your 
own versions of `student.c`. If you take this option *you will 
have to develop your code on the ecegrid machines*.

## Grading
You will lose 1 point for every 1 byte of memory leak. In other words, if your program leaks 100 or more bytes, you will **receive zero**.
We will grade HW6 using the same inputs (and expected outputs) as HW5.
Do NOT remove the `#ifndef` directives around `merge` and `msort`. (Note that `#ifndef` works the opposite way to `#ifdef` -- if a particular flag is *not* defined, then the code in the `#ifndef` will be included).

## Submission
Submit only the following files:
1. `msort.c`
