import hello;
int main (void)
{
  greeter ("world");
  return 0;
}

// g++ -fmodules-ts -std=c++2b -c main.cpp

// g++ -fmodules-ts -std=c++2b hello.cpp main.cpp
// g++ -c -fmodules-ts -x c++-system-header  -std=c++20 iostream string vector