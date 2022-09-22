#include <iostream>
#include <typeinfo>
#include <memory>
#include <cxxabi.h>

using namespace std;

string DemangleIt(const char* Mangled) {
  int Status;
  unique_ptr<char[], void(*)(void*)> Result(
    abi::__cxa_demangle(Mangled, 0, 0, &Status), free);
  return Result.get() ? string(Result.get()) : "Error";
}

void ShowType(function<float(double)> lambda) {
  cout << "Input has a value of: " << lambda(2.6) << endl;
  cout << "Input has type of: " <<
    DemangleIt(typeid(lambda(2.6)).name()) << endl;
}

void ShowChar(function<char(int)> lambda){
  cout << "Input has a value of: " << lambda(7) << endl;
}

int main() {
  ShowType([](int x) -> int {return int(x * x);});
  ShowType([](double x) -> int {return int(x * x);});
  ShowType([](double x) -> double {return x * x;});
  ShowType([](double x) {return float(x * x);});
  ShowType([](double x) {return x > 2 ? true : false;});
  ShowType([](int x) -> char {return char(x * 10);});
  ShowChar([](int x) -> char {return char(x * 10);});
  return 0;
}
