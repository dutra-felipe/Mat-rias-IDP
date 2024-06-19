#include <bits/stdc++.h>

using namespace std;

int main() {
    char direcao;
    cin >> direcao;

    queue<string> norte, sul, leste, oeste;

    string fila;
    while (cin >> fila && fila != "0") {
        if (fila.length() == 1) {
            direcao = fila[0];
        } else {
            switch (direcao) {
                case 'N':
                    norte.push(fila);
                    break;
                case 'S':
                    sul.push(fila);
                    break;
                case 'L':
                    leste.push(fila);
                    break;
                case 'O':
                    oeste.push(fila);
                    break;
            }
        }
    }

    bool primeiro = true; 
    while (!norte.empty() || !sul.empty() || !leste.empty() || !oeste.empty()) {
        if (!norte.empty()) {
            if (!primeiro) cout << " "; 
            cout << norte.front();
            norte.pop();
            primeiro = false;
        }
        if (!sul.empty()) {
            if (!primeiro) cout << " ";
            cout << sul.front();
            sul.pop();
            primeiro = false;
        }
        if (!leste.empty()) {
            if (!primeiro) cout << " ";
            cout << leste.front();
            leste.pop();
            primeiro = false;
        }
        if (!oeste.empty()) {
            if (!primeiro) cout << " ";
            cout << oeste.front();
            oeste.pop();
            primeiro = false;
        }
    }

    return 0;
}
