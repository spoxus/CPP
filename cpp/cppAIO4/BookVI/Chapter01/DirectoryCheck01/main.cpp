#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ofstream outfile("/abc/def/ghi/MyFile.txt");
  if (outfile.fail()) {
    cerr << "Couldn't open the file!" << endl;
    return -1;
  }
  outfile << "Hi" << endl;
  outfile.close();
  return 0;
}
