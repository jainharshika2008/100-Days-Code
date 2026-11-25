#include <stdio.h>
#include <string.h>

int main() {
    char str[1005];
    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 0;
    }
    str[strcspn(str, "\r\n")] = '\0';
    int len = (int)strlen(str);
    int start = 0;
    for (int i = 0; i <= len; i++) {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\0') {
            int end = i - 1;
            while (start < end) {
                char temp = str[start];
                str[start] = str[end];
                str[end] = temp;
                start++;
                end--;
            }
            start = i + 1;
        }
    }
    printf("%s\n", str);
    return 0;
}
