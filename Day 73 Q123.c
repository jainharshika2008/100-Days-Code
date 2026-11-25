#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char line[4096];
    char filename[1024] = "sample.txt";

    if (fgets(line, sizeof(line), stdin) != NULL) {
        line[strcspn(line, "\r\n")] = '\0';
        char *file_pos = strstr(line, "File:");
        if (file_pos == NULL) {
            file_pos = strstr(line, "file:");
        }
        if (file_pos != NULL) {
            char *p = file_pos + 5;
            while (*p == ' ' || *p == '\t') {
                p++;
            }
            char *end = p;
            while (*end != '\0' && *end != ' ' && *end != '\t' && *end != '(') {
                end++;
            }
            size_t len = (size_t)(end - p);
            if (len > 0 && len < sizeof(filename)) {
                memcpy(filename, p, len);
                filename[len] = '\0';
            }
        } else if (line[0] != '\0') {
            snprintf(filename, sizeof(filename), "%s", line);
        }
    }

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return 1;
    }

    long long characters = 0;
    long long words = 0;
    long long lines = 0;
    int in_word = 0;
    int ch;

    while ((ch = fgetc(fp)) != EOF) {
        characters++;
        if (ch == '\n') {
            lines++;
        }
        if (isspace((unsigned char)ch)) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            words++;
        }
    }

    if (characters > 0) {
        lines++;
    }

    fclose(fp);

    printf("Characters: %lld\n", characters);
    printf("Words: %lld\n", words);
    printf("Lines: %lld\n", lines);

    return 0;
}
