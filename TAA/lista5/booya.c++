#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int F, D;
    cin >> F >> D;

    vector<int> S(30);
    for (int i = 0; i < 30; ++i) {
        cin >> S[i];
    }

    long long int previsao = F;

    for (int i = 0; i < D; ++i) {
        long double soma = 0;
        for (int j = 0; j < 30; ++j) {
            soma += S[j];
        }
        long long int media = ceil(soma / 30);

        previsao += media;

        for (int j = 0; j < 29; ++j) {
            S[j] = S[j + 1];
        }
        S[29] = media; 
    }

    cout << previsao << endl;

    return 0;
}
