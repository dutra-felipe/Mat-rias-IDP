#include <iostream>

using namespace std;

unsigned long long trocaBits(unsigned long long N, int P, int Q) {
    if (((N >> P) & 1) != ((N >> Q) & 1)) {
        N ^= (1ULL << P); 
        N ^= (1ULL << Q); 
    }
    return N;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        unsigned long long N;
        int P, Q;
        cin >> N >> P >> Q;

        unsigned long long modificaNumero = trocaBits(N, P, Q);

        cout << modificaNumero << endl;
    }

    return 0;
}
