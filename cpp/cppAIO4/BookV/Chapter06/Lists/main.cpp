#include <iostream>
#include <list>

using namespace std;

class Duck {
public:
  string name;
  int weight;
  int length;
};

ostream& operator << (ostream &out, const Duck &duck) {
  cout << "(" << duck.name;
  cout << "," << duck.weight;
  cout << "," << duck.length;
  cout << ")";
  return out;
}

void Dump(list<Duck> *mylist) {
  list<Duck>::iterator iter = mylist->begin();
  while (iter != mylist->end())
  {
    cout << *iter << endl;
    iter++;
  }
}

list<Duck>::iterator Move(list<Duck> *mylist, int pos) {
  list<Duck>::iterator res = mylist->begin();
  for (int loop = 1; loop <= pos; loop++)
  {
    res++;
  }
  return res;
}

bool operator < (const Duck& first, const Duck& second) {
  return first.name < second.name;
}

int main() {
  list<Duck> Inarow;

  // Push some at the beginning
  Duck d1 = {"Jim", 20, 15}; // Braces notation!
  Inarow.push_front(d1);
  Duck d2 = {"Sally", 15, 12};
  Inarow.push_front(d2);

  // Push some at the end
  Duck d3 = {"Betty", 18, 25};
  Inarow.push_front(d3);
  Duck d4 = {"Arnold", 19, 26};
  Inarow.push_front(d4);

  // Display the ducks
  cout << "===Ducks===" << endl;
  Dump(&Inarow);

  // Reverse
  Inarow.reverse();
  cout << "\n==Reversed==" << endl;
  Dump(&Inarow);

  // Create the second list.
  list<Duck> extras;
  Duck d5 = {"Grumpy", 8, 8};
  extras.push_back(d5);
  Duck d6 = {"Sleepy", 8, 8};
  extras.push_back(d6);

  // Display the extras list.
  cout << "\n===Extras===" << endl;
  Dump(&extras);

  // Determine the positions.
  list<Duck>::iterator first = Move(&extras, 0);
  list<Duck>::iterator last = Move(&extras, 2);
  list<Duck>::iterator into = Move(&Inarow, 2);

  // Perform the splicing.
  Inarow.splice(into, extras, first, last);
  cout << "\n==Extras After Splice==" << endl;
  Dump(&extras);
  cout << "\n==Inarow After Splice==" << endl;
  Dump(&Inarow);

  // Sort the list.
  Inarow.sort();
  cout << "\n===Sorted===" << endl;
  Dump(&Inarow);
  return 0;
}
