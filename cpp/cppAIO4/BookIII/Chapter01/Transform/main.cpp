#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct EvenPair {
  int Value;
  bool Even;
};

EvenPair IsEven(int Value){
  if (Value % 2 == 0)
    return EvenPair{Value, true};

  return EvenPair{Value, false};
}

int main(){
  vector<int> Values{1, 2, 3, 4};
  vector<EvenPair> Evens(Values.size());

  transform(Values.begin(), Values.end(),
            Evens.begin(), IsEven);

  for(auto isEven : Evens)
    if (isEven.Even)
      cout << isEven.Value << " is even." << endl;
    else
      cout << isEven.Value << " is odd." << endl;

  return 0;
}
