#include <stdio.h>
#include <string.h>

int main() {
    char s1[1005], s2[1005];
    if (fgets(s1, sizeof(s1), stdin) == NULL || fgets(s2, sizeof(s2), stdin) == NULL) {
        return 0;
    }
    s1[strcspn(s1, "\r\n")] = '\0';
    s2[strcspn(s2, "\r\n")] = '\0';
    int freq[256] = {0};
    for (int i = 0; s1[i] != '\0'; i++) {
        freq[(unsigned char)s1[i]]++;
    }
    for (int i = 0; s2[i] != '\0'; i++) {
        freq[(unsigned char)s2[i]]--;
    }
    int is_anagram = 1;
    for (int i = 0; i < 256; i++) {
        if (freq[i] != 0) {
            is_anagram = 0;
            break;
        }
    }
    if (is_anagram) {
        printf("Anagrams\n");
    } else {
        printf("Not anagrams\n");
    }
    return 0;
}
