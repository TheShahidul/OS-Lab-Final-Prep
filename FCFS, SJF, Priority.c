//FCFS//

#include <stdio.h>

int main() {
    int p[20], bt[20], wt[20], tat[20], i, n;
    float wtavg, tatavg;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("\n");

    for(i = 0; i < n; i++) {
        printf("Enter the Burst Time for Process P%d: ", i);
        scanf("%d", &bt[i]);
    }

    wt[0] = wtavg = 0;
    tat[0] = tatavg = bt[0];

    for(i = 1; i < n; i++) {
        wt[i] = tat[i - 1];
        tat[i] = bt[i] + wt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }

    printf("\nPROCESS\t\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", i, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %f\n", wtavg / n);
    printf("Average Turnaround Time: %f\n", tatavg / n);

    return 0;
}



//SJF//

#include <stdio.h>
#include <conio.h>

int main() {
    int p[20], bt[20], wt[20], tat[20], i, k, n, temp;
    float wtavg, tatavg;

    printf("\nEnter the number of processes: ");
    scanf("%d", &n);
    printf("\n");

    for(i = 0; i < n; i++) {
        p[i] = i;
        printf("Enter Burst Time for Process P%d: ", i);
        scanf("%d", &bt[i]);
    }

    for(i = 0; i < n; i++) {
        for(k = i + 1; k < n; k++) {
            if(bt[i] > bt[k]) {
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;

                temp = p[i];
                p[i] = p[k];
                p[k] = temp;
            }
        }
    }

    wt[0] = wtavg = 0;
    tat[0] = tatavg = bt[0];

    for(i = 1; i < n; i++) {
        wt[i] = tat[i - 1];
        tat[i] = wt[i] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }

    printf("\nPROCESS\t\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %f\n", wtavg / n);
    printf("Average Turnaround Time: %f\n", tatavg / n);

    getch();
    return 0;
}


//priority


#include <stdio.h>

int main() {
    int p[20], bt[20], wt[20], tat[20], pri[20], i, j, n;
    float wtavg, tatavg;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("\n");

    for (i = 0; i < n; i++) {
        printf("Enter the Burst Time for process %d: ", i + 1);
        scanf("%d", &bt[i]);
        printf("Enter the Priority for process %d: ", i + 1);
        scanf("%d", &pri[i]);
        p[i] = i + 1; 
    }
                        //shahidul_213902017

  
  
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (pri[j] > pri[j + 1] || (pri[j]==pri[j+1] && bt[j] > bt[j+1])) {
                int temp = pri[j];
                pri[j] = pri[j + 1];
                pri[j + 1] = temp;

                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    wtavg = 0;
    tatavg = 0;
    wt[0] = 0;

    tat[0]=bt[0];

    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }

    printf("\nProcess \tBurst \tPriority \tWaiting \tT.Around \n");

    for (i = 0; i < n; i++) {
        printf("\nP%d \t\t\t%d \t\t\t%d \t\t\t%d \t\t\t%d ", p[i], bt[i], pri[i], wt[i], tat[i]);
    }
    printf("\n\n");
    printf("Average Waiting Time: %f\n", wtavg / n);
    printf("Average Turnaround Time: %f\n", tatavg / n);

    return 0;
}

