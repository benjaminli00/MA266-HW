// ***
// *** You MUST modify this file
// ***
#include <stdio.h>
#include <stdbool.h>
#include "hw4.h"

// must enclose the function by #ifdef TEST_INTEGRATE and #endif
#ifdef TEST_INTEGRATE
void integrate(Integration * intrg)
{
  // integrate the function stored in intrg's func
  // store the result in intrg's answer

  double width = intrg->upperlimit - intrg->lowerlimit;
  double sectionWidth = width / intrg->intervals;
  double sum = 0;

  for(int i = 0; i < intrg->intervals; i++)
  {
    sum += intrg->func(intrg->lowerlimit + i * sectionWidth) * sectionWidth;
  }
  
  intrg->answer = sum;
}
#endif // TEST_INTEGRATE

// must enclose the function by #ifdef RUN_INTEGRATE and #endif
#ifdef RUN_INTEGRATE
bool  runIntegrate(char * infilename, char * outfilename)
// return true if it can successfully open and read the input 
// and open and write the output
// return false when encountering any problem
{
  // open the input file name for reading
  FILE *fp;
  fp = fopen(infilename, "r");
  Integration intrg;

  // if fopen fails, return false

  if(fp == NULL)
  {
    return false;
  }

  // read one double from the input file and store it in 
  // intrg's lowerlimit
  // use fscanf
  // check the return value. If the return value is not one
  // close the file and return false

  int test  = fscanf(fp, "%lf\n", &intrg.lowerlimit);

  if(test != 1)
  {
    fclose(fp);
    return false;
  }

  // read one double from the input file and store it in 
  // intrg's upperlimit
  // use fscanf
  // check the return value. If the return value is not one
  // close the file and return false

  test = fscanf(fp, "%lf\n", &intrg.upperlimit);

  if(test != 1)
  {
    fclose(fp);
    return false;
  }

    // read one int from the input file and store it in 
  // intrg's intervals
  // use fscanf
  // check the return value. If the return value is not one
  // close the file and return false

  test = fscanf(fp, "%d\n", &intrg.intervals);

  if(test != 1)
  {
    fclose(fp);
    return false;
  }

  // close the input file

  fclose(fp);

  // open the output file for writing
  // if fopen fails, return false

  fp = fopen(outfilename, "w");

  if(fp == NULL)
  {
    return false;
  }

  // create an array of funcptr called funcs with five elements:
  // func1, func2, ..., func5

  funcptr funcs[5] = {func1, func2, func3, func4, func5};

  // go through the elements in funcs 
  // for each element, call integrate for that function
  // write the result (stored in intrg's answer to 
  // the output file. each answer occupies one line (add "\n")
  // use fprintf

  for(int i = 0; i < 5; i++)
  {
    intrg.func = funcs[i];
    integrate(&intrg);

    test = fprintf(fp, "%lf\n", intrg.answer);

  // check the return value of fprintf. 
  // If it is less one one, close the output
  // file and return false

    if(test < 1)
    {
      fclose(fp);
      
      return false;
    }

  }

  // after going through all functions in funcs
  // close the output file

  fclose(fp);

  // if the function reaches here, return true

  return true;
}
#endif // RUN_INTEGRATE
