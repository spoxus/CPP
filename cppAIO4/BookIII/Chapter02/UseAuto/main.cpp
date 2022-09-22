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

void ShowData(auto lambda){
  cout << "Input has a value of: " << lambda(3.6) << endl;
  cout << "Input has type of: " <<
    DemangleIt(typeid(lambda(3.6)).name()) << endl;
}

int main() {
  ShowData([](int x) -> int {return int(x * x);});
  ShowData([](double x) -> int {return int(x * x);});
  ShowData([](double x) -> double {return x * x;});
  ShowData([](double x) {return float(x * x);});
  ShowData([](double x) {return x > 2 ? true : false;});
  ShowData([](double x) -> char {return char(x * 10);});

  return 0;
}
