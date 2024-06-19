#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--) {
        int N, S;
        cin >> N;
        
        vector<int> elementos(N);

        for (int i = 0; i < N; ++i) {
            cin >> elementos[i];
        }

        cin >> S;

        int esq = 0;
        int dir = N - 1;
        bool encontrado = false;
        
        while (esq < dir) {
            int soma = elementos[esq] + elementos[dir];
            if (soma == S) {
                encontrado = true;
                break;
            } else if (soma < S) {
                esq++;
            } else {
                dir--;
            }
        }

        if(encontrado) {
            cout << "SIM" << endl;
        }else {
            cout << "NAO" << endl;
        }
    }

    return 0;
}
