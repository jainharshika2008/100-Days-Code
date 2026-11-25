#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[128];
    int roll_no;
    int marks;
};

static void trim_whitespace(char *str) {
    char *start = str;
    while (*start == ' ' || *start == '\t' || *start == '\r' || *start == '\n') {
        start++;
    }
    if (start != str) {
        memmove(str, start, strlen(start) + 1);
    }
    size_t len = strlen(str);
    while (len > 0 && (str[len - 1] == ' ' || str[len - 1] == '\t' || str[len - 1] == '\r' || str[len - 1] == '\n')) {
        str[--len] = '\0';
    }
}

static void extract_value_after_colon(char *line, char *out, size_t out_size) {
    char *colon = strchr(line, ':');
    if (colon != NULL) {
        snprintf(out, out_size, "%s", colon + 1);
    } else {
        snprintf(out, out_size, "%s", line);
    }
    trim_whitespace(out);
}

int main() {
    struct Student s;
    s.name[0] = '\0';
    s.roll_no = 0;
    s.marks = 0;

    char line[1024];
    int lines_read = 0;

    while (lines_read < 3 && fgets(line, sizeof(line), stdin) != NULL) {
        line[strcspn(line, "\r\n")] = '\0';
        trim_whitespace(line);
        if (line[0] == '\0') {
            continue;
        }

        if (strncmp(line, "Name:", 5) == 0 || strncmp(line, "name:", 5) == 0) {
            extract_value_after_colon(line, s.name, sizeof(s.name));
        } else if (strncmp(line, "Roll:", 5) == 0 || strncmp(line, "roll:", 5) == 0) {
            char val[128];
            extract_value_after_colon(line, val, sizeof(val));
            s.roll_no = (int)strtol(val, NULL, 10);
        } else if (strncmp(line, "Marks:", 6) == 0 || strncmp(line, "marks:", 6) == 0) {
            char val[128];
            extract_value_after_colon(line, val, sizeof(val));
            s.marks = (int)strtol(val, NULL, 10);
        } else {
            if (lines_read == 0) {
                snprintf(s.name, sizeof(s.name), "%s", line);
            } else if (lines_read == 1) {
                s.roll_no = (int)strtol(line, NULL, 10);
            } else if (lines_read == 2) {
                s.marks = (int)strtol(line, NULL, 10);
            }
        }
        lines_read++;
    }

    printf("Name: %s | Roll: %d | Marks: %d\n", s.name, s.roll_no, s.marks);
    return 0;
}
