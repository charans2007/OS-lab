#include<stdio.h>

int main()
{
    int n,i,time=0,highest;
    int at[10],bt[10],rt[10],pr[10];
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

        printf("Priority: ");
        scanf("%d",&pr[i]);

        rt[i]=bt[i];   // remaining time
    }

    while(completed<n)
    {
        highest=-1;

        for(i=0;i<n;i++)
        {
            if(at[i]<=time && rt[i]>0)
            {
                if(highest==-1 || pr[i]<pr[highest])
                    highest=i;
            }
        }

        if(highest==-1)
        {
            time++;
        }
        else
        {
            rt[highest]--;
            time++;

            if(rt[highest]==0)
            {
                completed++;

                ct[highest]=time;
                tat[highest]=ct[highest]-at[highest];
                wt[highest]=tat[highest]-bt[highest];

                avg_wt+=wt[highest];
                avg_tat+=tat[highest];
            }
        }
    }

    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,at[i],bt[i],pr[i],ct[i],tat[i],wt[i]);
    }

    printf("\nAverage Waiting Time = %.2f",avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n",avg_tat/n);

    return 0;
}
