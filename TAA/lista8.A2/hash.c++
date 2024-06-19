#include <bits/stdc++.h>

using namespace std;

int main() {
    int M, C;
    cin >> M >> C;

    vector<list<int>> hash(M);

    for (int i = 0; i < C; ++i) {
        int chave;
        cin >> chave;
        int index = chave % M;
        hash[index].push_back(chave);
    }

    for (int i = 0; i < M; ++i) {
        cout << i << " ->";
        for (int chave : hash[i]) {
            cout << " " << chave << " ->";
        }
        cout << " \\" << endl;  
    }

    return 0;
}