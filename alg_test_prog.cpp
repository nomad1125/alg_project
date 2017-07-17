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
  cout << "Beggining to read file...\n";
  string output = "";
  int index = 0;
  ifstream inFile;
  inFile.open("sample.txt");

  if (!inFile) {
    cerr << "Unable to open file...";
    return;
  }

  while (getline(inFile, output, ',')) {
    stringstream converter(output);
    converter >> inputArray[index];
    index++;
  }

  for (int i = 0; i <=10; i++)
  {
    cout << inputArray[i] << "\n";
  }

}

 int main() {
   cout << "Starting algorithm test program...\n";
   int arrayX[10];
   read_file(arrayX);
   return 0;
 }
