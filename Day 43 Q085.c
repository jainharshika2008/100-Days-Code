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
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
    for (int i = 0; i < len; i++) {
        printf("%c", str[i]);
    }
    printf("\n");
    return 0;
}
