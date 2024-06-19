/*Segundo a tradição, as provas das Olimpíadas de Natal são muito interessantes e diferentes. Dentre as provas existentes, podemos citar por exemplo, o levantamento de saco de brinquedos, a escalada de pinheiros, o hipismo com renas, o arremesso de duendes (com e sem o consentimento deles - esse segundo é mais perigoso) e o tempo de mergulho em buraco no gelo sem equipamentos, entre outros.

Parte do melhoramento da competição proposto por Noel para este ano sera a disponibilização do quadro de medalhas dos países participantes através de um placar eletrônico. Você foi convidado para viajar até as montanhas de Korvatunturi na Lapônia, Finlândia, aonde será a sede destes jogos, para, à partir de uma relação das provas e os países vencedores, desenvolver o sistema para este placar.

Serão quase trezentos países participantes e até 1000 modalidades de provas, no máximo.

Entrada
A entrada contem um unico caso de teste que consiste em uma relacao com o resultado de todas as provas realizadas nas Olimpíadas de Natal. Cada prova ou modalidade contém quatro linhas de informação: a primeira linha contém a descrição da prova, a segunda linha contém o país que ficou campeão nesta modalidade, a terceira linha contém o país vice-campeão e a última linha contém o país que ficou com a medalha de bronze na referida prova. O final da entrada é determinado por EOF.

Saída
Como saída, deve ser impresso o quadro de medalhas das Olimpíadas de Natal. A primeira linha contém a informação "Quadro de Medalhas". Cada uma das próximas linhas conterá o nome de um país seguido pelo respectivo número de medalhas de ouro, prata e bronze que este país conquistou, separadas por um espaço em branco. O critério de desempate é, na ordem, o número de medalhas de ouro seguido pelo número de medalhas de prata e de bronze. Se países empatarem nestes três critérios, a listagem será por ordem ascendente do nome do país participante.

Exemplo de Entrada	
Arremesso de duende
Finlandia
Noruega
Sri Lanca
Levantamento de Saco de Brinquedos
Russia
Africa do Sul
Estonia
Escalada de Pinheiro
Estados Unidos
Canada
Sri Lanca
Hipismo com Renas
Finlandia
Estados Unidos
Finlandia
Mergulho em Buraco no Gelo
Islandia
Estonia
Russia

Exemplo de Saída
Quadro de Medalhas
Finlandia 2 0 1
Estados Unidos 1 1 0
Russia 1 0 1
Islandia 1 0 0
Estonia 0 1 1
Africa do Sul 0 1 0
Canada 0 1 0
Noruega 0 1 0
Sri Lanca 0 0 2

*/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    map<string, vector<int>> medalhas;
    string prova, ouro, prata, bronze;

    while (cin >> prova) {
        cin >> ouro;
        cin >> prata;
        cin >> bronze;

        if (medalhas.find(ouro) == medalhas.end()) {
            medalhas[ouro] = vector<int>(3, 0);
        }
        if (medalhas.find(prata) == medalhas.end()) {
            medalhas[prata] = vector<int>(3, 0);
        }
        if (medalhas.find(bronze) == medalhas.end()) {
            medalhas[bronze] = vector<int>(3, 0);
        }

        medalhas[ouro][0]++;    // Incrementa ouro
        medalhas[prata][1]++;   // Incrementa prata
        medalhas[bronze][2]++;  // Incrementa bronze
    }

    vector<pair<string, vector<int>>> sorted_medalhas(medalhas.begin(), medalhas.end());

    sort(sorted_medalhas.begin(), sorted_medalhas.end(), [](const pair<string, vector<int>>& a, const pair<string, vector<int>>& b) {
        if (a.second[0] != b.second[0]) {
            return a.second[0] > b.second[0];
        }
        if (a.second[1] != b.second[1]) {
            return a.second[1] > b.second[1];
        }
        if (a.second[2] != b.second[2]) {
            return a.second[2] > b.second[2];
        }
        return a.first < b.first;
    });

    cout << "Quadro de Medalhas" << endl;
    for (const auto& entry : sorted_medalhas) {
        cout << entry.first << " " << entry.second[0] << " " << entry.second[1] << " " << entry.second[2] << endl;
    }

    return 0;
}

