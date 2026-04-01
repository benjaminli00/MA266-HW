// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

int indexOf(int * arr, int value, int size);
TreeNode * buildRecurse(int * inArray, int * postArray, int size);
TreeNode * createNode(int val);

// DO NOT MODIFY FROM HERE --->>>
void deleteTreeNode(TreeNode * tr)
{
  if (tr == NULL)
    {
      return;
    }
  deleteTreeNode (tr -> left);
  deleteTreeNode (tr -> right);
  free (tr);
}

void freeTree(Tree * tr)
{
  if (tr == NULL)
    {
      // nothing to delete
      return;
    }
  deleteTreeNode (tr -> root);
  free (tr);
}

static void preOrderTraversal(TreeNode * tn, FILE * fptr)
{
  if (tn == NULL)
    {
      return;
    }
  fprintf(fptr, "%d\n", tn -> value);
  preOrderTraversal(tn -> left, fptr);
  preOrderTraversal(tn -> right, fptr);
}

void preOrderToFile(Tree * tr, char * filename)
{
  if (tr == NULL)
    {
      return;
    }
  FILE * fptr = fopen(filename, "w");
  preOrderTraversal(tr -> root, fptr);
  fclose (fptr);
}
// <<<--- UNTIL HERE

// ***
// *** You MUST modify the follow function
// ***

#ifdef TEST_BUILDTREE
// Consider the algorithm posted on
// https://www.geeksforgeeks.org/construct-a-binary-tree-from-postorder-and-inorder/
// Feel free to add helper functions
// inArray: an integer array containing the in-order traversal output
// postArray: an integer array containing the post-order traversal output
// size: number of integers in inArray or postArray
Tree * buildTree(int * inArray, int * postArray, int size)
{
  Tree * tree = malloc(sizeof(Tree));

  tree->root = buildRecurse(inArray, postArray, size);
  
  return tree;
}
#endif

int indexOf(int * arr, int value, int size) {
  for(int i = 0; i < size; i++) {
    if(arr[i] == value) {
      return i;
    }
  }
  
  return -1;
}

TreeNode * buildRecurse(int * inArray, int * postArray, int size) {
  if(size <= 0) {
    return NULL;
  }

  int headVal = postArray[size - 1];
  TreeNode * head = createNode(headVal);

  if(size == 1) {
    return head;
  }

  int splitI = indexOf(inArray, headVal, size);

  if(splitI == -1) {
    printf("failed to find value in array: %d\n", headVal);
    return NULL;
  }

  TreeNode * leftTree = buildRecurse(inArray, postArray, splitI);

  TreeNode * rightTree = buildRecurse(&inArray[splitI + 1], &postArray[splitI], size - splitI - 1);

  head->left = leftTree;
  head->right = rightTree;

  return head;
}

TreeNode * createNode(int val) {
  TreeNode * res = malloc(sizeof(TreeNode));

  res->left = NULL;
  res->right = NULL;
  res->value = val;

  return res;
}