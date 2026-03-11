// ***
// *** You MUST modify this file
// ***

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "solver.h"
#include "path.h"
#include "mazehelper.h"
#include "maze.h"

char * solveMaze(Maze * m) {
    //An obvious upper bound on the size of the solution path is the number
    //of squares in the maze + 1 (to account for the '\0'). You could make
    //this a tighter bound by accounting for how many walls there are, but
    //this approach is good enough!
	char * retval = malloc(sizeof(char) * ((m->width * m->height) + 1));

	MazePos mp = {.xpos = m->start.xpos, .ypos = m->start.ypos};
	if (!depthFirstSolve(m, mp, retval, 0)) {
		free(retval);
		return NULL;
		fprintf(stderr, "No solution found!\n");
	} else {
		printf("Solution found: %s\n", retval);
	}
	
	return retval;
}

bool depthFirstSolve(Maze * m, MazePos curpos, char * path, int step) {
	
	//FILL IN YOUR CODE HERE

	//base case
	//true base case
	if(atEnd(curpos, m)) {
		path[step] = '\0';
		return true;		
	}
	//false base case
	if(!squareOK(curpos, m)) {
		return false;
	}

	m->maze[curpos.ypos][curpos.xpos].visited = true;
	
	//recursive case
	//north
	MazePos northPos = {
		.xpos = curpos.xpos,
		.ypos = curpos.ypos - 1
	};
	path[step] = NORTH;

	if(depthFirstSolve(m, northPos, path, step + 1)) {
		return true;
	}
	
	//south
	MazePos southPos = {
		.xpos = curpos.xpos,
		.ypos = curpos.ypos + 1
	};
	path[step] = SOUTH;

	if(depthFirstSolve(m, southPos, path, step + 1)) {
		return true;
	}

	//east
	MazePos eastPos = {
		.xpos = curpos.xpos + 1,
		.ypos = curpos.ypos
	};
	path[step] = EAST;

	if (depthFirstSolve(m, eastPos, path, step + 1)) {
		return true;
	}

	//west
	MazePos westPos = {
		.xpos = curpos.xpos - 1,
		.ypos = curpos.ypos
	};
	path[step] = WEST;

	if (depthFirstSolve(m, westPos, path, step + 1)) {
		return true;
	}

	return false;
}

