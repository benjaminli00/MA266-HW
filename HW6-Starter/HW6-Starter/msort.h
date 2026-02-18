// ***
// *** DO NOT modify this file
// ***

#ifndef _MSORT_H
#define _MSORT_H

#include <stdlib.h>
#include "hw6.h"

void msort(Student * base, int nel, int (*compar)(const void *, const void *));
Student * merge(Student * base1, int nel1, Student * base2, int nel2, int (*compar)(const void *, const void *));
void copy(Student * to, Student * from, int nel);

#endif
