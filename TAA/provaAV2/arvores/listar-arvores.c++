/*Coníferas e folhosas (softwoods e hardwoods) são dois grandes grupos de vegetais produtores de madeira. As folhosas são aquele grupo de árvores que têm folhas largas, produzem uma fruta ou castanha e geralmente ficam dormentes no inverno. Os climas temperados da América produzem florestas com centenas de espécies de madeira de lei - árvores que compartilham certas características biológicas. Embora o carvalho, bordo e cereja sejam tipos de árvores de madeira de lei, são espécies diferentes. Juntas, todas as espécies de madeira folhosas representam 40 por cento das árvores nos Estados Unidos.

Por outro lado, as madeiras macias (Softwoods) ou coníferas, chamadas "cone-bearing", são resinosas amplamente disponíveis EUA. Incluem cedro, abeto, cicuta, pinho, abeto vermelho e cipreste. Em uma casa, os resinosas são utilizados principalmente como madeira de viga estrutural, mas também podem ser utilizadas em algumas aplicações decorativas.

Usando tecnologia de imagem por satélite, o Departamento de Recursos Naturais elaborou um inventário de todas as árvores de um local específico em um determinado dia. Você deverá calcular a fração da população de cada árvore representada por cada uma das espécies.

Entrada
A entrada possui vários casos de teste. A primeira linha de entrada contém um inteiro N que indica o número de casos de teste, seguido por uma linha em branco. Cada caso de teste consiste de uma lista com a espécie de cada árvore observada pelo satélite, uma árvore por linha. Nenhum nome de espécie é superior a 30 caracteres. Não existem mais de 10.000 espécies e não mais de 1.000.000 árvores. Há uma linha em branco entre cada caso de teste consecutivo.

Saída
Para cada caso de teste imprima o nome de cada espécie representada na população, em ordem alfabética, seguida pelo percentual da população que representa, com 4 casas decimais. Imprima uma linha em branco entre dois conjuntos de dados consecutivos.

Exemplo de Entrada	
2

Red Alder
Ash
Aspen
Basswood
Ash
Beech
Yellow Birch
Ash
Cherry
Cottonwood
Ash
Cypress
Red Elm
Gum
Hackberry
White Oak
Hickory
Pecan
Hard Maple
White Oak
Soft Maple
Red Oak
Red Oak
White Oak
Poplan
Sassafras
Sycamore
Black Walnut
Willow

Red Alder
Ash

Exemplo de Saída
Ash 13.7931
Aspen 3.4483
Basswood 3.4483
Beech 3.4483
Black Walnut 3.4483
Cherry 3.4483
Cottonwood 3.4483
Cypress 3.4483
Gum 3.4483
Hackberry 3.4483
Hard Maple 3.4483
Hickory 3.4483
Pecan 3.4483
Poplan 3.4483
Red Alder 3.4483
Red Elm 3.4483
Red Oak 6.8966
Sassafras 3.4483
Soft Maple 3.4483
Sycamore 3.4483
White Oak 10.3448
Willow 3.4483
Yellow Birch 3.4483

Ash 50.0000
Red Alder 50.0000

*/

#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int T;
    string arvore;
   
    cin >> T;
    getline(cin, arvore);
    getline(cin, arvore);

    for (int t = 0; t < T; ++t) {
        map<string, int> qtdArvore;
        int total = 0;

        while (getline(cin, arvore) && !arvore.empty()) {
            qtdArvore[arvore]++;
            total++;
        }

        vector<string> especies;
        for (const auto &par : qtdArvore) {
            especies.push_back(par.first);
        }
        sort(especies.begin(), especies.end());

        for (const string &nome : especies) {
            double percentual = (qtdArvore[nome]  * 100.0) / total;
            cout << nome << " " << fixed << setprecision(4) << percentual << endl;
        }

        if (t < T - 1) {
            cout << endl;
        }
    }

    return 0;
}
