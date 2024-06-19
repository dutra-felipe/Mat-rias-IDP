#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, C, E, F;
    cin >> N >> M;

    vector<vector<int>> lista(N + 1);

    while(M--) {
        int A, B;
        cin >> A >> B;
        lista[A].push_back(B);
        lista[B].push_back(A);
    }

    cin >> C >> E >> F;

    auto bfs = [&](int src) {
        vector<int> dist(N + 1, INT_MAX);
        queue<int> fila;
        fila.push(src);
        dist[src] = 0;

        while (!fila.empty()) {
            int u = fila.front();
            fila.pop();

            for (int v : lista[u]) {
                if (dist[v] == INT_MAX) {
                    dist[v] = dist[u] + 1;
                    fila.push(v);
                }
            }
        }
        return dist;
    };

    vector<int> distC = bfs(C);
    vector<int> distE = bfs(E);
    int distTotal = distC[E] + distE[F];

    cout << distTotal << endl;

    return 0;
}
