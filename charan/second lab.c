#include<stdio.h>

int main()
{
    int n,i,time=0,smallest;
    int at[10],bt[10],rt[10];
    int ct[10],wt[10],tat[10];
    int completed=0;
    float avg_wt=0,avg_tat=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\nProcess %d\n",i+1);

        printf("Arrival Time: ");
        scanf("%d",&at[i]);

        printf("Burst Time: ");
        scanf("%d",&bt[i]);

        rt[i]=bt[i];   // remaining time
    }

    while(completed<n)
    {
        smallest=-1;

        for(i=0;i<n;i++)
        {
            if(at[i]<=time && rt[i]>0)
            {
                if(smallest==-1 || rt[i]<rt[smallest])
                    smallest=i;
            }
        }

        if(smallest==-1)
        {
            time++;
        }
        else
        {
            rt[smallest]--;
            time++;

            if(rt[smallest]==0)
            {
                completed++;

                ct[smallest]=time;
                tat[smallest]=ct[smallest]-at[smallest];
                wt[smallest]=tat[smallest]-bt[smallest];

                avg_wt+=wt[smallest];
                avg_tat+=tat[smallest];
            }
        }
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }

    printf("\nAverage Waiting Time = %.2f",avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n",avg_tat/n);

    return 0;
}
