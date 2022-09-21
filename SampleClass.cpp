// SampleClass.cpp
#include <iostream>
using namespace std;

class SampleClass {
public:
    double contents[1000];

    SampleClass(double d) {
        for (int i = 0; i < 1000; i++)
            contents[i] = d * i;
    }

    virtual ~SampleClass() {
        cout << "SampleClass instance being deleted ...\n";
    }

    void print() {
        for (int i = 0; i < 1000; i++) {
            cout << i << "th item = " << contents[i];
            if (i % 5 == 0) {
                cout << endl;
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    SampleClass sc(1.0);
    sc.print();

    return 0;
}