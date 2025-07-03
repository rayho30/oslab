#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[MAX], bt[MAX], rt[MAX], ct[MAX], tat[MAX], wt[MAX];
    int done[MAX] = {0}, completed = 0, time = 0;
    int twt = 0, ttat = 0;

    for (int i = 0; i < n; i++) {
        printf("P%d Arrival Time: ", i + 1);
        scanf("%d", &at[i]);
        printf("P%d Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    while (completed < n) {
        int idx = -1, min = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && !done[i] && rt[i] < min) {
                min = rt[i];
                idx = i;
            }
        }
        if (idx == -1) {
            time++;
        } else {
            rt[idx]--;
            time++;
            if (rt[idx] == 0) {
                done[idx] = 1;
                completed++;
                ct[idx] = time;
                tat[idx] = ct[idx] - at[idx];
                wt[idx] = tat[idx] - bt[idx];
                ttat += tat[idx];
                twt += wt[idx];
            }
        }
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);

    printf("\nAvg WT: %.2f\nAvg TAT: %.2f\n", (float)twt / n, (float)ttat / n);
    return 0;
}
