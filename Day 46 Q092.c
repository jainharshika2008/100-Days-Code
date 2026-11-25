#include <stdio.h>

int main() {
    char str[1005];
    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 0;
    }
    int seen[26] = {0};
    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            int idx = str[i] - 'a';
            if (seen[idx]) {
                printf("%c\n", str[i]);
                return 0;
            }
            seen[idx] = 1;
        }
    }
    return 0;
}
