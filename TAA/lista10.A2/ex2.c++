#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> matriz(N + 1);

    while(M--) {
        int A, B;
        cin >> A >> B;
        matriz[A].push_back(B);
        matriz[B].push_back(A);
    }

    vector<bool> check(N + 1, false);
    int maiorGrupo = 0;

    for (int i = 1; i <= N; ++i) {
        if (!check[i]) {
            queue<int> fila;
            fila.push(i);
            check[i] = true;
            int grupo = 0;

            while (!fila.empty()) {
                int no = fila.front();
                fila.pop();
                grupo++;

                for (int noVizinho : matriz[no]) {
                    if (!check[noVizinho]) {
                        check[noVizinho] = true;
                        fila.push(noVizinho);
                    }
                }
            }
            maiorGrupo = max(maiorGrupo, grupo);
        }
    }
    cout << "O grupo mais numeroso tem " << maiorGrupo << " aluno(s)" << endl;

    return 0;
}
