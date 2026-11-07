
#include <stdio.h>

int main() {
    int n, i, j, temp, pos;
    int time = 0, completed = 0;
    float totalTAT = 0, totalWT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int p[n], at[n], bt[n], rt[n], ct[n], tat[n], wt[n], done[n];

    // Input
    for (i = 0; i < n; i++) {
        p[i] = i + 1;

        printf("Enter arrival time of P%d: ", p[i]);
        scanf("%d", &at[i]);

        printf("Enter burst time of P%d: ", p[i]);
        scanf("%d", &bt[i]);

        rt[i] = bt[i];
        done[i] = 0;
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
        temp = rt[i]; rt[i] = rt[pos]; rt[pos] = temp;
        temp = p[i]; p[i] = p[pos]; p[pos] = temp;
    }

    // SRTF Scheduling
    while (completed < n) {
        int min = 9999, index = -1;

        // Find shortest remaining time
        for (i = 0; i < n; i++) {
            if (at[i] <= time && done[i] == 0) {
                if (rt[i] < min) {
                    min = rt[i];
                    index = i;
                }
            }
        }

        if (index != -1) {
            rt[index]--;
            time++;

            if (rt[index] == 0) {
                ct[index] = time;
                tat[index] = ct[index] - at[index];
                wt[index] = tat[index] - bt[index];

                totalTAT += tat[index];
                totalWT += wt[index];

                done[index] = 1;
                completed++;
            }
        }
        else {
            time++;
        }
    }

    // Average
    float avgTAT = totalTAT / n;
    float avgWT = totalWT / n;

    // Output
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nTotal TAT = %.0f", totalTAT);
    printf("\nTotal WT = %.0f", totalWT);
    printf("\nAverage TAT = %.2f", avgTAT);
    printf("\nAverage WT = %.2f\n", avgWT);

    return 0;
}
