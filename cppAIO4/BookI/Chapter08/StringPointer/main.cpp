#include <iostream>

using namespace std;

int main()
{
  string GoodMovie;
  string *ptrToString;

  GoodMovie = "Best in Show";
  ptrToString = &GoodMovie;

  cout << *ptrToString << endl;

  *ptrToString = "Galaxy Quest";
  cout << GoodMovie << endl;
  return 0;
}
