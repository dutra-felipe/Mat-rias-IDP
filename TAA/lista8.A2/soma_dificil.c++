#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    long long K;
    cin >> N >> K;

    vector<long long> elementos(N);
    for (int i = 0; i < N; ++i) {
        cin >> elementos[i];
    }

    sort(elementos.begin(), elementos.end());

    for (int i = 0; i < N - 2; ++i) {
        int esq = i + 1;
        int dir = N - 1;
        
        while (esq < dir) {
            long long soma = elementos[i] + elementos[esq] + elementos[dir];
            if (soma == K) {
                cout << elementos[i] << " " << elementos[esq] << " " << elementos[dir] << endl;
                return 0;
            } else if (soma < K) {
                ++esq;
            } else {
                --dir;
            }
        }
    }

    cout << "Nao existe" << endl;
    return 0;
}