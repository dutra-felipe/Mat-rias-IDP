#include <iostream>

using namespace std;

int main() {
    long long int N;
    cin >> N;

    long long int somaEsperada = (N * (N + 1)) / 2;
    long long int somaPermutacao = 0;

    for (int i = 0; i < N - 1; i++) {
        long long int input = 0;
        cin >> input;
        somaPermutacao += input;
    }

    cout << somaEsperada - somaPermutacao;

    return 0;
}