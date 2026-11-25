#include <stdio.h>
#include <string.h>

int main() {
    char str[1005];
    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 0;
    }
    str[strcspn(str, "\r\n")] = '\0';
    int max_len = 0, max_start = 0;
    int cur_len = 0, cur_start = 0;
    int i = 0;
    while (1) {
        char ch = str[i];
        if (ch == ' ' || ch == '\t' || ch == '\0') {
            if (cur_len > max_len) {
                max_len = cur_len;
                max_start = cur_start;
            }
            cur_len = 0;
            cur_start = i + 1;
            if (ch == '\0') {
                break;
            }
        } else {
            if (cur_len == 0) {
                cur_start = i;
            }
            cur_len++;
        }
        i++;
    }
    if (max_len > 0) {
        for (int j = 0; j < max_len; j++) {
            printf("%c", str[max_start + j]);
        }
    }
    printf("\n");
    return 0;
}
