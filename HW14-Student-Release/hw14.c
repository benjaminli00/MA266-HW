#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> 
#include "huffman.h"

typedef struct {
   int count;
   unsigned char buffer;
} Buffer;

/* count the occurrences in a file */

long *countLetters(FILE *fp)
{
   long *asciiCount = (long *)malloc(sizeof(long)*ASCII_SIZE);
   if (asciiCount == NULL) {
      return NULL;
   }
   int ch;
   for (ch = 0; ch < ASCII_SIZE; ch++) {
      asciiCount[ch] = 0;
   }
   fseek(fp, 0, SEEK_SET);
   while ((ch = fgetc(fp)) != EOF) {
      asciiCount[ch] += 1;
   }
   return asciiCount;
}

void placeInList(ListNode * head, TreeNode * new, long count) {
   //don't need to check for alphabetical order
   ListNode * new_node = malloc(sizeof(ListNode));
   new_node->ptr = new;
   new_node->next = NULL;

   if(head->next == NULL) {
      head->next = new_node;
      return;
   }

   if(count < head->next->ptr->count) {
      new_node->next = head->next;
      head->next = new_node;
      return;
   }
   
   ListNode * temp = head->next;
   
   while(temp->next != NULL && count >= temp->next->ptr->count) {
      temp = temp->next;
   }

   if(temp->next != NULL) {
      new_node->next = temp->next;
   }

   temp->next = new_node;

   return;
}

ListNode * createOrderedList(long *asciiCount) {
   //at end, make head the next element and free current node
   ListNode * head = malloc(sizeof(ListNode));
   head->ptr = NULL;
   head->next = NULL;

   for(int i = 0; i < ASCII_SIZE; i++) {
      if(asciiCount[i] > 0) {
         TreeNode * leaf = malloc(sizeof(TreeNode));
         leaf->label = i;
         leaf->count = asciiCount[i];
         leaf->left = NULL;
         leaf->right = NULL;

         placeInList(head, leaf, leaf->count);
      }
   }

   ListNode * temp = head;

   head = head->next;
   free(temp);

   return head;   
}

void addToBuffer(int val, FILE * fp, Buffer * buff){
   buff->count++;

   buff->buffer = buff->buffer << 1;

   buff->buffer = (buff->buffer & ~1) | val;

   if(buff->count == 8) {
      buff->count = 0;
      fprintf(fp, "%c", buff->buffer);
   }

   return;
}

void printBits(int num, FILE * fp, Buffer * buff) {
   int total_bit = 8;

   for(int i = total_bit - 1; i >= 0; i--) {
      int bit = (num >> i) & 1;
      addToBuffer(bit, fp, buff);
   }

   return;
}

void writeHeader(TreeNode * tree, FILE * fp, Buffer * buff){
   //base case not a node
   if(tree == NULL) {
      return;
   }

   //base case leaf node
   if(isLeafNode(tree)){
      addToBuffer(1, fp, buff);
      printBits(tree->label, fp, buff);
      return;
   }

   //recursive case
   addToBuffer(0, fp, buff);
   writeHeader(tree->left, fp, buff);
   writeHeader(tree->right, fp, buff);

   return;
}


// You main function takes exactly four inputs
// argv[1]: input file name - for example, testcases/gophers
// argv[2]: output file 1 name - to store the sorted characters, for example, gophers_sorted
// argv[3]: output file 2 name - to store the huffman code of each characters, for example, gophers_huffman
// argv[4]: output file 3 name - to store the header information, for example, gophers_header
int main(int argc, char **argv)
{
   if (argc != 5) {
    printf("Not enough arguments");
    return EXIT_FAILURE;
   }
   FILE * inFile = fopen(argv[1], "r");
   if (inFile == NULL) {
      fprintf(stderr, "can't open the input file.  Quit.\n");
      return EXIT_FAILURE;
   }

   /* read and count the occurrences of characters */
   long *asciiCount = countLetters(inFile);
   fclose(inFile);

   if (asciiCount == NULL) {
      fprintf(stderr, "cannot allocate memory to count the characters in input file.  Quit.\n");
      return EXIT_FAILURE;
   }

   // Your code should go here
   //create ordered list
   ListNode * list = createOrderedList(asciiCount);

   //write sorted list to argv[2]
   FILE * sortedFile = fopen(argv[2], "w");
   if (sortedFile == NULL) {
      fprintf(stderr, "can't open sorted file.  Quit.\n");
      return EXIT_FAILURE;
   }

   printList(list, sortedFile);

   fclose(sortedFile);

   //make huffman tree
   TreeNode * huffman = buildHuffmanTree(list);

   //print tree
   FILE * treeFile = fopen(argv[3], "w");
   if (treeFile == NULL) {
      fprintf(stderr, "can't open tree file.  Quit.\n");
      return EXIT_FAILURE;
   }

   huffmanPrint(huffman, treeFile);

   fclose(treeFile);


   //make header from tree
   FILE * headerFile = fopen(argv[4], "w");
   if (headerFile == NULL) {
      fprintf(stderr, "can't open header file.  Quit.\n");
      return EXIT_FAILURE;
   }

   Buffer * buff = malloc(sizeof(Buffer));

   buff->count = 0;
   buff->buffer = 0;
   
   writeHeader(huffman, headerFile, buff);

   if(buff->count != 0) {
      buff->buffer = buff->buffer << (8 - buff->count);
      fprintf(headerFile, "%c", buff->buffer);
   }

   fclose(headerFile);
   
   //free
   freeHuffmanTree(huffman);
   free(buff);
   free(asciiCount);

   return EXIT_SUCCESS;
}
