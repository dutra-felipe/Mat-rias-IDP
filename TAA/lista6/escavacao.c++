#include <bits/stdc++.h>

using namespace std;

int contaPedras(const string& bloco) {
    stack<char> pilha;
    int pedra = 0;

    for (char c : bloco) {
        if (c == '<') {
            pilha.push(c);
        } else if (c == '>' && !pilha.empty()) {
            pilha.pop();
            pedra++;
        }
    }

    return pedra;
}

int main() {
    int N;
    cin >> N;
    cin.ignore(); 

    for (int i = 0; i < N; i++) {
        string bloco;
        getline(cin, bloco);
        int pedra = contaPedras(bloco);
        cout << pedra << endl;
    }

    return 0;
}
