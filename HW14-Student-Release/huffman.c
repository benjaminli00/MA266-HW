#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "huffman.h"

void traverseTreePrint(const TreeNode * tree, FILE * fp, char * code, int depth);

/* construct a new tree, with the new label, and left and right branches */
/* get the count from left and right for the new count                   */
TreeNode * buildTreeNode(int label, TreeNode * left, TreeNode * right){
    TreeNode * newTree = malloc(sizeof(TreeNode));

    newTree->label = label;
    newTree->count = left->count + right->count;
    newTree->left = left;
    newTree->right = right;

    return newTree;
}

/* destroy a tree, deallocating all memory associated with the tree      */

void freeHuffmanTree(TreeNode * ptr){
    if(ptr == NULL) return;

    freeHuffmanTree(ptr->left);
    freeHuffmanTree(ptr->right);

    free(ptr);
    return;
}

/* given a huffman coding tree, print the huffman code for each ASCII    */
/* symbol                                                                */
void huffmanPrint(const TreeNode * ptr, FILE * fp){
    char code[ASCII_SIZE];

    traverseTreePrint(ptr, fp, code, 0);
}

void traverseTreePrint(const TreeNode * tree, FILE * fp, char * code, int depth) {
    // base case: null
    if(tree == NULL) {
        return;
    }

    // base case: leaf
    // print code
    if(isLeafNode(tree)) {
        fprintf(fp, "%c:", tree->label);
        for(int i = 0; i < depth; i++) {
            fprintf(fp, "%c", code[i]);
        }
        fprintf(fp, "\n");
        return;
    }

    //left case
    code[depth] = '0';
    traverseTreePrint(tree->left, fp, code, depth + 1);

    //right case
    code[depth] = '1';
    traverseTreePrint(tree->right, fp, code, depth + 1);
}

/* is a given TreeNode a leaf node                                       */
int isLeafNode(const TreeNode * node){
    return node->left == NULL && node->right == NULL;
}

/* return the count of a TreeNode                                        */
long treeNodeCount(TreeNode * node){
    return node->count;
}

/* compare tree nodes based on the count
0: tp1 less than tp2, 1: tp1 more than tp2              */
int treeNodeCompare(TreeNode * tp1, TreeNode * tp2){
    if(treeNodeCount(tp1) >= treeNodeCount(tp2)) {
        return 1;
    }

    return 0;
}

/*build huffman tree for a given ListNode				 */
TreeNode * buildHuffmanTree(ListNode * list){
    if(list == NULL){
        return NULL;
    }

    //ListNode * lastNode;

    while(list->next != NULL){
        TreeNode * combineTree = buildTreeNode(126, list->ptr, list->next->ptr);
        addListNode(&list, combineTree, treeNodeCompare);

        free(removeListNode(&list));
        free(removeListNode(&list));
        //printf("new first node: label %c, count %ld\n", list->ptr->label, list->ptr->count);
    }

    // if(list->next != NULL) {
    //     TreeNode * combineTree = buildTreeNode(126, list->ptr, list->next->ptr);
    //     addListNode(&list, combineTree, treeNodeCompare);
    //     free(removeListNode(&list));
    //     free(removeListNode(&list));
    //     // printf("combined last 2\n");
    //     return combineTree;
    // }

    TreeNode * res = list->ptr;

    free(list);

    return res;
}

//place new treenode to list and delete first 2 elements. Returns ptr to new element
ListNode * addListNode(ListNode ** list, TreeNode * new_object, 
    int (*cmpFunction)(TreeNode *, TreeNode *)){
    
    ListNode * newNode = malloc(sizeof(ListNode));
    newNode->ptr = new_object;

    // if(!cmpFunction(new_object, (*list)->ptr)){
    //     newNode->next = *list;
    //     *list = newNode;

    //     return newNode;
    // }
    
    ListNode * temp = *list;
    
    while(temp->next != NULL && cmpFunction(new_object, temp->next->ptr)) {
        temp = temp->next;
    }

    if(temp->next != NULL) {
        newNode->next = temp->next;
    }

    temp->next = newNode;

    return newNode;        
}

//returns the list node to remove (doesn't actually remove node)
//moves start of list to next element
//only use when tree still exists
ListNode * removeListNode(ListNode ** list){
    if(list == NULL || *list == NULL) {
        return NULL;
    }

    ListNode * remove = *list;
    *list = (*list)->next;
    
    return remove;
}


/* destroy an entire linked list, freeing all memory used.                */
void freeList(ListNode * list){
    while(list != NULL) {
        freeHuffmanTree(list->ptr);

        ListNode * temp = list;
        list = list->next;
        free(temp);
    }

    return;
}

/* print an entire linked list, each element is just a leaf                                        */
void printList(const ListNode * list, FILE * fp){
    while(list != NULL) {
        fprintf(fp, "%c:%ld\n", list->ptr->label, list->ptr->count);
        list = list->next;
    }

    return;
}