#include <bits/stdc++.h>

using namespace std;

struct Pokemon {
    string nome;
    int forca;
    int index;

    bool operator<(const Pokemon& prox) const {
    if (forca == prox.forca) {
        if (nome == prox.nome) {
            return index < prox.index;
        }
        return nome < prox.nome;
    }
    return forca < prox.forca;
}

};

int main() {
    int P;
    cin >> P;
    vector<Pokemon> pokemons(P);

    for (int i = 0; i < P; ++i) {
        cin >> pokemons[i].nome >> pokemons[i].forca;
        pokemons[i].index = i;
    }

    priority_queue<Pokemon> pq(pokemons.begin(), pokemons.end());
    vector<string> resultados;

    while (pq.size() > 1) {
        Pokemon p1 = pq.top(); pq.pop();
        Pokemon p2 = pq.top(); pq.pop();

        if (p1.forca == p2.forca) {
            resultados.push_back(p1.nome + " (" + to_string(p1.forca) + ") x (" + to_string(p2.forca) + ") " + p2.nome + " : empate");
        } else {
            if (p1.forca > p2.forca) {
                resultados.push_back(p1.nome + " (" + to_string(p1.forca) + ") x (" + to_string(p2.forca) + ") " + p2.nome + " : " + p1.nome + " venceu");
                p1.forca -= p2.forca;
                pq.push(p1);
            } 
            else {
                resultados.push_back(p2.nome + " (" + to_string(p2.forca) + ") x (" + to_string(p1.forca) + ") " + p1.nome + " : " + p2.nome + " venceu");
                p2.forca -= p1.forca;
                pq.push(p2);
            }
        }
    }

    if (!pq.empty()) {
        Pokemon vencedor = pq.top();
        resultados.push_back(vencedor.nome + " venceu com " + to_string(vencedor.forca));
    } else {
        resultados.push_back("nenhum vencedor");
    }

    for (const auto& x : resultados) {
        cout << x << endl;
    }

    return 0;
}
