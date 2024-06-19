/*Valentina é uma mulher muito dedicada e costuma trabalhar até tarde todos os dias. Para economizar tempo, ela faz a lista de compras do mercado em um aplicativo e costuma anotar cada item na mesma hora que percebe a falta dele em casa.

O problema é que o aplicativo não exclui itens duplicados e como Valentina é distraída, anota o mesmo item mais de uma vez e a lista acaba ficando extensa. Sua tarefa como programadora e amiga de Valentina é melhorar o aplicativo de notas desenvolvendo um código que exclua os itens duplicados da lista de compras e que os ordene alfabeticamente.

Entrada
A primeira linha de entrada contém um inteiro N (N < 100) que indica a quantidade de casos de teste que vem a seguir, ou melhor, a quantidade de listas de compras que Valentina quer organizar. Cada lista de compra consiste de uma única linha que contém de 1 a 1000 itens ou palavras compostas apenas de letras minúsculas (de 1 a 20 letras), sem acentos e separadas por um espaço.

Saída
A saída contém N linhas, cada uma representando uma das listas de compras de Valentina, sem itens repetidos e em ordem alfabética.

Exemplo de Entrada
2
carne laranja suco picles laranja picles
laranja pera laranja pera pera

Exemplo de Saída
carne laranja picles suco
laranja pera*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore(); 

    for (int i = 0; i < N; ++i) {
        string linha;
        getline(cin, linha);

        set<string> itens; 
        stringstream ss(linha);
        string item;

        while (ss >> item) {
            itens.insert(item);
        }

        vector<string> listaOrdenada(itens.begin(), itens.end());

        sort(listaOrdenada.begin(), listaOrdenada.end());

        for (size_t j = 0; j < listaOrdenada.size(); ++j) {
            if (j > 0) cout << " ";
            cout << listaOrdenada[j];
        }
        cout << endl;
    }

    return 0;
}
