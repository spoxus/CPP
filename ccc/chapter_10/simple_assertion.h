#include <stdexcept>
#include <iostream>

using std::cout;
using std::endl;
using unit_test = void(*)();

constexpr void assert_that(bool statement, const char* message) {
    if (!statement) throw std::runtime_error{message};
}

void run_test(unit_test the_test, const char* name) {
    try {
        the_test();
        cout << "[+] Test '" << name << "' successful." << endl;
    } catch (const std::exception& e) {
        cout << "[-] Test failure in '" << name << "'. Error message: " << e.what() << endl;
    }
}

void test_equal() {
    assert_that(24 == 42, "24 == 42? not right");
}

void test_great_than() {
    assert_that(1 + 2 > 2, "great than test");
}

/*
usage below

int main() {
    assert_that(1 + 2 > 2, "greater than test");
    //assert_that( 24 == 42, "this assertion will generate an exception");
    run_test(test_equal, "equal test");
    run_test(test_great_than, "greater than");
}
*/