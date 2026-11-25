#include <stdio.h>
#include <string.h>

int main() {
    char num[50];
    if (scanf("%49s", num) == 1) {
        int start = 0;
        if (num[0] == '-' || num[0] == '+') {
            start = 1;
        }
        int len = strlen(num);
        if (len - start > 1) {
            char temp = num[start];
            num[start] = num[len - 1];
            num[len - 1] = temp;
        }
        printf("%s\n", num);
    }
    return 0;
}
