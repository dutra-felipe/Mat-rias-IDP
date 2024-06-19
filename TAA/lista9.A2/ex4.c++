#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> lista(N + 1);

    while(M--) {
        int U, V, W;
        cin >> U >> V >> W;
        lista[U].push_back({V, W});
        lista[V].push_back({U, W}); 
    }

    vector<int> dist(N + 1, INT_MAX);
    dist[1] = 0; 

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> fila;
    fila.push({0, 1}); 

    while (!fila.empty()) {
        int d = fila.top().first;
        int u = fila.top().second;
        fila.pop();

        if (d > dist[u]) continue;

        for (const auto& borda : lista[u]) {
            int v = borda.first;
            int w = borda.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                fila.push({dist[v], v});
            }
        }
    }

    if (dist[N] == INT_MAX) {
        cout << "Preso no IDP" << endl;
    } else {
        cout << "Distancia para chegar em casa: " << dist[N] << endl;
    }
    return 0;
}
