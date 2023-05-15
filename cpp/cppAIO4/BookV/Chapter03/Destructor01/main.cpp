#include <iostream>

using namespace std;

class LittleInst {
public:
  int MyNumber;
  ~LittleInst() { cout << MyNumber << endl; }
};

class Container {
public:
  LittleInst first;
  LittleInst *second;
  Container();
};

Container::Container() {
  first.MyNumber = 1;
  second = new LittleInst;
  second->MyNumber = 2;
}

int main() {
  Container *inst = new Container;
  delete inst;
  return 0;
}
