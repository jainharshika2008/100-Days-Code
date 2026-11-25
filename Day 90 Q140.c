#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum Gender {
    MALE,
    FEMALE,
    OTHER
};

struct Person {
    enum Gender gender;
};

int main() {
    char line[256];
    if (fgets(line, sizeof(line), stdin) == NULL) {
        return 0;
    }

    line[strcspn(line, "\r\n")] = '\0';

    char *eq = strchr(line, '=');
    char *val = (eq != NULL) ? (eq + 1) : line;

    while (*val == ' ' || *val == '\t') {
        val++;
    }

    size_t len = strlen(val);
    while (len > 0 && (val[len - 1] == ' ' || val[len - 1] == '\t')) {
        val[--len] = '\0';
    }

    for (size_t i = 0; i < len; i++) {
        val[i] = (char)toupper((unsigned char)val[i]);
    }

    struct Person p;
    if (strcmp(val, "MALE") == 0) {
        p.gender = MALE;
    } else if (strcmp(val, "FEMALE") == 0) {
        p.gender = FEMALE;
    } else if (strcmp(val, "OTHER") == 0) {
        p.gender = OTHER;
    } else {
        return 0;
    }

    switch (p.gender) {
        case MALE:
            printf("Male\n");
            break;
        case FEMALE:
            printf("Female\n");
            break;
        case OTHER:
            printf("Other\n");
            break;
    }

    return 0;
}
