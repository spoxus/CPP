#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main() {
  // Always set a seed value.
  srand((unsigned int)time(NULL));
  int RandomValue = rand() % 12;
  cout << "The random month number is: "
    << RandomValue + 1 << endl;
  return 0;
}
