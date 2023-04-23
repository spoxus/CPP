#include <cstdio>

int main() {
    char lower[] = "abc?e";
    char upper[] = "ABC?E";
    char *upper_ptr = upper;

    lower[3] = 'd';
    upper[3] = 'D';

    char letter_d = lower[3];
    char letter_D = upper[3];

    printf("lower: %s\nupper: %s\n", lower, upper);
    lower[7] = 'g';
}