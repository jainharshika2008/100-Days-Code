#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

void printStudent(struct Student s) {
    printf("Name: %s | Roll: %d | Marks: %d\n", s.name, s.roll, s.marks);
}

int main() {
    char line[4096];
    if (fgets(line, sizeof(line), stdin) == NULL) {
        return 0;
    }

    trim_whitespace(line);
    if (line[0] == '\0') {
        return 0;
    }

    struct Student s;
    s.name[0] = '\0';
    s.roll = 0;
    s.marks = 0;

    char *colon = strchr(line, ':');
    const char *data = (colon != NULL) ? (colon + 1) : line;

    char trimmed_data[4096];
    snprintf(trimmed_data, sizeof(trimmed_data), "%s", data);
    trim_whitespace(trimmed_data);

    if (sscanf(trimmed_data, "%127s %d %d", s.name, &s.roll, &s.marks) != 3) {
        char name_buf[128] = "";
        int roll_val = 0, marks_val = 0;
        if (scanf("%127s %d %d", name_buf, &roll_val, &marks_val) == 3) {
            snprintf(s.name, sizeof(s.name), "%s", name_buf);
            s.roll = roll_val;
            s.marks = marks_val;
        }
    }

    printStudent(s);
    return 0;
}
