#include <stdio.h>
#include <math.h>

int main() {
    double p, r, t, si, ci;
    scanf("%lf %lf %lf", &p, &r, &t);
    si = (p * r * t) / 100.0;
    ci = p * pow((1.0 + r / 100.0), t) - p;
    printf("Simple Interest=%.2g, Compound Interest=%.2f\n", si, ci);
    return 0;
}
