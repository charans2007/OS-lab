#include <stdio.h>

int main() {
    int ref[] = {7,0,1,2,0,3,0,4,2,3,0,3,2};
    int fr[3], time[3];
    int i, j, k, pos, max;
    int f = 3, n = 13, pf;

    // FIFO
    for(i=0;i<f;i++)
        fr[i] = -1;

    pf = 0;
    k = 0;

    for(i=0;i<n;i++) {
        for(j=0;j<f;j++)
            if(fr[j] == ref[i])
                break;

        if(j == f) {
            fr[k] = ref[i];
            k = (k + 1) % f;
            pf++;
        }
    }

    printf("FIFO Page Faults = %d\n", pf);

    // LRU
    for(i=0;i<f;i++) {
        fr[i] = -1;
        time[i] = -1;
    }

    pf = 0;

    for(i=0;i<n;i++) {

        for(j=0;j<f;j++) {
            if(fr[j] == ref[i]) {
                time[j] = i;
                break;
            }
        }

        if(j == f) {
            pos = 0;

            for(j=1;j<f;j++)
                if(time[j] < time[pos])
                    pos = j;

            fr[pos] = ref[i];
            time[pos] = i;
            pf++;
        }
    }

    printf("LRU Page Faults = %d\n", pf);

    // Optimal
    for(i=0;i<f;i++)
        fr[i] = -1;

    pf = 0;

    for(i=0;i<n;i++) {

        for(j=0;j<f;j++)
            if(fr[j] == ref[i])
                break;

        if(j == f) {

            pos = -1;

            // Empty frame check
            for(j=0;j<f;j++) {
                if(fr[j] == -1) {
                    pos = j;
                    break;
                }
            }

            // If no empty frame
            if(pos == -1) {
                max = -1;

                for(j=0;j<f;j++) {

                    for(k=i+1;k<n;k++)
                        if(fr[j] == ref[k])
                            break;

                    if(k > max) {
                        max = k;
                        pos = j;
                    }
                }
            }

            fr[pos] = ref[i];
            pf++;
        }
    }

    printf("Optimal Page Faults = %d\n", pf);

    return 0;
}
