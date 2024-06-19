#include <iostream>

using namespace std;

bool verifica_primo(int n) {
    if (n < 2) {
        return false;
    }
    if (n == 2 || n == 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

bool verifica_gemeo(int n) {
    if (!verifica_primo(n))
        return false;

    return verifica_primo(n + 2) || verifica_primo(n - 2);
}

int main() {
    const int MAX_VALUE = 10000; 
    int n;
    cin >> n;

    int valor[MAX_VALUE]; 

    for (int i = 0; i < n; i++) {
        cin >> valor[i];
    }

    for (int i = 0; i < n; i++) {
        if (verifica_gemeo(valor[i])) {
            cout << "O numero " << valor[i] << " eh um primo gemeo" << endl;
        } else {
            cout << "O numero " << valor[i] << " nao eh um primo gemeo" << endl;
        }
    }

    return 0;
}
