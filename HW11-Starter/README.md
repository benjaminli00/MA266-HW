# Homework 11: Depth First Search and Linked Lists

            ,-----------------------------.-----------------------------
      |                             |                                  |    
      |    .    .    ,---------     |     ------------------------.    |    
      |    |    |    |              |                             |    |    
      |    |    `----"--------------'    ,-------------------.    |    |    
      |    |                             |                   |    |    |    
      |    :--------------.--------------"----     ,---------:    |    |    
      |    |              |                        |         |    |    |    
      |    :---------     |    .    ,---------.    |    .    |    `----:    
      |    |              |    |              |    |    |    |         |    
      |    |     ---------'    |    :----     |    |    |    |    .    |    
      |    |                   |    |         |    |    |    |    |    |    
      |    `-------------------'    |     ----'    |    |    |    |    |    
      |    |    |    "    |    |    |    |     ---------"---------.    |    
      |    |    |         |    |    |    |                        |    |    
      |    |    `---------"----'    |    |    ,---------.    .    |    |    
      |    |                        |    |    |         |    |    |    |    
      |    :---------.--------------:    |    |    .    |    |    |    |    
      |    |         | X            |    |    |    |    |    |    |    |    
      |    "    .    `---------     |    |    `----'    |    `----'    |    
      |         |                   |    |              |              |    
      `---------"-------------------'    `--------------"--------------'

## Goals

In HW9 you built a solver for mazes that returned the *first* solution to the maze.
In this assignment, you will instead return *all* valid solutions to the maze.
Because we don't know how many solutions there are for the maze, we will use a
linked list structure to store all of the solutions.

We don't want to just store all of the paths, though. We want to order them so that the "best" path is first. 
We want to keep the paths in a *sorted* list. Paths should be sorted in ascending order, according to the **following rules**:

1. Shorter paths come before longer paths
2. If two paths are the same length, the path with fewer "turns" should be 
   before the path with more turns (a turn is when a path changes direction: 
   `EENN` has one turn, `EENE` has two turns)
3. If two paths are the same length *and* have the same number of turns, sort 
   in alphabetical order.


You will learn 
* Building a sorted linked list
* Incremental development


## Background

### 1. Sorted Linked Lists

In this homework, you want to write a linked list that will maintain
all of its nodes in sorted order. The key to writing a sorted linked list is
to maintain the *invariant* that the list is always sorted after you perform
any operation (e.g., insert, remove) on it. We can think about this inductively:

1. An empty list is, by definition, sorted.
2. If you have a sorted list, and you insert a new node *into the correct location* (i.e., between the largest node that is smaller and the smallest node that is larger), the list will still be sorted.
3. If you have a sorted list and you remove a node, the list will remain sorted.

> Note: for ordering the paths in the linked list, refer to the three rules in the **Goals** section above.


### 2. Notes on good coding habit: Incremental development

When presented with a big development challenge, it is tempting to try to write all of your code and then see if it works.
This is a path to frustrating bugs and possible failure. What you should do instead is:

1. Break the problem down into manageable chunks
2. Write code to solve each chunk
3. *Test* each chunk to make sure it works correctly before moving on to the next chunk.

This has several benefits: 
1. It is a lot more manageable to think of a big
project in terms of a lot of smaller steps you have to get done;
2. Because you test each step before moving on to the next one, you know that if
something breaks, it must be either part of the last step, or because of some
interaction between your chunks -- you don't have to search through all of
your code.

For example, here is a proposed development plan for this programming assignment:

1. Implement a small function that compares two paths according to the criteria above, to make sure that you can sort paths correctly.
2. Implement your linked list, and test adding, removing, and finding paths in the linked list.
3. Use your *now working* linked list to implement the new solver.

Note that the key here is to *test every piece of your code*.
When you implement a chunk of code, you should
write a test file -- another `.c` file that has its own `main` function. You
can compile your new code with this test file to test the functionality of
your chunk.

Another aspect of incremental development is to make sure that your program
passes simple test cases first, before moving on to complex test cases. If
your solver fails on a 10x10 maze, it may be hard to tell what's going on. If
your solver fails on a 2x2 maze, it's often much easier to debug.

## What do you need to do?

There are two things you need to do.

### 1. Build and test your linked list

Fill in and *test* the linked list methods, including making sure that you can
insert, remove, and find paths in your linked list.

**Even if you do not use a
particular linked list method in `depthFirstSolve`, make sure you implement
it.**

**HINT:** You may find the example code on Brightspace (Lecture Notes -> Week 8) helpful.
Note that you'll need to modify the `list_insert` function so that the linked list remains
sorted every time after inserting a new node.

### 2. Build and test your updated maze solver

We have provided almost all of the code you need, other than the linked list
methods themselves. The one missing piece is `depthFirstSolve` in `solver.c`.
You may start with the `depthFirstSolve` function that you implemented in HW9.
This needs to be modified so that when you find a solution to the maze, rather
than returning that solution you just add the solution to the maze and keep
going. (Make sure you keep track of `visited` correctly: a MazeSquare should
count as visited if the *current* path you are exploring has visited that
square, not if *any* path has visited that square in the past.)

If your HW9 does not work out, don't worry, you can still work on this homework. 
After the late submission deadline for HW9 has passed, we will post a version of
`solver.c` that solves HW9 for your reference.

We have provided you with three published test mazes in the `testcases` directory (`maze1` to `maze3`).
You should write more tests of your own.

Beyond the three examples in the starter package, grading includes two additional hidden test cases. In total, the autograder runs 5 test cases for both correctness and Valgrind memory checks. The maze sizes for test cases range from 2x2 to 26x32. The last two hidden tests are larger and are tuned to run around 1 second each.

### Local testing workflow

Use the provided `Makefile` to run both correctness and memory checks on the 3 published cases:

1. `make test`
This compiles your program and runs `maze1` to `maze3`, comparing each result with the expected output.

2. `make memtest`
This compiles your program and runs `maze1` to `maze3` under `valgrind`.

3. `make clean`
This removes the executable, generated outputs, and valgrind logs.

### 3. What you need to submit

You only need to submit the following two source files:

1. `list.c`
2. `solver.c`

All other submitted files will be ignored by the autograder.

## Grading
The autograder total is 100 points:

1. Required files submitted correctly: 5 points
2. Program compiles correctly: 5 points
3. Correctness on five testcase outputs (equal weight per case): 60 points
4. Memory checks on the same five testcases (equal weight per case): 30 points
