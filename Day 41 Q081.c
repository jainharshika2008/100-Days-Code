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
    printf("%d\n", len);
    return 0;
}
