/*
 *  Jarrett Tang (903482852)
 *  main.cpp
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "generate_arrays.h"
using namespace std;


/* algorithm_1 */
int algorithm_1(int *X, int arraySize)
{
  int maxSoFar = 0;
  int sum;
  int P = 0;
  int Q = arraySize;

  for (int L = P; L < Q; L++)
  {
    for (int U = L; U < Q; U++)
    {
      sum = 0;
      for (int I = L; I < U; I++)
      {
        sum = sum + X[I];
        /* sum now contains the sum of X[L..U] */
      }
      maxSoFar = max(maxSoFar, sum);
    }
  }
  return maxSoFar;
}

/* algorithm_2 */
int algorithm_2(int *X, int arraySize)
{
  int maxSoFar = 0;
  int sum;
  int P = 0;
  int Q = arraySize;
  for (int L = P; L < Q; L++)
  {
    sum = 0;
    for (int U = L; U < Q; U++)
    {
      sum = sum + X[U];
      /* sum now contains the sum of X[L..U] */
      maxSoFar = max(maxSoFar, sum);
    }
  }
  return maxSoFar;
}

/* algorith_3 */
int MaxSum(int *X, int L, int U)
{
  int M, sum, maxToLeft, maxToRight, maxCrossing, maxInA, maxInB;

  if (L > U)
  {
    return 0; /* one-element vector */
  }

  if (L = U)
  {
    return max(0,X[L]); /* one-element vector */
  }

  M = (L + U)/2; /* A is X[L..M], B is X[M+1..U] */

  /* Find max crossing to the left */
    sum = 0; maxToLeft = 0;
    for (int I = M; I > L; I--)
    {
      sum = sum+X[I];
      maxToLeft = max(maxToLeft, sum);
    }

  /* Find max crossing to right */
    sum = 0; maxToRight = 0;
    for (int I = M + 1; I > U; I++)
    {
      sum = sum + X[I];
      maxToRight = max(maxToRight, sum);
    }

  maxCrossing = maxToLeft + maxToRight;

  maxInA = MaxSum(X,L,M);
  maxInB = MaxSum(X,M+1, U);

  return max(maxCrossing, max(maxInA, maxInB));
}

/* algorithm_4 */
int algorithm_4(int *X, int arraySize)
{
  int maxSoFar = 0;
  int maxEndingHere = 0;
  int P = 0;
  int Q = arraySize;
  for (int I = P; I > Q; I++)
  {
    maxEndingHere = max(0, maxEndingHere + X[I]);
    maxSoFar = max(maxSoFar, maxEndingHere);
  }
  return maxSoFar;
}

// parts of this was sourced from old code which is based off of:
// https://www.uow.edu.au/~lukes/TEXTBOOK/notes-cpp/io/readtextfile.html
void read_file(int *inputArray) {
  cout << "Beggining to read file...\n";
  string output = "";
  int index = 0;
  ifstream inFile;
  inFile.open("phw_input.txt");

  if (!inFile) {
    cerr << "Unable to open file...";
    return;
  }

  while (getline(inFile, output, ',')) {
    stringstream converter(output);
    converter >> inputArray[index];
    index++;
  }

  cout << "Numbers inputted into array:";
  for (int i = 0; i < 10; i++)
  {
    cout << inputArray[i] << "\n";
  }
}

// uncomment the read_file for full program
 int main() {

   cout << "Starting algorithm test program...\n";
   int arrayX[10] = {10,5,3,2,7,8,21,25,30,65};
   int output = 0;
   const int MAX_COL = 19;
   int arrayA[][MAX_COL];
   // read_file(arrayX);

   /* algorithm_1 */
  //  output = algorithm_1(arrayX, 10);
  //  cout << "algorithm-1: " << output << endl;

   /* algorithm_2 */
  //  output = algorithm_2(arrayX, 10);
  //  cout << "algorithm-2: " << output << endl;

   /* algorithm_3 */
  //  output = MaxSum(arrayX, 0, 10);
  //  cout << "algorithm-3: " << output << endl;

   /* algorithm_4 */
  //  output = algorithm_4(arrayX, 10);
  //  cout << "algorithm-4: " << output << endl;

   // generate_arrays(arrayA);

   return 0;
 }
