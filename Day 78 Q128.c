#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static void extract_filename(const char *src, char *dest, size_t dest_size) {
    while (*src == ' ' || *src == '\t' || *src == '=') {
        src++;
    }
    const char *end = src;
    while (*end != '\0' && *end != ' ' && *end != '\t' && *end != '(' && *end != '\r' && *end != '\n') {
        end++;
    }
    size_t len = (size_t)(end - src);
    if (len > 0 && len < dest_size) {
        memcpy(dest, src, len);
        dest[len] = '\0';
    }
}

int main() {
    char line[4096];
    char filename[1024] = "text.txt";

    if (fgets(line, sizeof(line), stdin) != NULL) {
        line[strcspn(line, "\r\n")] = '\0';
        char *pos = strstr(line, "File:");
        if (pos == NULL) {
            pos = strstr(line, "file:");
        }
        if (pos != NULL) {
            const char *colon = strchr(pos, ':');
            if (colon != NULL) {
                extract_filename(colon + 1, filename, sizeof(filename));
            }
        } else if (line[0] != '\0') {
            extract_filename(line, filename, sizeof(filename));
        }
    }

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return 1;
    }

    long long vowels = 0;
    long long consonants = 0;
    int ch;

    while ((ch = fgetc(fp)) != EOF) {
        unsigned char uch = (unsigned char)ch;
        if (isalpha(uch)) {
            char lower = (char)tolower(uch);
            if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }

    fclose(fp);

    printf("Vowels: %lld\n", vowels);
    printf("Consonants: %lld\n", consonants);

    return 0;
}
