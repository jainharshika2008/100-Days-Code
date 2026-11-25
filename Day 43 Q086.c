#include <stdio.h>

int main() {
    char str[1005];
    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 0;
    }
    int len = 0;
    while (str[len] != '\0' && str[len] != '\n') {
        len++;
    }
    int is_palindrome = 1;
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            is_palindrome = 0;
            break;
        }
    }
    if (is_palindrome) {
        printf("Palindrome\n");
    } else {
        printf("Not palindrome\n");
    }
    return 0;
}
