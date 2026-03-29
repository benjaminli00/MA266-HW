// ***
// *** You MUST modify this file
// ***

#include "solver.h"
#include "list.h"
#include "mazehelper.h"
#include "path.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

PathLL* solveMaze(Maze* m) {

    PathLL* successPaths = buildPaths();
    char* retval = malloc(((m->height * m->width) + 1) * sizeof(char));

    MazePos mp = {.xpos = m->start.xpos, .ypos = m->start.ypos};
    depthFirstSolve(m, mp, retval, 0, successPaths);

    free(retval);

    return successPaths;
}

void depthFirstSolve(Maze* m, MazePos curpos, char* path, int step,
                     PathLL* successPaths) {

    // TODO (Your best bet is to modify a working implementation from HW9)
    
    //base case
	//false base case
	if(!squareOK(curpos, m)) {
		return;
	}

    // printf("step=%d, x=%d, y=%d\n", step, curpos.xpos, curpos.ypos);
    fflush(stdout);

	//true base case
	if(atEnd(curpos, m)) {
		path[step] = '\0';
        addNode(successPaths, path);
        // printf("Found successful path: %s\n", path);
		return;		
	}

	m->maze[curpos.ypos][curpos.xpos].visited = true;
	
	//recursive case
	//north
	MazePos northPos = {
		.xpos = curpos.xpos,
		.ypos = curpos.ypos - 1
	};
	path[step] = NORTH;

    depthFirstSolve(m, northPos, path, step + 1, successPaths);
	
	//south
	MazePos southPos = {
		.xpos = curpos.xpos,
		.ypos = curpos.ypos + 1
	};
	path[step] = SOUTH;

	depthFirstSolve(m, southPos, path, step + 1, successPaths);

	//east
	MazePos eastPos = {
		.xpos = curpos.xpos + 1,
		.ypos = curpos.ypos
	};
	path[step] = EAST;

	depthFirstSolve(m, eastPos, path, step + 1, successPaths);

	//west
	MazePos westPos = {
		.xpos = curpos.xpos - 1,
		.ypos = curpos.ypos
	};
	path[step] = WEST;

	depthFirstSolve(m, westPos, path, step + 1, successPaths);

    m->maze[curpos.ypos][curpos.xpos].visited = false;
    
	return;
}
