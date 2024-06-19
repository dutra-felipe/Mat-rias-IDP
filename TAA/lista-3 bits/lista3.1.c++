#include <bits/stdc++.h>

using namespace std;

int distanciaHamming(long long x, long long y) {

    int distanciaHamming = 0;
    long long xorResultado = x ^ y;
     while (xorResultado) {
        if (xorResultado & 1) {
            distanciaHamming++;
        }
        xorResultado >>= 1;
    }

    return distanciaHamming;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        long long X, Y;
        cin >> X >> Y;

        cout << distanciaHamming(X, Y) << endl;
    }

    return 0;
}
