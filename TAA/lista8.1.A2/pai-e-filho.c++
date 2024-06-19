#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, C;
    cin >> N >> C;

    vector<int> arvore(N + 1);

    for (int i = 1; i <= N; ++i) {
        cin >> arvore[i];
    }

    for (int i = 0; i < C; ++i) {
        int consulta;
        cin >> consulta;

        int filho_esquerdo = 2 * consulta;
        int filho_direito = 2 * consulta + 1;

        if (consulta == 1 && arvore[1] != -1) {
            cout << "RAIZ - ";
            if (filho_esquerdo <= N && arvore[filho_esquerdo] != -1) {
                cout << arvore[filho_esquerdo] << " ";
            } else {
                cout << "NULL ";
            }
            if (filho_direito <= N && arvore[filho_direito] != -1) {
                cout << arvore[filho_direito] << endl;
            } else {
                cout << "NULL" << endl;
            }
            continue;
        }

        int pai = consulta / 2;


        if(arvore[1] == -1){
            cout << "NULL" << endl;
            break;
        }
        cout << arvore[pai] << " - ";
        if (filho_esquerdo <= N && arvore[filho_esquerdo] != -1) {
            cout << arvore[filho_esquerdo] << " ";
        } else {
            cout << "NULL ";
        }
        if (filho_direito <= N && arvore[filho_direito] != -1) {
            cout << arvore[filho_direito] << endl;
        } else {
            cout << "NULL" << endl;
        }
    }

    return 0;
}
