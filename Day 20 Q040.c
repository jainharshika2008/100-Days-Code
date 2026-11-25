#include <stdio.h>
#include <string.h>

int main() {
    char bin[105];
    if (scanf("%104s", bin) == 1) {
        int len = strlen(bin);
        for (int i = 0; i < len; i++) {
            if (bin[i] == '0') {
                bin[i] = '1';
            } else if (bin[i] == '1') {
                bin[i] = '0';
            }
        }
        printf("%s\n", bin);
    }
    return 0;
}
