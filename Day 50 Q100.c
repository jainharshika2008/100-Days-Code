#include <stdio.h>
#include <string.h>

int main() {
    char str[1005];
    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 0;
    }
    str[strcspn(str, "\r\n")] = '\0';
    int len = (int)strlen(str);
    int first = 1;
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            if (!first) {
                printf(",");
            }
            first = 0;
            for (int k = i; k <= j; k++) {
                printf("%c", str[k]);
            }
        }
    }
    printf("\n");
    return 0;
}
