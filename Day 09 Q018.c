#include <stdio.h>

int main() {
    int p;
    scanf("%d", &p);
    if (p >= 90 && p <= 100) {
        printf("Grade A\n");
    } else if (p >= 80 && p <= 89) {
        printf("Grade B\n");
    } else if (p >= 70 && p <= 79) {
        printf("Grade C\n");
    } else if (p >= 60 && p <= 69) {
        printf("Grade D\n");
    } else {
        printf("Grade F\n");
    }
    return 0;
}
