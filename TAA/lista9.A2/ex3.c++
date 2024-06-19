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
    queue<int> fila;
    fila.push(1);
    noVisitado[1] = true;

    while (!fila.empty()) {
        int no = fila.front();
        fila.pop();

        for (int vizinho : lista[no]) {
            if (!noVisitado[vizinho]) {
                noVisitado[vizinho] = true;
                fila.push(vizinho);
            }
        }
    }

    bool conectados = true;
    for (int i = 1; i <= N; ++i) {
        if (!noVisitado[i]) {
            conectados = false;
            break;
        }
    }

    if (conectados) {
        cout << "Todo mundo eh amigo de todo mundo" << endl;
    } else {
        cout << "Varios grupos de amigos" << endl;
    }

    return 0;
}
