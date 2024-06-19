#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, C;
    cin >> V >> C;

    vector<vector<int>> matriz(V, vector<int>(V, 0));

    while(C--) {
        int A, B;
        cin >> A >> B;
        A--;
        B--;
        matriz[A][B] = 1;
        matriz[B][A] = 1;  
    }

    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cout << matriz[i][j];
            if (j < V - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}
