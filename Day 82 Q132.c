#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum TrafficLight {
    RED,
    YELLOW,
    GREEN
};

int main() {
    char token[128];
    if (scanf("%127s", token) != 1) {
        return 0;
    }

    for (int i = 0; token[i] != '\0'; i++) {
        token[i] = (char)toupper((unsigned char)token[i]);
    }

    enum TrafficLight light;
    if (strcmp(token, "RED") == 0) {
        light = RED;
    } else if (strcmp(token, "YELLOW") == 0) {
        light = YELLOW;
    } else if (strcmp(token, "GREEN") == 0) {
        light = GREEN;
    } else {
        return 0;
    }

    switch (light) {
        case RED:
            printf("Stop\n");
            break;
        case YELLOW:
            printf("Wait\n");
            break;
        case GREEN:
            printf("Go\n");
            break;
    }

    return 0;
}
