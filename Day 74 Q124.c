#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void extract_path_after_label(const char *src, char *dest, size_t dest_size) {
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
    char src_name[1024] = "source.txt";
    char dst_name[1024] = "destination.txt";

    if (fgets(line, sizeof(line), stdin) != NULL) {
        line[strcspn(line, "\r\n")] = '\0';
        char *src_pos = strstr(line, "Source File:");
        if (src_pos == NULL) {
            src_pos = strstr(line, "source file:");
        }
        char *dst_pos = strstr(line, "Destination File:");
        if (dst_pos == NULL) {
            dst_pos = strstr(line, "destination file:");
        }

        if (src_pos != NULL) {
            extract_path_after_label(src_pos + 12, src_name, sizeof(src_name));
        }
        if (dst_pos != NULL) {
            extract_path_after_label(dst_pos + 16, dst_name, sizeof(dst_name));
        }
        if (src_pos == NULL && dst_pos == NULL && line[0] != '\0') {
            char first[1024] = {0}, second[1024] = {0};
            if (sscanf(line, "%1023s %1023s", first, second) == 2) {
                snprintf(src_name, sizeof(src_name), "%s", first);
                snprintf(dst_name, sizeof(dst_name), "%s", second);
            } else {
                snprintf(src_name, sizeof(src_name), "%s", line);
                char second_line[1024];
                if (fgets(second_line, sizeof(second_line), stdin) != NULL) {
                    second_line[strcspn(second_line, "\r\n")] = '\0';
                    if (second_line[0] != '\0') {
                        snprintf(dst_name, sizeof(dst_name), "%s", second_line);
                    }
                }
            }
        }
    }

    FILE *src_fp = fopen(src_name, "r");
    if (src_fp == NULL) {
        return 1;
    }

    FILE *dst_fp = fopen(dst_name, "w");
    if (dst_fp == NULL) {
        fclose(src_fp);
        return 1;
    }

    int ch;
    while ((ch = fgetc(src_fp)) != EOF) {
        fputc(ch, dst_fp);
    }

    fclose(src_fp);
    fclose(dst_fp);

    printf("File copied successfully to %s\n", dst_name);
    return 0;
}
