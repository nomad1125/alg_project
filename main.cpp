/*
 *  Jarrett Tang (903482852)
 *  main.cpp
 */

 #include <iostream>
 #include <string>
 #include <fstream>
 #include <sstream>
 using namespace std;

// parts of this were sourced from old code which is based off of:
// https://www.uow.edu.au/~lukes/TEXTBOOK/notes-cpp/io/readtextfile.html
void read_file(int *inputArray) {
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

}

 int main() {
   int arrayX[10];
   read_file(arrayX);
   return 0;
 }
