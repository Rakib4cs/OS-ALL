
#include <stdio.h>

int main() {
    int n, i, tq;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int p[n], at[n], bt[n], rt[n], ct[n];
    int tat[n], wt[n], visited[n];

    // Input
    for (i = 0; i < n; i++) {
        p[i] = i + 1;

        printf("Enter arrival time of P%d: ", p[i]);
        scanf("%d", &at[i]);

        printf("Enter burst time of P%d: ", p[i]);
        scanf("%d", &bt[i]);

        rt[i] = bt[i];
        visited[i] = 0;
        ct[i] = 0;
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    // Initialization
    int time = 0, completed = 0;
    int queue[100], front = 0, rear = 0;

    // Add first arrived processes
    for (i = 0; i < n; i++) {
        if (at[i] == 0) {
            queue[rear++] = i;
            visited[i] = 1;
        }
    }

    // Round Robin Scheduling
    while (completed < n) {

        // Check empty queue
        if (front == rear) {
            int next = 9999;

            for (i = 0; i < n; i++) {
                if (rt[i] > 0 && at[i] > time && at[i] < next)
                    next = at[i];
            }

            time = next;

            for (i = 0; i < n; i++) {
                if (at[i] <= time && rt[i] > 0 && visited[i] == 0) {
                    queue[rear++] = i;
                    visited[i] = 1;
                }
            }
        }

        int index = queue[front++];

        // Execute process
        if (rt[index] > tq) {
            time += tq;
            rt[index] -= tq;
        }
        else {
            time += rt[index];
            rt[index] = 0;
            ct[index] = time;
            completed++;
        }

        // Add newly arrived processes
        for (i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }

        // Add unfinished process again
        if (rt[index] > 0) {
            queue[rear++] = index;
        }
    }

    // Calculate TAT and WT
    float totalTAT = 0, totalWT = 0;

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        totalTAT += tat[i];
        totalWT += wt[i];

        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nTotal TAT = %.0f", totalTAT);
    printf("\nTotal WT = %.0f", totalWT);
    printf("\nAverage TAT = %.2f", totalTAT / n);
    printf("\nAverage WT = %.2f\n", totalWT / n);

    return 0;
}
