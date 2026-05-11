#include <stdio.h>

int main() {
    int n, m, i, j, k;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resource types: ");
    scanf("%d", &m);

    int allocation[n][m], request[n][m], available[m];
    int finish[n];

    // Input Allocation Matrix
    printf("\nEnter Allocation Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    // Input Request Matrix
    printf("\nEnter Request Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &request[i][j]);
        }
    }

    // Input Available Resources
    printf("\nEnter Available Resources:\n");
    for(i = 0; i < m; i++) {
        scanf("%d", &available[i]);
    }

    // Initialize Finish Array
    for(i = 0; i < n; i++) {
        finish[i] = 0;
    }

    int found;

    do {
        found = 0;

        for(i = 0; i < n; i++) {

            if(finish[i] == 0) {

                int possible = 1;

                // Check if request can be satisfied
                for(j = 0; j < m; j++) {
                    if(request[i][j] > available[j]) {
                        possible = 0;
                        break;
                    }
                }

                // If possible, release resources
                if(possible) {

                    for(k = 0; k < m; k++) {
                        available[k] += allocation[i][k];
                    }

                    finish[i] = 1;
                    found = 1;
                }
            }
        }

    } while(found);

    // Check Deadlock
    int deadlock = 0;

    for(i = 0; i < n; i++) {
        if(finish[i] == 0) {
            deadlock = 1;
            printf("\nProcess P%d is deadlocked", i);
        }
    }

    if(deadlock == 0) {
        printf("\n\nNo Deadlock Detected\n");
    }

    return 0;
}
