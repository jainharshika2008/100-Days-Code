#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_STUDENTS 5

struct Student {
    char name[128];
    int roll;
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

static void extract_value_after_colon(const char *line, char *out, size_t out_size) {
    const char *colon = strchr(line, ':');
    if (colon != NULL) {
        snprintf(out, out_size, "%s", colon + 1);
    } else {
        snprintf(out, out_size, "%s", line);
    }
    trim_whitespace(out);
}

int main() {
    struct Student students[NUM_STUDENTS];
    for (int i = 0; i < NUM_STUDENTS; i++) {
        students[i].name[0] = '\0';
        students[i].roll = 0;
        students[i].marks = 0;
    }

    char line[4096];
    int idx = 0;
    int field_step = 0;

    while (idx < NUM_STUDENTS && fgets(line, sizeof(line), stdin) != NULL) {
        line[strcspn(line, "\r\n")] = '\0';
        trim_whitespace(line);
        if (line[0] == '\0') {
            continue;
        }

        if (strncmp(line, "Name:", 5) == 0 || strncmp(line, "name:", 5) == 0) {
            extract_value_after_colon(line, students[idx].name, sizeof(students[idx].name));
            field_step = 1;
        } else if (strncmp(line, "Roll:", 5) == 0 || strncmp(line, "roll:", 5) == 0) {
            char val[128];
            extract_value_after_colon(line, val, sizeof(val));
            students[idx].roll = (int)strtol(val, NULL, 10);
            field_step = 2;
        } else if (strncmp(line, "Marks:", 6) == 0 || strncmp(line, "marks:", 6) == 0) {
            char val[128];
            extract_value_after_colon(line, val, sizeof(val));
            students[idx].marks = (int)strtol(val, NULL, 10);
            idx++;
            field_step =
