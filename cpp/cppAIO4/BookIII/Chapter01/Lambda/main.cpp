#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct EvenPair {
  int Value;
  bool Even;
};

int main(){
  vector<int> Values{1, 2, 3, 4};
  vector<EvenPair> Evens(Values.size());

  transform(Values.begin(), Values.end(),
            Evens.begin(), [](int Value) {
              return (Value % 2 == 0)
                ? EvenPair{Value, true}
                : EvenPair{Value, false};});

  for(auto isEven : Evens)
    if (isEven.Even)
      cout << isEven.Value << " is even." << endl;
    else
      cout << isEven.Value << " is odd." << endl;

  return 0;
}
