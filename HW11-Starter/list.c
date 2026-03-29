// ***
// *** You MUST modify this file
// ***

#include "list.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countTurns(char*);
bool alphabeticallyBefore(char*, char*);

/** INTERFACE FUNCTIONS **/

PathLL* buildPaths() {
    PathLL* retval = malloc(sizeof(PathLL));
    retval->head = NULL;
    return retval;
}

// Read the comments in list.h to understand what you need to implement
// for each function.
// Remember to check for memory leak.

void freePaths(PathLL* p) {
    // Remove all nodes from a linked list, deallocate the PathLL structure.
    // TODO
    PathNode * ptr = p->head;

    while(ptr != NULL) {
        PathNode * temp = ptr->next;
        freeNode(ptr);
        ptr = temp;
    }

    free(p);
}

PathNode* buildNode(char* path) {
    // Allocate a new PathNode with path as its data, return the address.

    // WARNING: don't forget to use strcpy to copy path into the new node.
    // Don't just set them equal, otherwise if the input path changes the node
    // will have the wrong path.

    // TODO
    PathNode * res = malloc(sizeof(PathNode));

    if(res == NULL) {
        return NULL;
    }

    res->path = malloc(sizeof(char) * (strlen(path) + 1));
    strcpy(res->path, path);
    res->next = NULL;

    return res;
}

void freeNode(PathNode* p) {
    // Deallocate a pathNode
    // TODO

    free(p->path);
    free(p);
}

bool addNode(PathLL* paths, char* path) {
    // Add a path to the list of paths
    // TODO

    PathNode * newNode = buildNode(path);

    if(newNode == NULL) {
        return false;
    }

    PathNode * currPathNode = paths->head;

    if(currPathNode == NULL) {
        paths->head = newNode;
        return true;
    }

    int newTurns = countTurns(path);
    int newLen = strlen(path);

    //missing logic for when to add node to first element
    if( (strlen(currPathNode->path) > newLen) || 
        (countTurns(currPathNode->path) > newTurns && strlen(currPathNode->path) == newLen) ||
        (!alphabeticallyBefore(currPathNode->path, path) && countTurns(currPathNode->path) == newTurns && strlen(currPathNode->path) == newLen)) {
        newNode->next = currPathNode;
        paths->head = newNode;
        return true;
    }

    //sort by length, shortest first
    while(currPathNode->next != NULL) {
        if(strlen(currPathNode->next->path) > newLen) break;
        if(strlen(currPathNode->next->path) == newLen && countTurns(currPathNode->next->path) > newTurns) break;
        if(strlen(currPathNode->next->path) == newLen && countTurns(currPathNode->next->path) == newTurns && !alphabeticallyBefore(currPathNode->next->path, path)) break;

        currPathNode = currPathNode->next;
    }
    if(currPathNode->next == NULL) {
        currPathNode->next = newNode;
        return true;
    }    

    newNode->next = currPathNode->next;
    currPathNode->next = newNode;

    return true;
}

int countTurns(char* path) {
    int count = 0;
    int i = 0;
    while(path[i + 1] != '\0') {
        if (path[i] != path[i+1]) count++;
        i++;
    }

    return count;
}

bool alphabeticallyBefore(char* path1, char* path2) {
    int i = 0;

    while(path1[i] != '\0' && path2[i] != '\0'){
        if(path1[i] < path2[i]) {
            return true;
        }
        if(path1[i] > path2[i]) {
            return false;
        }

        i++;
    }

    if(path1[i] == '\0'){
        return true;
    }
    else {
        return false;
    }
}

bool removeNode(PathLL* paths, char* path) {
    // Remove a node from the list with the specified path
    // TODO

    PathNode * nd = paths->head;

    if(strcmp(path, nd->path) == 0) {
        paths->head = nd->next;
        freeNode(nd);
        return true;
    }

    PathNode * prev = nd;
    nd = nd->next;

    while(nd != NULL) {
        if(strcmp(path, nd->path) == 0) {
            prev->next = nd->next;
            freeNode(nd);
            return true;
        }
        prev = nd;
        nd = nd->next;
    }

    return false;
}

bool containsNode(PathLL* paths, char* path) {
    // Return true if path exists in the list
    // TODO

    PathNode * nd = paths->head;

    while(nd != NULL) {
        if(strcmp(path, nd->path) == 0) {
            return true;
        }

        nd = nd->next;
    }

    return false;
}

void printPaths(PathLL* paths, FILE* fptr) {
    PathNode* curr = paths->head;
    int i = 0;
    while (curr != NULL) {
        fprintf(fptr, "Path %2d: %s\n", i, curr->path);
        i++;
        curr = curr->next;
    }
}
