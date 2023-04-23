#include <cstdio>

struct College {
    char name[256];
};

void print_name(College *colleges, size_t n_colleges) {
    for (size_t i = 0; i < n_colleges; i++)
        printf("%s College\n", colleges[i].name);
}

void print_name_array(College colleges[], size_t n_colleges) {
    for (size_t i = 0; i < n_colleges; i++)
        printf("%s College\n", colleges[i].name);
}

int main() {
    College oxford[] = {"Magdalen", "Nuffield", "Kellogg"};
    print_name(oxford, sizeof(oxford) / sizeof(College));
    print_name_array(oxford, sizeof(oxford) / sizeof(College));
}