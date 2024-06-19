#include <bits/stdc++.h>

using namespace std;

bool terminaExercicios(vector<int>& exercicios, int sessao, int horas) {
    long long totalhoras = 0;
    for (int numexercicios : exercicios) {
        totalhoras += (numexercicios + sessao - 1) / sessao; 
    }
    return totalhoras <= horas;
}

int main() {
    int N, H;
    cin >> N >> H;

    vector<int> exercicios(N);
    for (int i = 0; i < N; ++i) {
        cin >> exercicios[i];
    }

    int esq = 1, dir = *max_element(exercicios.begin(), exercicios.end());
    while (esq < dir) {
        int meio = esq + (dir - esq) / 2;
        if (terminaExercicios(exercicios, meio, H)) {
            dir = meio;
        } else {
            esq = meio + 1;
        }
    }

    cout << esq << endl;

    return 0;
}
