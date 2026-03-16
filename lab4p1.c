#include <stdio.h>

int main() {
    int n, i, time, remain, flag;
    int tq1;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n];
    int ct[n], tat[n], wt[n];

    printf("\nEnter Arrival Time and Burst Time:\n");

    for(i = 0; i < n; i++) {
        printf("P%d Arrival Time: ", i+1);
        scanf("%d", &at[i]);

        printf("P%d Burst Time: ", i+1);
        scanf("%d", &bt[i]);

        rt[i] = bt[i];
    }

    printf("\nEnter Time Quantum for Output 1: ");
    scanf("%d", &tq1);





    for(i = 0; i < n; i++)
            rt[i] = bt[i];

        time = 0;
        remain = n;
        flag = 0;

        printf("\n===== Round Robin (Time Quantum = %d) =====\n", tq1);

        while(remain != 0)
        {
            for(i = 0; i < n; i++) {
              if(at[i] <= time && rt[i] > 0) {
                if(rt[i] <= tq1) {
                   time += rt[i];
                   rt[i] = 0;
                   ct[i] = time;
                   tat[i] = ct[i] - at[i];
                   wt[i] = tat[i] - bt[i];
                   remain--;
                 }
              else {
                  rt[i] -= tq1;
                  time += tq1;
              }
            }
          }

        }
        float awt=0,atat=0;
        printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
        for(i = 0; i < n; i++) {
           printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
           i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
           awt+=wt[i];
           atat+=tat[i];
        }
        printf("avg wt=%f",awt/n);
        printf("avg tat= %f",atat/n);

    return 0;
}
