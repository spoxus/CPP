#include <iostream>
#include <memory>
#include <optional>

using namespace std;

void unicPoint() {
    int myValue = 42;

    unique_ptr<int> ptr1(new int());
    *ptr1 = 100;
    cout << "*ptr value" << *ptr1 << endl;

    unique_ptr<int> ptr2(&myValue);
    cout << "*ptr2 value" << *ptr2 << endl;

    unique_ptr<int> ptr3 = make_unique<int>(98);
    cout << "*ptr3 value" << *ptr3 << endl;
    cout << "ptr3 address " << ptr3.get() << endl;
    unique_ptr<int> ptr4;
    ptr4 = move(ptr3);

    if (ptr3 == nullptr) {
        cout << "ptr3 is null" << endl;
    }

    cout << "*ptr4 value: " << *ptr4 << endl;
    cout << "ptr4 address: " << ptr4.get();

}

void sharedPointers() {
    int myValue = 42;
    shared_ptr<int> ptr1(new int(myValue));
    cout << "*ptr1 vaule: " << *ptr1 << endl;
    cout << "ptr1 use count: " << ptr1.use_count() << endl;

    shared_ptr<int> ptr2 = ptr1;
    cout << "*ptr2 value: " << *ptr2 << endl;
    cout << "ptr1 address: " << ptr1 << endl;
    cout << "ptr2 address: " << ptr2 << endl;
    cout << "ptr1 use count: " << ptr1.use_count() << endl;

    ptr2.reset();
    cout << "ptr1 use count after ptr2 reset: " << ptr1.use_count() << endl;

    ptr1.reset();
    cout << "ptr1 use count after ptr1 reset: " << ptr1.use_count() << endl;
}

void myFunction(optional<string> name = nullopt) {
    if (name == nullopt) {
        cout << "i wish i knew your name!" << endl;
    } else {
        cout << "Hello " << name.value() << endl;
    }
}

int main() {
    cout << "Hello world!" << endl;
    //sharedPointers();

    myFunction();
    myFunction("Sarah");

    return 0;
}
