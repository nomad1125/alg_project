/*
 *  Jarrett Tang (903482852)
 *  main.cpp
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <chrono>

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

  if (L == U)
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
  for (int I = P; I < Q; I++)
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
/**
 *  source of multi dimensional array research:
 *  https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new
 */
 int main()
 {
   cout << "Starting algorithm test program...\n";
   int arrayX[10] = {10,5,3,2,7,8,21,23,30,6};
   int output = 0;

   // read_file(arrayX);

   /* algorithm_1 */
   output = algorithm_1(arrayX, 10);
   cout << "algorithm-1: " << output << endl;

   /* algorithm_2 */
   output = algorithm_2(arrayX, 10);
   cout << "algorithm-2: " << output << endl;

   /* algorithm_3 */
   output = MaxSum(arrayX, 0, 10);
   cout << "algorithm-3: " << output << endl;

   /* algorithm_4 */
   output = algorithm_4(arrayX, 10);
   cout << "algorithm-4: " << output << endl;

  /* Start step 6 */
  const int MAX_ROW = 19;
  int colCount = 10;
  int **arrayA = new int*[MAX_ROW];
  srand (time(NULL));

  /* creates array */
  for (int i = 0; i < MAX_ROW; i++)
  {
    arrayA[i] = new int[colCount];
    colCount = colCount + 5;
  }
  colCount = 10;  // reset colCount

  /* fills array */
  for (int i = 0; i < MAX_ROW; i++)
  {
    for (int j = 0; j < colCount; j++)
    {
      arrayA[i][j] = rand() % 2147483648 + (-2147483647);
    }
  }
  colCount = 10; //reset

  /**
   *  step 7
   *  source for elapsed time:
   *  https://www.pluralsight.com/blog/software-development/how-to-measure-execution-time-intervals-in-c--
   */
  double timeMatrix[19][8];
  double maxTime = 0;

  /*
   *  step 7: algorithm_1
   */
  for (int i = 0; i < MAX_ROW; i++)
  {
    for (int N = 0; N < 1000; N++)
    {
      // Record start time
      auto start = std::chrono::high_resolution_clock::now();
      for (int j = 0; j < colCount; j++)
      {
        /* algorithm_1 */
        output = algorithm_1(arrayA[i], colCount);
      }
      // Record end time
      auto finish = std::chrono::high_resolution_clock::now();
      std::chrono::duration<double> t1 = finish - start;
      timeMatrix[i][0] = timeMatrix[i][0] + t1.count(); //time in secs
      if (maxTime < t1.count())
      {
        maxTime = t1.count();
      }

      colCount = colCount + 5; //reset
    }
    timeMatrix[i][0] = timeMatrix[i][0] / 1000; // t1
    timeMatrix[i][4] = maxTime; // t4
    maxTime = 0; // reset
    cout << "algorithm-1 row " << i << " run time average:\t" << timeMatrix[i][0]
      << endl;
    cout << "algorithm-1 row " << i << " max run time:  \t" << timeMatrix[i][4]
      << endl;
  }
  colCount = 10; // reset

  return 0;
 }
