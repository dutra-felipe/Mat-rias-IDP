#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, C;
    cin >> N >> C;

    vector<int> arvore(N + 1);

    for (int i = 1; i <= N; ++i) {
        cin >> arvore[i];
    }

    for (int i = 0; i < C; ++i) {
        int consulta;
        cin >> consulta;

        if (arvore[1] == -1) {
            cout << "NULL" << endl;
            break;
        }

        if (consulta == 1 && arvore[1] != -1) {
            cout << "RAIZ" << endl;
            continue;
        }

        int pai = consulta / 2;

        cout << arvore[pai] << endl;
    }

    return 0;
}
