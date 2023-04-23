#include <stdexcept>
#include <cstdio>

constexpr void assert_that(bool statement, const char* message) {
    if (!statement) throw std::runtime_error{message};
}

void run_test(void(*unit_test)(), const char* name) {
    try {
        unit_test();
        printf("[+] Test %s successful.\n", name);
    } catch (const std::exception& e) {
        printf("[-] Test failure in %s. %s.\n", name, e.what());
    }
}

void test_equal() {
    assert_that(24 == 42, "24 == 42? not right");
}

int main() {
    assert_that(1 + 2 > 2, "somethig wrong");
    run_test(test_equal, "not right");
}