#include <stdio.h>
#include <string.h>

int main() {
    char date[105];
    if (fgets(date, sizeof(date), stdin) == NULL) {
        return 0;
    }
    date[strcspn(date, "\r\n")] = '\0';
    char dd[10], mm[10], yyyy[20];
    if (sscanf(date, "%9[^/]/%9[^/]/%19s", dd, mm, yyyy) == 3) {
        if (strcmp(mm, "04") == 0) {
            printf("%s-Apr-%s\n", dd, yyyy);
        } else {
            printf("%s/%s/%s\n", dd, mm, yyyy);
        }
    }
    return 0;
}
