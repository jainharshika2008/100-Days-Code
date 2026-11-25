#include <stdio.h>

int main() {
    char str[1005];
    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 0;
    }
    char target;
    if (scanf(" %c", &target) != 1) {
        return 0;
    }
    int count = 0;
    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        if (str[i] == target) {
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}
