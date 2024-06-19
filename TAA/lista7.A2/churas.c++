#include <bits/stdc++.h>

using namespace std;

int main() {
    int A;
    cin >> A;

    set<string> churrasco;

    while(A--) {
        int P;
        cin >> P;

        for (int j = 0; j < P; ++j) {
            string ingrediente;
            cin >> ingrediente;

            if (churrasco.count(ingrediente) == 0) {
                cout << "adicionando " << ingrediente << endl;
                churrasco.insert(ingrediente);
            } else {
                cout << ingrediente << " ja tem" << endl;
            }
        }
    }

    cout << "Itens do churrasco:" << endl;
    for (const auto& item : churrasco) {
        cout << item << endl;
    }

    return 0;
}
