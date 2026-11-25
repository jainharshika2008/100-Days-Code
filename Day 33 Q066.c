#include <stdio.h>

int main() {
    int n, x;
    scanf("%d", &n);
    int arr[n + 1];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &x);
    int pos = n - 1;
    while (pos >= 0 && arr[pos] > x) {
        arr[pos + 1] = arr[pos];
        pos--;
    }
    arr[pos + 1] = x;
    for (int i = 0; i <= n; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", arr[i]);
    }
    printf("\n");
    return 0;
}
