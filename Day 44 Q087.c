#include <stdio.h>
#include <ctype.h>

int main() {
    char str[1005];
    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 0;
    }
    int spaces = 0, digits = 0, special = 0;
    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        unsigned char ch = (unsigned char)str[i];
        if (ch == ' ') {
            spaces++;
        } else if (isdigit(ch)) {
            digits++;
        } else if (!isalpha(ch)) {
            special++;
        }
    }
    printf("Spaces=%d, Digits=%d, Special=%d\n", spaces, digits, special);
    return 0;
}
