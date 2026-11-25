#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static void extract_filename(const char *src, char *dest, size_t dest_size) {
    while (*src == ' ' || *src == '\t' || *src == '=') {
        src++;
    }
    const char *end = src;
    while (*end != '\0' && *end != ' ' && *end != '\t' && *end != '(' && *end != ')' && *end != '\r' && *end != '\n') {
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
    char in_name[1024] = "input.txt";
    char out_name[1024] = "output.txt";

    if (fgets(line, sizeof(line), stdin) != NULL) {
        line[strcspn(line, "\r\n")] = '\0';
        char *in_pos = strstr(line, "Input File");
        if (in_pos == NULL) {
            in_pos = strstr(line, "input file");
        }
        if (in_pos != NULL) {
            char *p1 = strchr(in_pos, '(');
            char *p2 = (p1 != NULL) ? strchr(p1 + 1, ')') : NULL;
            if (p1 != NULL && p2 != NULL && p2 > p1 + 1) {
                extract_filename(p1 + 1, in_name, sizeof(in_name));
            } else {
                char *colon = strchr(in_pos, ':');
                if (colon != NULL) {
                    extract_filename(colon + 1, in_name, sizeof(in_name));
                }
            }
        } else if (line[0] != '\0') {
            extract_filename(line, in_name, sizeof(in_name));
        }
    }

    FILE *in_fp = fopen(in_name, "r");
    if (in_fp == NULL) {
        return 1;
    }

    FILE *out_fp = fopen(out_name, "w");
    if (out_fp == NULL) {
        fclose(in_fp);
        return 1;
    }

    int ch;
    while ((ch = fgetc(in_fp)) != EOF) {
        fputc(toupper((unsigned char)ch), out_fp);
    }

    fclose(in_fp);
    fclose(out_fp);

    return 0;
}
