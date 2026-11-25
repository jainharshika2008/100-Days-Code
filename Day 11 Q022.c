#include <stdio.h>

int main() {
    double cp, sp, percentage;
    scanf("%lf %lf", &cp, &sp);
    if (sp > cp) {
        percentage = ((sp - cp) / cp) * 100.0;
        printf("Profit %.0f%%\n", percentage);
    } else if (cp > sp) {
        percentage = ((cp - sp) / cp) * 100.0;
        printf("Loss %.0f%%\n", percentage);
    } else {
        printf("No Profit No Loss\n");
    }
    return 0;
}
