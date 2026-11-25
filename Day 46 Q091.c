#include <stdio.h>
#include <ctype.h>

int main() {
    char str[1005];
    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 0;
    }
    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        char lower = (char)tolower((unsigned char)str[i]);
        if (lower != 'a' && lower != 'e' && lower != 'i' && lower != 'o' && lower != 'u') {
            printf("%c", str[i]);
        }
    }
    printf("\n");
    return 0;
}
