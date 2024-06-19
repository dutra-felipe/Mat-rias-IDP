#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, B;
    cin >> N >> B;

    int bit_activation = 1 << B;

    vector<int> numbers(N);
    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];

        numbers[i] |= bit_activation;
    }

    for (int i = 0; i < N; ++i) {
        cout << numbers[i] << endl;
    }

    return 0;
}
