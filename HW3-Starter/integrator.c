/* YOU MUST MODIFY THIS FILE */
// Read "hw3.h" to learn about the two data types: `Range` and `RangeAnswer`

#include "hw3.h"

double integrate1(Range rng)
{
  
  /* Fill in for Part 1 */
  // calculate the numerical integration of the function func
  // based on the three attributes (`lowerlimit`, `upperlimit`, and `intervals`) of the type `Range`.
  // the return value of function `integrate1` should be the numerical integration (return type is double)
  
  double width = rng.upperlimit - rng.lowerlimit;
  double sectionWidth = width / rng.intervals;
  double sum = 0;

  for(int i = 0; i < rng.intervals; i++)
  {
    sum += func(rng.lowerlimit + i * sectionWidth) * sectionWidth;
  }

  return sum;
}

void integrate2(RangeAnswer * rngans)
{
  /* Fill in for Part 2 */
  // run `integrate1` function
  // take the return value from `integrate1` function 
  // and assign it to attribute `answer` of the type `RangeAnswer`

  double val = integrate1(rngans->rng);

  rngans->answer = val;
}
