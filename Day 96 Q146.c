#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Employee {
    char name[128];
    int id;
    struct Date joining_date;
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

int main() {
    char line[4096];
    if (fgets(line, sizeof(line), stdin) == NULL) {
        return 0;
    }

    trim_whitespace(line);
    if (line[0] == '\0') {
        return 0;
    }

    struct Employee emp;
    emp.name[0] = '\0';
    emp.id = 0;
    emp.joining_date.day = 0;
    emp.joining_date.month = 0;
    emp.joining_date.year = 0;

    char copy[4096];
    snprintf(copy, sizeof(copy), "%s", line);

    char *part = strtok(copy, "|");
    while (part != NULL) {
        trim_whitespace(part);
        if (strncmp(part, "Employee:", 9) == 0 || strncmp(part, "employee:", 9) == 0 ||
            strncmp(part, "Name:", 5) == 0 || strncmp(part, "name:", 5) == 0) {
            char *colon = strchr(part, ':');
            if (colon != NULL) {
                char val[128];
                snprintf(val, sizeof(val), "%s", colon + 1);
                trim_whitespace(val);
                snprintf(emp.name, sizeof(emp.name), "%s", val);
            }
        } else if (strncmp(part, "ID:", 3) == 0 || strncmp(part, "id:", 3) == 0) {
            char *colon = strchr(part, ':');
            if (colon != NULL) {
                char val[128];
                snprintf(val, sizeof(val), "%s", colon + 1);
                trim_whitespace(val);
                emp.id = (int)strtol(val, NULL, 10);
            }
        } else if (strstr(part, "Date:") != NULL || strstr(part, "date:") != NULL) {
            char *colon = strchr(part, ':');
            if (colon != NULL) {
                char val[128];
                snprintf(val, sizeof(val), "%s", colon + 1);
                trim_whitespace(val);
                int d = 0, m = 0, y = 0;
                if (sscanf(val, "%d %d %d", &d, &m, &y) == 3 ||
                    sscanf(val, "%d/%d/%d", &d, &m, &y) == 3 ||
                    sscanf(val, "%d-%d-%d", &d, &m, &y) == 3) {
                    emp.joining_date.day = d;
                    emp.joining_date.month = m;
                    emp.joining_date.year = y;
                }
            }
        }
        part = strtok(NULL, "|");
    }

    if (emp.name[0] == '\0') {
        sscanf(line, "%127s %d %d %d %d",
               emp.name, &emp.id,
               &emp.joining_date.day, &emp.joining_date.month, &emp.joining_date.year);
    }

    printf("Name: %s | ID: %d | Joining Date: %02d/%02d/%04d\n",
           emp.name, emp.id,
           emp.joining_date.day, emp.joining_date.month, emp.joining_date.year);

    return 0;
}
