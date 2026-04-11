// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tree.h"

int indexOf(int * arr, int value, int size);
TreeNode * buildRecurse(int * inArray, int * postArray, int size);
TreeNode * createNode(int val);

bool isOnPath(TreeNode * tr, int val);

// DO NOT MODIFY FROM HERE --->>>
Tree * newTree(void)
{
  Tree * t = malloc(sizeof(Tree));
  t -> root = NULL;
  return t;
}

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


// <<<--- UNTIL HERE

// ***
// *** You MUST modify the follow function
// ***
#ifdef TEST_BUILDTREE
Tree * buildTree(int * inArray, int * postArray, int size)
{
  Tree * tree = malloc(sizeof(Tree));

  tree->root = buildRecurse(inArray, postArray, size);
  
  return tree;
}

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
#endif

#ifdef TEST_PRINTPATH
void printPath(Tree * tr, int val)
{

  TreeNode * root = tr->root;
  isOnPath(root, val);
  printf("\n");
}

bool isOnPath(TreeNode * tr, int val) {
  if(tr->value == val) {
    printf("%d ", tr->value);
    return true;
  }

  if(tr->left != NULL && isOnPath(tr->left, val)) {
    printf("%d ", tr->value);
    return true;
  }

  if(tr->right != NULL && isOnPath(tr->right, val)) {
    printf("%d ", tr->value);
    return true;
  }

  return false;
}
#endif
