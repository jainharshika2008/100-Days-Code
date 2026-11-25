#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum Status {
    SUCCESS,
    FAILURE,
    TIMEOUT
};

int main() {
    char token[128];
    if (scanf("%127s", token) != 1) {
        return 0;
    }

    for (int i = 0; token[i] != '\0'; i++) {
        token[i] = (char)toupper((unsigned char)token[i]);
    }

    enum Status st;
    if (strcmp(token, "SUCCESS") == 0) {
        st = SUCCESS;
    } else if (strcmp(token, "FAILURE") == 0) {
        st = FAILURE;
    } else if (strcmp(token, "TIMEOUT") == 0) {
        st = TIMEOUT;
    } else {
        return 0;
    }

    switch (st) {
        case SUCCESS:
            printf("Operation succeeded\n");
            break;
        case FAILURE:
            printf("Operation failed\n");
            break;
        case TIMEOUT:
            printf("Operation timed out\n");
            break;
    }

    return 0;
}
