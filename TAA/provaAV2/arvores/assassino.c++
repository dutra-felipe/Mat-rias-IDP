/*Quem matou Meryn Trant? Quem matou Syrio Forel, se é que ele de fato morreu? Quem matou Stannis Baratheon? Quem matou Myrcella Baratheon? Quem matou Aerys II Targaryen? Quem vai matar (alerta de spoiler!) Jaime Lannister? Para algumas destas perguntas já sabíamos a resposta. Para outras, tínhamos apenas especulações. No entanto, recebemos de um correspondente anônimo uma lista descrevendo vários assassinatos, que já aconteceram ou que estão para acontecer, revelando tanto o nome dos assassinos quanto dos assassinados. Mas os assassinatos não estão em ordem lexicográfica, nem mesmo em ordem cronológica, e fica difícil contar quantas pessoas cada assassino matou. Você pode nos ajudar?

Entrada
Cada linha da entrada descreve um assassinato informando o nome do assassino seguido pelo nome do assassinado. Cada nome é composto por no mínimo um e no máximo 10 caracteres, sendo o primeiro sempre uma letra maiúscula e os demais sempre letras minúsculas. A entrada consiste de no mínimo uma e no máximo 105 linhas e é encerrada em fim de arquivo.

Saída
A primeira linha da saída deve consistir da frase “HALL OF MURDERERS”, sem as aspas. Cada uma das linhas seguintes deve conter um nome de um assassino seguido do número de pessoas que ele matou. A lista de assassinos deve obedecer a ordem lexicográfica. Se um assassino também acabou sendo assassinado, ele não deve figurar na lista.

Exemplo de Entrada	
Arya Meryn
Meryn Syrio
Brienne Stannis
Ellaria Myrcella
Jaime Aerys
Brienne Jaime

Exemplo de Saída
HALL OF MURDERERS
Arya 1
Brienne 2
Ellaria 1*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    string assassino, assassinado;
    map<string, int> assassinos;
    set<string> assassinados;

    while (cin >> assassino >> assassinado) {
        assassinos[assassino]++;
        assassinados.insert(assassinado);
    }

    cout << "HALL OF MURDERERS" << endl;

    vector<string> nomesAssassinos;
    for (const auto& entry : assassinos) {
        if (assassinados.find(entry.first) == assassinados.end()) {
            nomesAssassinos.push_back(entry.first);
        }
    }

    sort(nomesAssassinos.begin(), nomesAssassinos.end());

    for (const string& nome : nomesAssassinos) {
        cout << nome << " " << assassinos[nome] << endl;
    }

    return 0;
}

