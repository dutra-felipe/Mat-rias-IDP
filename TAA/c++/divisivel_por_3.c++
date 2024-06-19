#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char valor[100001];
    int digitos;

    while (true) {
        cin >> digitos;
        if (digitos == -1) {
            break;
        }

        cin >> valor;

        int soma = 0;

        for (int i = 0; i < digitos; i++) {
            soma += valor[i] - '0';
        }

        if (soma % 3 == 0) {
            cout << soma << " sim" << endl;
        } else {
            cout << soma << " nao" << endl;
        }
    }

    return 0;
}
