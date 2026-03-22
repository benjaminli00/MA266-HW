// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h>
#include "hw10.h"

// DO NOT MODIFY this function --->>>
void printListNode(ListNode * head)
{
  ListNode * p = head;
  printf("printListNode: ");
  while (p != NULL) // the linked list must end with NULL
    {
      printf("%7d ", p -> value);
      p = p -> next;
    }
  printf("\n");
}
// <<<--- until here

// You MUST modify the following functions

#ifdef TEST_CREATELIST
// create a linked list storing values 0, 1, 2, ... valn - 1
// The first node (head) stores 0, the next node stores 1,
// ..., the last node stores valn - 1
// return the head of the linked listn
// the linked list must end with NULL
ListNode * createList(int valn)
{
  ListNode * head = NULL;
  while(valn > 0) {
    ListNode * newHead = NULL;
    newHead = malloc(sizeof(ListNode));

    newHead->next = head;
    newHead->value = --valn;
    
    head = newHead;
  }

  return head;
}
#endif

#ifdef TEST_ELIMINATE
// eliminate the nodes in the linked list
// starting from the head, move one node at a time and count to valk.
// eliminate that node, keep counting
//
// when reaching the end of the list, continue from the beginning of
// the list
//
// print the values of the nodes to be deleted
void eliminate(ListNode * head, int valk)
{
  ListNode * nd = head;
  ListNode * prev = NULL;
  while(head != NULL) {
    for(int i = 0; i < valk - 1; i++)
    {
      prev = nd;
      nd = nd->next;
      if(nd == NULL){
        nd = head;
        prev = NULL;
      }
    }

    ListNode * p = nd;

#ifdef DEBUG
  // this #ifdef ... #endif should be inside the condition *BEFORE* a
  // node' value is printed and it is deleted
    ListNode * todelete = p;
    printListNode (todelete); 
#endif

    printf("%d\n", p->value);

    if(prev == NULL) {
      head = nd->next;
    } else {
      prev->next = nd->next;
    }

    nd = p->next == NULL ? head : p->next;
    prev = NULL;
    free(p);
  }
}
#endif

#ifdef TEST_DELETENODE
// head points to the first node in the linked list
// todelete points  to the node to be deleted
//
// delete the node and return the head of the linked list
// release the memory of the deleted node
//
// should check several conditions:
// 1. If head is NULL, the list is empty and this function returns NULL
// 2. If todelete is NULL, nothing can be deleted, return head
// 3. If todelete is not in the list, keep the list unchanged and
//    return head
// It is possible that todelete is the first node in the list (i.e.,
// the head). If this occurs, return the second node of the list.
ListNode * deleteNode(ListNode * head, ListNode * todelete)
{
  if(head == NULL) {
    return NULL;
  }
  if(todelete == NULL) {
    return NULL;
  }
  if(head == todelete) {
    return head->next;
  }

  ListNode * curr = head->next;
  ListNode * prev = head;

  while(curr != todelete && curr != NULL) {
    curr = curr->next;
    prev = prev->next;
  }

  if(curr == todelete) {
    prev->next = curr->next;
    free(curr);
  }

  return head;
}
#endif


