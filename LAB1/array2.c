#include <stdio.h>

int main() {
    int n;

    printf("Enter order of square matrix: ");
    scanf("%d", &n);

    int matrix[n][n];
    int sum = 0;

    printf("Enter matrix elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        sum += matrix[i][i];
    }

    printf("Sum of left (primary) diagonal: %d\n", sum);

    return 0;
}