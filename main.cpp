/*
 *  Jarrett Tang (903482852)
 *  main.cpp
 */

 #include <iostream>
 #include <string>
 #include <fstream>
 using namespace std;

// parts of this were sourced from old code which is based off of:
// https://www.uow.edu.au/~lukes/TEXTBOOK/notes-cpp/io/readtextfile.html
void read_file(int *inputArray) {
  string output = "";
  int index = 0;
  ifstream inFile("phw_input.txt");
  inFile.open(filename)

  if (!inFile) {
    cerr << "Unable to open file...";
    exit(1);
  }

  while (getline(inFile, output, ',')) {
    inputArray[index] = stoi(output);
  }

}

 int main() {
   int arrayX[10];
 }
