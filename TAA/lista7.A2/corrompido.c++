#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;

    for (int j = 0; j < T; ++j) {
        int L;
        cin >> L;

        map<pair<int, string>, int> registro;

        int erros = 0;

        for (int i = 0; i < L; ++i) {
            int matricula;
            string disciplina;
            cin >> matricula >> disciplina;

            if (registro[{matricula, disciplina}] == 1) {
                erros++;
            } else {
                registro[{matricula, disciplina}] = 1;
            }
        }

        if (erros == 0) {
            cout << "Arquivo OK" << endl;
        } else {
            cout << "Corrompido com " << erros << " erro(s)" << endl;
        }
    }

    return 0;
}
