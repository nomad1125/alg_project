/**
 *  Jarrett Tang
 *  generate_arrays.cpp
 */

#include "generate_arrays.h"

void generate_arrays(int **arrayInput)
{
  int col_counter = 10;
  int counter = 0;

  for (int i = 0; i < MAX_ROWS; i++)
  {
    for (int j = 0; j < col_counter; j++)
    {
      arrayInput[i][j] = counter;
      counter++;
    }
    col_counter = col_counter + 5;
  }
}
