#include <bits/stdc++.h>

using namespace std;

int buscaNotas(vector<int>& nota, int alvo) {
    int esq = 0;
    int dir = nota.size() - 1;
    int numero = -1;

    while (esq <= dir) {
        int meio = esq + (dir - esq) / 2;

        if (nota[meio] > alvo) {
            numero = meio;
            dir = meio - 1; 
        } else {
            esq = meio + 1; 
        }
    }

    return numero != -1 ? nota.size() - numero : 0;
}

int main() {
    ios_base::sync_with_stdio(false);

    int A, Q;
    cin >> A >> Q;

    vector<int> nota(A);
    for (int i = 0; i < A; ++i) {
        cin >> nota[i];
    }

    for (int i = 0; i < Q; ++i) {
        int media;
        cin >> media;
        int numAbove = buscaNotas(nota, media);
        cout << numAbove << " notas maiores que " << media << endl;
    }

    return 0;
}
