#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum UserRole {
    ADMIN,
    USER,
    GUEST
};

int main() {
    char token[128];
    if (scanf("%127s", token) != 1) {
        return 0;
    }

    for (int i = 0; token[i] != '\0'; i++) {
        token[i] = (char)toupper((unsigned char)token[i]);
    }

    enum UserRole role;
    if (strcmp(token, "ADMIN") == 0) {
        role = ADMIN;
    } else if (strcmp(token, "USER") == 0) {
        role = USER;
    } else if (strcmp(token, "GUEST") == 0) {
        role = GUEST;
    } else {
        return 0;
    }

    switch (role) {
        case ADMIN:
            printf("Welcome Admin!\n");
            break;
        case USER:
            printf("Welcome User!\n");
            break;
        case GUEST:
            printf("Welcome Guest!\n");
            break;
    }

    return 0;
}
