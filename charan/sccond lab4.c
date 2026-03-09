#include <stdio.h>

int main()
{
    int n,i,j;
    int at[10],bt[10],pr[10];
    int ct[10],wt[10],tat[10],pid[10];
    int temp;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        pid[i]=i+1;

        printf("\nProcess %d\n",i+1);

        printf("Arrival Time: ");
        scanf("%d",&at[i]);

        printf("Burst Time: ");
        scanf("%d",&bt[i]);

        printf("Priority: ");
        scanf("%d",&pr[i]);
    }

    // Sorting based on Priority
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(pr[i] > pr[j])
            {
                temp=pr[i]; pr[i]=pr[j]; pr[j]=temp;

                temp=bt[i]; bt[i]=bt[j]; bt[j]=temp;

                temp=at[i]; at[i]=at[j]; at[j]=temp;

                temp=pid[i]; pid[i]=pid[j]; pid[j]=temp;
            }
        }
    }

    ct[0]=at[0]+bt[0];

    for(i=1;i<n;i++)
        ct[i]=ct[i-1]+bt[i];

    for(i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }

    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        pid[i],at[i],bt[i],pr[i],ct[i],tat[i],wt[i]);
    }

    return 0;
}
