/**
 *  Jarrett Tang
 *  generate_arrays.cpp
 */

#include "generate_arrays.h"

void generate_arrays(int **arrayInput)
{
  int row_counter = 10;
  int counter = 0;

  for (int i = 0; i < MAX_COL; i++)
  {
    for (int j = 0; j < row_counter; j++)
    {
      arrayInput[j][i] = counter;
      counter++;
    }
    col_counter = col_counter + 5;
  }
}
