#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> lista(N + 1);

    while(M--) {
        int U, V;
        cin >> U >> V;
        lista[U].push_back(V);
        lista[V].push_back(U);
    }

    vector<bool> noVisitado(N + 1, false);

    auto busca = [&](int no) {
        stack<int> pilha;
        pilha.push(no);
        noVisitado[no] = true;

        while (!pilha.empty()) {
            int u = pilha.top();
            pilha.pop();

            for (int v : lista[u]) {
                if (!noVisitado[v]) {
                    noVisitado[v] = true;
                    pilha.push(v);
                }
            }
        }
    };

    int gangues = 0;

    for (int i = 1; i <= N; ++i) {
        if (!noVisitado[i]) {
            busca(i);
            gangues++;
        }
    }

    cout << gangues << " gangue(s) no clube da briga" << endl;
    return 0;
}
