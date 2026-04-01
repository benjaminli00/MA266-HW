# Homework 12: Building a Binary Tree
    _________[!!Victory!!]________
            /                    \
        _[0]                 _____[1]
       /                    /         \
    [00]                _[10]           [11]
                      /     \
                   [100]       [101]

## Goals

This assignment is the first part of two assignments. You need to implement the algorithms
for building and traversing binary trees. This part (HW12) asks you to build a 
binary tree. For the next part (HW13) you will implement the function for traversal of
a binary tree. Please read both Part 1 (HW12) and Part 2 (HW13) before you start.

You will learn to
* Understand binary tree and binary search tree
* Traverse binary trees using pre-order, in-order, and post-order 
* Construct binary trees from in-order and post-order traversal outputs
* Validate if the constructed binary tree is a binary search tree


## Background

### 1. Connection between Part 1 and Part 2

In Part 1 (HW12), you'll implement functions for building a binary tree based on 
the in-order and and post-order traversal outputs. In Part 2 (HW13), you'll implment
functions to print the path from a node to the root of the built binary tree. You'll reuse
your code of Part 1 (HW12) when you work on Part 2 (HW13). Thus, please read both
Part 1 and Part 2 before you start.

Your Part 1's score will be at least 50% of the Part 2's score. 
Thus, if you do well in Part 2, you may get some points back for Part 1,
even though your original score for Part 1 may be low.

### 2. Binary Search Tree

A binary tree means each node has at most two children using two
pointers. If a child does not exist, the pointer points to `NULL`.  If
a node has no child (i.e., both pointers point to `NULL`), this is
called a *leaf node*.

There are several commonly used methods to visit every node
in a binary tree: they are called *pre-order*, *in-order*, and
*post-order* traversal. Given the outputs of pre-order and in-order (or
post-order and in-order), it possible to *uniquely* construct a binary
tree. 

> **Note:** It is not possible to **uniquely** construct a
binary tree from pre-order and post-order. You may think of why and try to
give a counter example. :)

**Validating if a binary tree is a binary search tree:** 
A binary tree is a *binary search tree* if the value stored in a node
is greater than the values stored in *every* node on its left **subtree** and
smaller than the values stored in *every* node on its right **subtree**.
This rule must be true for every node.

> **Note:** If we have a binary tree, where for every node, the stored value is
greater than the value stored in its left **child** and
smaller than the value stored in its right **child**, then this does NOT ensure a binary search tree.
For example, if a node's value is greater than the value stored in the
left child, it possible that the value in a grand child of the left
child is greater and this is not a binary search tree.

### 3. Construct a Binary Tree from In-Order and Post-Order

This assignment asks you to construct a binary tree from in-order and
post-order traversal outputs. The constructed binary tree should be a binary
search tree. Thus, you can validate your program by checking whether
it creates a binary search tree.

The method explained below is inspired by [this website] (https://www.geeksforgeeks.org/construct-a-binary-tree-from-postorder-and-inorder/).

#### Example 1:
Consider two input arrays with the outputs of in-order and post-order:

* in-order: [6, 7, 8]

* post-order: [7, 6, 8]

Since the root is always the **last** node in the output of post-order traversal,
8 must be the root of the entire tree. 
Since 8 is the last element in the in-order traversal, then the root has no right child.
Both 6 and 7 are on the left side.

Next, consider the post-order of these two numbers: 6 is after 7
in post-order so 6 must be the left child of 8 (i.e., the root of the left subtree) 
and 7 is the right child of 6. 

Thus, the pre-order ouput of this binary tree is [8, 6, 7].

#### Example 2:

Let's consider a more complex example:

* in-order: [2, 5, 6, 8, 10]

* post-order: [5, 2, 10, 8, 6]

From the last value in post-order, 6 is the root.
Then considering the location of 6 in the in-order output, we can
divide the remaining numbers into two arrays for the left and the right sides of
the root:

Left

* in-order: [2, 5]

* post-order: [5, 2]

Right

* in-order: [8, 10]

* post-order: [10, 8]

For the left side, 2 is the root (since 2 is the last node in the post-order output for
the left side) and 5 is the right child of 2.

Similarly, for the right side, 8 is the root and 10 is the right child of 8.


Thus, the pre-order output of this binary tree is [6, 2, 5, 8, 10].

> **Note:** You may note that for the two examples above, the in-order traversal outputs
are always in the ascending order. This is because the binary trees in the two examples above
are also binary search trees. The in-order traversal outputs for a binary search tree are
**always** in the ascending order, since for every node, the smaller values (on its left side) are
printed before the node, and the larger values (on its right side) are printed after the node.

For this assignment, you may assume that the inputs are valid: the
in-order and the post-order are from the same binary search tree.

## What do you need to do?

You'll need to change one file `tree.c`.

Inside `tree.c`, you'll implment the function `Tree * buildTree(int * inArray, int * postArray, int size)`.
This `buildTree` function takes the in-order and post-order traversal as input and build a binary tree 
based on it.

There are 6 test cases provided to you in the `testcases` directory. The corresponding pre-order outputs for the
6 test cases are in the `expected` directory.

### 1. How to test your code

You may notice from the `main` function in `main.c` that your program requires three inputs:
```
argv[1]: input file name for in-order traversal
argv[2]: input file name for post-order traversal
argv[3]: output file name for pre-order traversal
```

Thus, suppose your executable file is named `hw12`, you may run your the program with the following command:
```
./hw12 testcases/test1in testcases/test1post output1
```

You may further use the `diff` command to compare your output with the expected output in the  `expected` directory.

Remember to use `valgrind` to check memory. 

## Grading
You will lose 1 point for every 1 byte of memory leak. In other words, if your program leaks 100 or more bytes, you will **receive zero**.

## Submission
Make sure to submit only the following files:
1. `tree.c`
