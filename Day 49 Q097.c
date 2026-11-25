#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[1005];
    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 0;
    }
    str[strcspn(str, "\r\n")] = '\0';
    int in_word = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isspace((unsigned char)str[i])) {
            if (!in_word) {
                printf("%c.", str[i]);
                in_word = 1;
            }
        } else {
            in_word = 0;
        }
    }
    printf("\n");
    return 0;
}
