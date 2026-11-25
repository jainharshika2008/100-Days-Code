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
    char filename[1024] = "data.txt";
    char append_text[4096] = {0};

    if (fgets(line, sizeof(line), stdin) != NULL) {
        line[strcspn(line, "\r\n")] = '\0';
        char *file_pos = strstr(line, "Existing File:");
        if (file_pos == NULL) {
            file_pos = strstr(line, "existing file:");
        }
        if (file_pos == NULL) {
            file_pos = strstr(line, "File:");
        }
        if (file_pos == NULL) {
            file_pos = strstr(line, "file:");
        }

        char *input_pos = strstr(line, "User Input:");
        if (input_pos == NULL) {
            input_pos = strstr(line, "user input:");
        }

        if (file_pos != NULL) {
            const char *after_label = strchr(file_pos, ':');
            if (after_label != NULL) {
                extract_filename(after_label + 1, filename, sizeof(filename));
            }
        }

        if (input_pos != NULL) {
            const char *p = strchr(input_pos, ':');
            if (p != NULL) {
                p++;
                while (*p == ' ' || *p == '\t') {
                    p++;
                }
                snprintf(append_text, sizeof(append_text), "%s", p);
            }
        } else if (file_pos != NULL) {
            if (fgets(append_text, sizeof(append_text), stdin) != NULL) {
                append_text[strcspn(append_text, "\r\n")] = '\0';
                char *second_input = strstr(append_text, "User Input:");
                if (second_input == NULL) {
                    second_input = strstr(append_text, "user input:");
                }
                if (second_input != NULL) {
                    const char *p = strchr(second_input, ':');
                    if (p != NULL) {
                        p++;
                        while (*p == ' ' || *p == '\t') {
                            p++;
                        }
                        memmove(append_text, p, strlen(p) + 1);
                    }
                }
            }
        } else if (line[0] != '\0') {
            snprintf(filename, sizeof(filename), "%s", line);
            if (fgets(append_text,
