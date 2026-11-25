#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum MenuChoice {
    ADD = 1,
    SUBTRACT,
    MULTIPLY
};

int main() {
    char op_str[64];
    long long a = 0, b = 0;

    if (scanf("%63s %lld %lld", op_str, &a, &b) != 3) {
        return 0;
    }

    for (int i = 0; op_str[i] != '\0'; i++) {
        op_str[i] = (char)toupper((unsigned char)op_str[i]);
    }

    enum MenuChoice choice;
    if (strcmp(op_str, "ADD") == 0) {
        choice = ADD;
    } else if (strcmp(op_str, "SUBTRACT") == 0 || strcmp(op_str, "SUB") == 0) {
        choice = SUBTRACT;
    } else if (strcmp(op_str, "MULTIPLY") == 0 || strcmp(op_str, "MUL") == 0) {
        choice = MULTIPLY;
    } else {
        return 0;
    }

    switch (choice) {
        case ADD:
            printf("%lld\n", a + b);
            break;
        case SUBTRACT:
            printf("%lld\n", a - b);
            break;
        case MULTIPLY:
            printf("%lld\n", a * b);
            break;
    }

    return 0;
}
