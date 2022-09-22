#include <iostream>
#include <sstream>
#include <stdlib.h>

using namespace std;

string *GetSecretCode()
{
  string *code = new string;
  code->append("CR");

  int randomnumber = rand();
  ostringstream converter;
  converter << randomnumber;
  code->append(converter.str());

  code->append("NQ");
  return code;
}

int main()
{
  string *newcode;

  for (int index = 0; index < 5; index++)
  {
    newcode = GetSecretCode();
    cout << *newcode << endl;
  }

  return 0;
}
