#include <bits/stdc++.h>

using namespace std;

struct Aresta {
    int u, v, distancia;
};

int localiza(int u, vector<int>& parente) {
    return (parente[u] == u) ? u : (parente[u] = localiza(parente[u], parente));
}

void uniao(int u, int v, vector<int>& parente, vector<int>& rank) {
    int raizU = localiza(u, parente);
    int raizV = localiza(v, parente);
    if (raizU != raizV) {
        if (rank[raizU] > rank[raizV]) {
            parente[raizV] = raizU;
        } else if (rank[raizU] < rank[raizV]) {
            parente[raizU] = raizV;
        } else {
            parente[raizV] = raizU;
            rank[raizU]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int M, N;
        cin >> M >> N;
        vector<Aresta> arestas(N);
        for (auto& aresta : arestas) {
            cin >> aresta.u >> aresta.v >> aresta.distancia;
        }
        sort(arestas.begin(), arestas.end(), [](const Aresta& a, const Aresta& b) {
            return a.distancia < b.distancia;
        });
        vector<int> parente(M + 1), rank(M + 1, 0);
        for (int i = 1; i <= M; ++i) parente[i] = i;
        int fio = 0;
        for (const auto& aresta : arestas) {
            if (localiza(aresta.u, parente) != localiza(aresta.v, parente)) {
                fio += aresta.distancia;
                uniao(aresta.u, aresta.v, parente, rank);
            }
        }
        cout << fio << endl;
    }
    return 0;
}
