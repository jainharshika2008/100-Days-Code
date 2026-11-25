#include <stdio.h>

int main() 
{
    float c;
    scanf("%f", &c);
    printf("Fahrenheit=%.0f\n", (c * 9.0f / 5.0f) + 32.0f);
    return 0;
}
