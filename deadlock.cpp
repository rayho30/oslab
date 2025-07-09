#include <iostream>
using namespace std;

#define MAX 100

int main() {
    int n, m, Alloc[MAX][MAX], Max[MAX][MAX], Need[MAX][MAX], Avail[MAX], Finish[MAX] = {0}, SafeSeq[MAX];

    cout << "Processes and resource types: ";
    cin >> n >> m;
    cout<<"allocation matrix:\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        cin>>Alloc[i][j];

     cout << "Max Matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> Max[i][j];
            if (Alloc[i][j] > Max[i][j]) return cout << "Error at P" << i << " R" << j << endl, -1;
            Need[i][j] = Max[i][j] - Alloc[i][j];
        }
        cout<<"available resources: ";
        for(int i=0;i<m;i++) cin>>Avail[i];

        int count = 0;
        while  (count<n){
            bool progress = false;
            for(int i=0;i<n;i++){
                if (!Finish[i]) {
                bool canRun = true;
                for (int j = 0; j < m; j++)
                    if (Need[i][j] > Avail[j]) canRun = false;
                if (canRun) {
                    for (int j = 0; j < m; j++) Avail[j] += Alloc[i][j];
                    SafeSeq[count++] = i;
                    Finish[i] = 1;
                    progress = true;
                }
            }
        }
        if (!progress) break;
        }
        if(count == n){
            cout<<"Safe.Sequence:";
            for (int i = 0; i < n; i++) cout << "P" << SafeSeq[i] << " ";

        }else{
        cout<<"Deadlock!Process:";
        for(int i=0;i<n;i++) if(!Finish[i]) cout<< "p" <<i<<" ";
        }
        return 0;

}
