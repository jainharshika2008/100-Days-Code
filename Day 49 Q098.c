#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[1005];
    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 0;
    }
    str[strcspn(str, "\r\n")] = '\0';
    int len = (int)strlen(str);
    while (len > 0 && isspace((unsigned char)str[len - 1])) {
        str[--len] = '\0';
    }
    int last_space = -1;
    for (int i = len - 1; i >= 0; i--) {
        if (isspace((unsigned char)str[i])) {
            last_space = i;
            break;
        }
    }
    if (last_space == -1) {
        printf("%s\n", str);
        return 0;
    }
    int in_word = 0;
    for (int i = 0; i < last_space; i++) {
        if (!isspace((unsigned char)str[i])) {
            if (!in_word) {
                printf("%c.", str[i]);
                in_word = 1;
            }
        } else {
            in_word = 0;
        }
    }
    printf(" %s\n", str + last_space + 1);
    return 0;
}
