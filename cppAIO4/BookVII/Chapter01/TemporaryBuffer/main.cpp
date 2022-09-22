#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

int main() {
  vector<string> Words;
  Words.push_back("Blue");
  Words.push_back("Green");
  Words.push_back("Teal");
  Words.push_back("Brick");

  int Count = Words.size();
  cout << "Words contains: " << Count << " elements."
    << endl;

  // Create the buffer and copy the data to it.
  pair<string*, ptrdiff_t> Mem =
    get_temporary_buffer<string>(Count);
  uninitialized_copy(Words.begin(), Words.end(),
                     Mem.first);

  // Perform a sort and display the results.
  sort(Mem.first, Mem.first+Mem.second);
  for (int i = 0; i < Mem.second; i++)
      cout << Mem.first[i] << endl;

  // Show that the original list is unchanged.
  cout << "\nShowing Words Hasn't Changed" << endl;
  for (int i = 0; i < Count; i++)
    cout << Words[i] << endl;
  return 0;
}
