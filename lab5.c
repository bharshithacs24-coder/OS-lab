#include <stdio.h>



int main() {
    int n;
    int PID[30], AT[30], BT[30], TYPE[30];
    int CT[30], TAT[30], WT[30], Start[30];

    int sysQueue[30], userQueue[30];
    int sysCount = 0, userCount = 0;

    int i, j, temp;
    int time = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);


    for(i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);
        printf("PID: ");
        scanf("%d", &PID[i]);
        printf("Arrival Time: ");
        scanf("%d", &AT[i]);
        printf("Burst Time: ");
        scanf("%d", &BT[i]);
        printf("Type (0 = System, 1 = User): ");
        scanf("%d", &TYPE[i]);
    }


    for(i = 0; i < n; i++) {
        if(TYPE[i] == 0)
            sysQueue[sysCount++] = i;
        else
            userQueue[userCount++] = i;
    }


    for(i = 0; i < sysCount - 1; i++) {
        for(j = i + 1; j < sysCount; j++) {
            if(AT[sysQueue[i]] > AT[sysQueue[j]]) {
                temp = sysQueue[i];
                sysQueue[i] = sysQueue[j];
                sysQueue[j] = temp;
            }
        }
    }


    for(i = 0; i < userCount - 1; i++) {
        for(j = i + 1; j < userCount; j++) {
            if(AT[userQueue[i]] > AT[userQueue[j]]) {
                temp = userQueue[i];
                userQueue[i] = userQueue[j];
                userQueue[j] = temp;
            }
        }
    }


    for(i = 0; i < sysCount; i++) {
        int p = sysQueue[i];

        if(time < AT[p])
            time = AT[p];

        Start[p] = time;
        time += BT[p];
        CT[p] = time;

        TAT[p] = CT[p] - AT[p];
        WT[p] = TAT[p] - BT[p];
    }


    for(i = 0; i < userCount; i++) {
        int p = userQueue[i];

        if(time < AT[p])
            time = AT[p];

        Start[p] = time;
        time += BT[p];
        CT[p] = time;

        TAT[p] = CT[p] - AT[p];
        WT[p] = TAT[p] - BT[p];
    }


    printf("\n\nPID\tAT\tBT\tTYPE\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
            PID[i], AT[i], BT[i], TYPE[i],
            CT[i], TAT[i], WT[i]);
    }

    return 0;
}
