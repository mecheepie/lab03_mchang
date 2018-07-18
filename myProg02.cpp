// countDucks.cpp 
// P. Conrad for CS16, Winter 2015
// Example program to read from file and count occurences

#include <iostream> // for printf()
#include <cstdlib> // for exit(), perror()
#include <fstream> // for ifstream

using namespace std;

int ducks = 0;
int animals =-1;
int nonducks = 0;

int main(int argc, char *argv[])
{
  if (argc!=2) {
    // if argc is not 2, print an error message and exit
    cerr << "Usage: "<< argv[0] << " inputFile" << endl;
    exit(1); // defined in cstdlib
  }

ifstream in;
	in.open(argv[1]);
	string line = "";
	
	if (in.fail()) { // checks if reading the file failed…
		cerr << "Opening file failed" << endl;
		return 0;
	}


	while (!in.eof()) { // checks if we reached the end of file or not
		getline(in, line); // returns the entire line
		animals++;
		if (line == "duck") {
			ducks++;
		}
		if (line != "duck") {
			nonducks++;
		}
	}
	in.close();
  

  cout << "Report for " << argv[1] << ":" << endl;
  cout << "   Animal count:    " << animals << endl;
  cout << "   Duck count:      " << ducks << endl;
  cout << "   Non duck count:  " << nonducks << endl;
  cout << endl;  
return 0;
}
