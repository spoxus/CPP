#include <iostream>
#include <memory>

using namespace std;

int main()
{
  int myValue = 42;
  shared_ptr<int> ptr1(new int(myValue));
  cout << "ptr1 value: " << *ptr1 << endl;
  cout << "ptr1 use count: " << ptr1.use_count()
    << endl;

  shared_ptr<int> ptr2 = ptr1;
  cout << "ptr2 value: " << *ptr2 << endl;
  cout << "ptr1 address: " << ptr1;
  cout << " ptr2 address: " << ptr2 << endl;
  cout << "ptr1 use count: " << ptr1.use_count()
    << endl;

  ptr2.reset();
  cout << "ptr1 use count: " << ptr1.use_count()
    << endl;

  ptr1.reset();
  cout << "ptr1 use count: " << ptr1.use_count()
    << endl;

  return 0;
}
