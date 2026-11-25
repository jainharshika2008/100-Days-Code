#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char line[4096];
    if (fgets(line, sizeof(line), stdin) == NULL) {
        return 0;
    }

    char name[512] = {0};
    int age = 0;

    char *name_pos = strstr(line, "Name:");
    if (name_pos == NULL) {
        name_pos = strstr(line, "name:");
    }
    char *age_pos = strstr(line, "Age:");
    if (age_pos == NULL) {
        age_pos = strstr(line, "age:");
    }

    if (name_pos != NULL) {
        char *p = name_pos + 5;
        while (*p == ' ' || *p == '\t') {
            p++;
        }
        char *end = (age_pos != NULL && age_pos > p) ? age_pos : (p + strlen(p));
        while (end > p && (end[-1] == ',' || end[-1] == ' ' || end[-1] == '\t' || end[-1] == '\r' || end[-1] == '\n')) {
            end--;
        }
        size_t len = (size_t)(end - p);
        if (len >= sizeof(name)) {
            len = sizeof(name) - 1;
        }
        memcpy(name, p, len);
        name[len] = '\0';
    }

    if (age_pos != NULL) {
        age = (int)strtol(age_pos + 4, NULL, 10);
    } else if (name_pos == NULL) {
        line[strcspn(line, "\r\n")] = '\0';
        snprintf(name, sizeof(name), "%s", line);
        if (scanf("%d", &age) != 1) {
            age = 0;
        }
    }

    FILE *fp = fopen("info.txt", "w");
    if (fp == NULL) {
        return 1;
    }

    fprintf(fp, "Name: %s, Age: %d\n", name, age);
    fclose(fp);

    printf("File created successfully! Data written to info.txt\n");
    return 0;
}
