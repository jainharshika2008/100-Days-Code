#include <stdio.h>

enum Status {
    SUCCESS,
    FAILURE,
    TIMEOUT
};

int main() {
    int s = SUCCESS;
    int f = FAILURE;
    int t = TIMEOUT;
    printf("SUCCESS=%d, FAILURE=%d, TIMEOUT=%d\n", s, f, t);
    return 0;
}
