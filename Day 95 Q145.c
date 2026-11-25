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

struct Student getTopStudent(const struct Student arr[], int n) {
    struct Student top;
    memset(&top, 0, sizeof(top));
    if (n <= 0) {
        return top;
    }
    top = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i].marks > top.marks) {
            top = arr[i];
        }
    }
    return top;
}

int main() {
    char buffer[8192];
    size_t total_len = 0;
    buffer[0] = '\0';

    char line[2048];
    while (fgets(line, sizeof(line), stdin) != NULL) {
        size_t l = strlen(line);
        if (total_len + l < sizeof(buffer) - 1) {
            memcpy(buffer + total_len, line, l);
            total_len += l;
            buffer[total_len] = '\0';
        }
    }

    trim_whitespace(buffer);
    if (buffer[0] == '\0') {
        return 0;
    }

    struct Student students[512];
    int count = 0;
    int expected_count = -1;

    char *colon = strchr(buffer, ':');
    char *data_start = buffer;

    if (colon != NULL) {
        char prefix[128];
        size_t plen = (size_t)(colon - buffer);
        if (plen >= sizeof(prefix)) {
            plen = sizeof(prefix) - 1;
        }
        memcpy(prefix, buffer, plen);
        prefix[plen] = '\0';
        for (size_t i = 0; prefix[i] != '\0'; i++) {
            if (isdigit((unsigned char)prefix[i])) {
                expected_count = (int)strtol(prefix + i, NULL, 10);
                break;
            }
        }
        data_start = colon + 1;
    }

    char *segment = strtok(data_start, ",;\n\r");
    while (segment != NULL && count < 512) {
        trim_whitespace(segment);
        if (segment[0] != '\0') {
            char name[128];
            int roll = 0, marks = 0;
            if (sscanf(segment, "%127s %d %d", name, &roll, &marks) == 3) {
                snprintf(students[count].name, sizeof(students[count].name),
