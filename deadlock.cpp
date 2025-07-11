#include <iostream>
using namespace std;
const int N = 10;

int main() {
    int n, m, A[N][N], M[N][N], Need[N][N], Avail[N], Seq[N];
    bool Finish[N] = {};

    cout << "Processes: "; cin >> n;
    cout << "Resources: "; cin >> m;

    cout << "Allocation:\n";
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            cin >> A[i][j];

    cout << "Max:\n";
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) {
            cin >> M[i][j];
            if (A[i][j] > M[i][j]) {
                cout << "Error at P" << i << " R" << j << endl;
                return -1;
            }
            Need[i][j] = M[i][j] - A[i][j];
        }

    cout << "Available:\n";
    for (int i = 0; i < m; i++) cin >> Avail[i];

    int count = 0;
    while (count < n) {
        bool progress = false;
        for (int i = 0; i < n; i++) {
            if (!Finish[i]) {
                bool canRun = true;
                for (int j = 0; j < m; j++)
                    if (Need[i][j] > Avail[j]) {
                        canRun = false;
                        break;
                    }
                if (canRun) {
                    for (int j = 0; j < m; j++) Avail[j] += A[i][j];
                    Seq[count++] = i;
                    Finish[i] = true;
                    progress = true;
                }
            }
        }
        if (!progress) break;
    }

    if (count == n) {
        cout << "SAFE: ";
        for (int i = 0; i < n; i++) cout << "P" << Seq[i] << " ";
        cout << endl;
    } else {
        cout << "DEADLOCK: ";
        for (int i = 0; i < n; i++)
            if (!Finish[i]) cout << "P" << i << " ";
        cout << endl;
    }
    return 0;
}
