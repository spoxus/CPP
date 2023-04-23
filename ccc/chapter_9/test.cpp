#include <cstdio>
#include <cstdint>

struct CountIf {
    CountIf(char x) : x{x} {}
    size_t operator()(const char* str) const {
        size_t index{};
        size_t result{};
        while (str[index]) {
            if (str[index] == x) result++;
            index++;
        }
        return result;
    }
private:
    const char x;
};

float add(float a, int b) {
    return a + b;
}

float subtract(float a, int b) {
    return a - b;
}

int main() {
    const float first{100};
    const int second{20};

    float(*operation)(float, int) {};
    printf("operation initialized to 0x%p\n", operation);

    operation = &add;
    printf("&add = 0x%p\n", operation);
    printf("%g + %d = %g\n", first, second, operation(first, second));

    using operation_func = float(*)(float, int);
    operation_func f = subtract;
    printf("&subtract = 0x%p\n", f);
    printf("%g - %d = %g\n", first, second, f(first, second));

    CountIf s_count{'s'};
    auto sally = s_count("Sally sells seashells by theseashore.");
    printf("Sally: %zd\n", sally);
}