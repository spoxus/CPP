#include <iostream>

using namespace std;

int main()
{
    int first = 10;
    int second = 20;
    string result;
    bool isequal;

    isequal = (first == second);
    result = isequal ? "equal" : "not equal";

    cout << result << endl;
    return 0;
}
