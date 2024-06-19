#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;

    while (T--) {
        string R, S;
        cin >> R >> S;

        unordered_set<char> baralho(R.begin(), R.end());
        vector<char> cartas;

        for (char c : S) {
            if (baralho.count(c)) {
                if (find(cartas.begin(), cartas.end(), c) == cartas.end()) {
                    cartas.push_back(c);
                }
            }
        }
        if (cartas.empty()) {
            cout << "Baralhos prontos para o duelo" << endl;
        } else {
            sort(cartas.begin(), cartas.end());
            for (char c : cartas) {
                cout << c;
            }
            cout << endl;
        }
    }
    return 0;
}
