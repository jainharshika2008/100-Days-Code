#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[128];
    int roll;
    int marks;
} Student;

int main() {
    char line[8192];
    if (fgets(line, sizeof(line), stdin) == NULL) {
        return 0;
    }
    line[strcspn(line, "\r\n")] = '\0';

    Student records[256];
    int count = 0;

    char *cursor = line;
    while (*cursor != '\0' && count < 256) {
        char *n_pos = strstr(cursor, "Name:");
        if (n_pos == NULL) {
            n_pos = strstr(cursor, "name:");
        }
        if (n_pos == NULL) {
            break;
        }

        char *p = n_pos + 5;
        while (*p == ' ' || *p == '\t') {
            p++;
        }

        char *r_pos = strstr(p, "Roll:");
        if (r_pos == NULL) {
            r_pos = strstr(p, "roll:");
        }
        char *m_pos = strstr(p, "Marks:");
        if (m_pos == NULL) {
            m_pos = strstr(p, "marks:");
        }

        if (r_pos == NULL || m_pos == NULL) {
            break;
        }

        char *name_end = r_pos;
        while (name_end > p && (name_end[-1] == ',' || name_end[-1] == ' ' || name_end[-1] == '\t' || name_end[-1] == ';')) {
            name_end--;
        }
        size_t nlen = (size_t)(name_end - p);
        if (nlen >= sizeof(records[count].name)) {
            nlen = sizeof(records[count].name) - 1;
        }
        memcpy(records[count].name, p, nlen);
        records[count].name[nlen] = '\0';

        records[count].roll = (int)strtol(r_pos + 5, NULL, 10);
        records[count].marks = (int)strtol(m_pos + 6, NULL, 10);

        cursor = m_pos + 6;
        while (*cursor != '\0' && *cursor != ';') {
            cursor++;
        }
        if (*cursor == ';') {
            cursor++;
        }

        count++;
    }

    if (count == 0) {
        int n = (int)strtol(line, NULL, 10);
        if (n <= 0 || n > 256) {
            return 0;
        }
        for (int i = 0; i < n; i++) {
            if (scanf("%127s %d %d", records[i].name, &records[i].roll, &records[i].marks) != 3) {
                return 0;
            }
            count++;
        }
    }

    FILE *fp = fopen("students.txt", "w");
    if (fp == NULL) {
        return 1;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s %d %d\n", records[i].name, records[i].roll, records[i].marks);
    }
    fclose(fp);

    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        return 1;
    }

    Student s;
    while (fscanf(fp, "%127s %d %d", s.name, &s.roll, &s.marks) == 3) {
        printf("Name: %s | Roll: %d | Marks: %d\n", s.name, s.roll, s.marks);
    }

    fclose(fp);
    return 0;
}
