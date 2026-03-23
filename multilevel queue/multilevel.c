#include <stdio.h>

int main()
{
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int PID[n], AT[n], BT[n], TYPE[n];
    int CT[n], TAT[n], WT[n], ST[n];

    int sysQ[n], userQ[n];
    int sc = 0, uc = 0;

    // -------- Input --------
    for (int i = 0; i < n; i++)
    {
        printf("\nProcess %d\n", i + 1);

        printf("PID: ");
        scanf("%d", &PID[i]);

        printf("Arrival Time: ");
        scanf("%d", &AT[i]);

        printf("Burst Time: ");
        scanf("%d", &BT[i]);

        printf("Type (0 = System, 1 = User): ");
        scanf("%d", &TYPE[i]);

        if (TYPE[i] == 0)
            sysQ[sc++] = i;
        else
            userQ[uc++] = i;
    }

    // -------- Sort System Queue by AT --------
    for (int i = 0; i < sc - 1; i++)
    {
        for (int j = i + 1; j < sc; j++)
        {
            if (AT[sysQ[i]] > AT[sysQ[j]])
            {
                int temp = sysQ[i];
                sysQ[i] = sysQ[j];
                sysQ[j] = temp;
            }
        }
    }

    // -------- Sort User Queue by AT --------
    for (int i = 0; i < uc - 1; i++)
    {
        for (int j = i + 1; j < uc; j++)
        {
            if (AT[userQ[i]] > AT[userQ[j]])
            {
                int temp = userQ[i];
                userQ[i] = userQ[j];
                userQ[j] = temp;
            }
        }
    }

    int time = 0;

    // ===== Execute System Queue (High Priority) =====
    for (int i = 0; i < sc; i++)
    {
        int p = sysQ[i];

        if (time < AT[p])
            time = AT[p];

        ST[p] = time;
        time += BT[p];
        CT[p] = time;

        TAT[p] = CT[p] - AT[p];
        WT[p] = TAT[p] - BT[p];
    }

    // ===== Execute User Queue (Low Priority) =====
    for (int i = 0; i < uc; i++)
    {
        int p = userQ[i];

        if (time < AT[p])
            time = AT[p];

        ST[p] = time;
        time += BT[p];
        CT[p] = time;

        TAT[p] = CT[p] - AT[p];
        WT[p] = TAT[p] - BT[p];
    }

    // -------- Output --------
    printf("\nPID\tAT\tBT\tTYPE\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               PID[i], AT[i], BT[i], TYPE[i],
               CT[i], TAT[i], WT[i]);
    }

    return 0;
}
