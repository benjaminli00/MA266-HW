#include "maze.h"
#include "path.h"
#include "solver.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    PathLL* paths = buildPaths();


    while(true) {
        char path[15];

        printf("\nPath to add (e to exit): ");
        scanf("%s", path);
        if(path[0] == 'e') {
            break;
        }

        addNode(paths, path);

        PathNode* curr = paths->head;
        int i = 0;
        while (curr != NULL) {
            printf("Path %2d: %s\n", i, curr->path);
            i++;
            curr = curr->next;
        }
    }

    freePaths(paths);

}