#include <stdio.h>

enum TrafficLight {
    RED,
    YELLOW,
    GREEN,
    LIGHT_COUNT
};

int main() {
    const char *names[] = {
        "RED",
        "YELLOW",
        "GREEN"
    };

    for (int i = RED; i < LIGHT_COUNT; i++) {
        printf("%s=%d\n", names[i], i);
    }

    return 0;
}
