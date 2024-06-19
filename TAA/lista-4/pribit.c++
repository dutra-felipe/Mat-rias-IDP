#include <bits/stdc++.h>

using namespace std;

bool verificaPrimo(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

int contaBits(long long int n) {
    int valor = 0;
    while (n) {
        n &= (n - 1);
        valor++;
    }
    return valor;
}

int main() {
    int N;
    cin >> N; 

    for (int i = 0; i < N; ++i) {
        long long int V;
        cin >> V; 

        int numBits = contaBits(V);

        if (verificaPrimo(numBits)) {
            cout << V << " eh um pribit" << endl;
        } else {
            cout << V << " nao eh um pribit" << endl;
        }
    }

    return 0;
}
