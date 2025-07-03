#include <stdio.h>

int main() {
    int n;
    printf("No. of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], tat[n], wt[n], id[n], ttat = 0, twt = 0;

    for (int i = 0; i < n; i++) {
        id[i] = i + 1;
        printf("P%d Arrival Time: ", id[i]);
        scanf("%d", &at[i]);
        printf("P%d Burst Time: ", id[i]);
        scanf("%d", &bt[i]);
    }

    // Sort by arrival time
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (at[j] > at[j + 1]) {
                int t;
                t = at[j], at[j] = at[j + 1], at[j + 1] = t;
                t = bt[j], bt[j] = bt[j + 1], bt[j + 1] = t;
                t = id[j], id[j] = id[j + 1], id[j + 1] = t;
            }

    int time = 0;
    for (int i = 0; i < n; i++) {
        if (time < at[i]) time = at[i];
        ct[i] = time + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        time = ct[i];
        ttat += tat[i];
        twt += wt[i];
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", id[i], at[i], bt[i], ct[i], tat[i], wt[i]);

    printf("\nAvg WT: %.2f\nAvg TAT: %.2f\n", (float)twt / n, (float)ttat / n);
    return 0;
}
