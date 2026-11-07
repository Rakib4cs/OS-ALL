#include <stdio.h>
int main() {
    int n, i, j, temp, pos, time = 0;
    float totalTAT = 0, totalWT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int p[n], at[n], bt[n], ct[n], tat[n], wt[n];

    // Input
    for (i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Enter arrival time of P%d: ", p[i]);
        scanf("%d", &at[i]);
        printf("Enter burst time of P%d: ", p[i]);
        scanf("%d", &bt[i]);
    }

    // Sort by arrival time
    for (i = 0; i < n; i++) {
        pos = i;
        for (j = i + 1; j < n; j++) {
            if (at[j] < at[pos])
                pos = j;
        }

        temp = at[i]; at[i] = at[pos]; at[pos] = temp;
        temp = bt[i]; bt[i] = bt[pos]; bt[pos] = temp;
        temp = p[i]; p[i] = p[pos]; p[pos] = temp;
    }

    // FCFS Calculation
    for (i = 0; i < n; i++) {
        if (time < at[i])
            time = at[i];

        ct[i] = time + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        time = ct[i];

        totalTAT += tat[i];
        totalWT += wt[i];
    }

    // Output
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nTotal TAT: %.0f", totalTAT);
    printf("\nTotal WT: %.0f", totalWT);
    printf("\nAverage TAT: %.2f", totalTAT / n);
    printf("\nAverage WT: %.2f\n", totalWT / n);

    return 0;
}
