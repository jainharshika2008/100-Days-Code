#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char filename[1024] = {0};

    if (fgets(line, sizeof(line), stdin) != NULL) {
        line[strcspn(line, "\r\n")] = '\0';
        char *pos = strstr(line, "Filename:");
        if (pos == NULL) {
            pos = strstr(line, "filename:");
        }
        if (pos == NULL) {
            pos = strstr(line, "File:");
        }
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

    if (filename[0] == '\0') {
        printf("Error: File does not exist!\n");
        return 0;
    }

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File does not exist!\n");
        return 0;
    }

    printf("File opened successfully.\n");
    char buffer[4096];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    fclose(fp);
    return 0;
}
