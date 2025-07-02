#include <stdio.h>
#include <limits.h>

struct Process {
    int id, at, bt, ct, wt, tat;
};

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];
    int done[n], time = 0, completed = 0, twt = 0, ttat = 0;

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("P%d Arrival Time: ", p[i].id);
        scanf("%d", &p[i].at);
        printf("P%d Burst Time: ", p[i].id);
        scanf("%d", &p[i].bt);
        done[i] = 0;
    }

    while (completed < n) {
        int idx = -1, min_bt = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (!done[i] && p[i].at <= time && p[i].bt < min_bt) {
                min_bt = p[i].bt;
                idx = i;
            }
        }
        if (idx == -1) {
            time++;
        } else {
            time += p[idx].bt;
            p[idx].ct = time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            twt += p[idx].wt;
            ttat += p[idx].tat;
            done[idx] = 1;
            completed++;
        }
    }

    // Sort by Completion Time (execution order)
    for (int i = 0; i < n - 1; i++) {
       for (int j = 0; j < n - i - 1; j++) {
           if (p[j].ct > p[j + 1].ct) {
               struct Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    printf("\nP\tAT\tBT\tCT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].wt, p[i].tat);
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)twt / n);
    printf("Average Turnaround Time: %.2f\n", (float)ttat / n);

    return 0;
}
