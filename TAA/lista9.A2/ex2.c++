#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    cin >> M >> N;

    vector<vector<int>> adj(M + 1);

    while (N--) {
        int X, Y;
        cin >> X >> Y;
        adj[X].push_back(Y);
        adj[Y].push_back(X);
    }

    vector<int> distancia(M + 1, INT_MAX);
    distancia[1] = 0;

    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (distancia[v] == INT_MAX) {
                distancia[v] = distancia[u] + 1;
                q.push(v);
            }
        }
    }

    if (distancia[M] == INT_MAX) {
        cout << -1 << endl; 
    } else {
        cout << distancia[M] << endl; 
    }

    return 0;
}
