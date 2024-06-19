#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    queue<int> descartadas;
    vector<int> descartadas_em_ordem;
 
    for (int i = N; i >= 1; --i) {
        descartadas.push(i);
    }

    while (descartadas.size() > 1) {
        int carta_descartada = descartadas.front();
        descartadas.pop();

        descartadas_em_ordem.push_back(carta_descartada);

        int carta_topo = descartadas.front();
        descartadas.pop();
        descartadas.push(carta_topo);
    }

    cout << "Descarte: ";
    for (int i = 0; i < descartadas_em_ordem.size(); i++) {
        cout << descartadas_em_ordem[i];
        if (i < descartadas_em_ordem.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;
    cout << "Ultima carta: " << descartadas.front() << endl;
    

    return 0;
}
