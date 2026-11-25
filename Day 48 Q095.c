#include <stdio.h>
#include <string.h>

int main() {
    char s1[1005], s2[1005];
    if (fgets(s1, sizeof(s1), stdin) == NULL || fgets(s2, sizeof(s2), stdin) == NULL) {
        return 0;
    }
    s1[strcspn(s1, "\r\n")] = '\0';
    s2[strcspn(s2, "\r\n")] = '\0';
    int len1 = (int)strlen(s1);
    int len2 = (int)strlen(s2);
    if (len1 != len2) {
        printf("Not rotation\n");
        return 0;
    }
    char doubled[2015];
    strcpy(doubled, s1);
    strcat(doubled, s1);
    if (strstr(doubled, s2) != NULL) {
        printf("Rotation\n");
    } else {
        printf("Not rotation\n");
    }
    return 0;
}
