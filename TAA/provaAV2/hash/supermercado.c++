/*Hoje é a inauguração de um grande supermercado em sua cidade, e todos estão muito excitados com os baixos preços prometidos.

Este supermercado tem N funcionários que trabalham no caixa, identificados por números de 1 a N, onde cada funcionário leva um determinado tempo vi para processar um item de um cliente. Ou seja, se um cliente tem cj itens em sua cesta, um determinado funcionário levará vi*cj segundos para processar todos os itens deste cliente.

Quando um cliente entra na fila para ser atendido ele espera até que um funcionário esteja livre para o atendê-lo. Se mais de um funcionário estiverem livres ao mesmo tempo, o cliente será atendido pelo funcionário de menor número de identificação. Tal funcionário só estará livre novamente após processar todos os itens deste cliente.

Há M clientes na fila para serem atendidos, cada um com um determinado número de itens na sua cesta. Dadas as informações sobre os funcionários nos caixas e os clientes, o gerente pediu sua ajuda para descobrir quanto tempo levará para que todos os clientes sejam atendidos.

Entrada
A primeira linha conterá dois inteiros N e M, indicando o número de funcionários no caixa e o número de clientes, respectivamente (1 ≤ N ≤ M ≤ 104).

Em seguida haverá N inteiros vi, indicando quanto tempo leva para o i-ésimo funcionário processar um item (1 ≤ vi ≤ 100, para todo 1 ≤ i ≤ N).

Em seguida haverá M inteiros cj, indicando quantos itens o j-ésimo cliente tem em sua cesta (1 ≤ cj ≤ 100, para todo 1 ≤ j ≤ M).

Saída
Imprima uma linha contendo um inteiro, indicando quanto tempo levará para que todos os clientes sejam atendidos.

Exemplos de Entrada	
1 1
3
6

Exemplos de Saída
18
*/

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> vi(N);
    vector<int> cj(M);

    for (int i = 0; i < N; ++i) {
        cin >> vi[i];
    }

    for (int j = 0; j < M; ++j) {
        cin >> cj[j];
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    for (int i = 0; i < N; ++i) {
        pq.push(make_pair(0, i));
    }

    long long total_time = 0;

    for (int j = 0; j < M; ++j) {
        auto current = pq.top();
        pq.pop();

        long long available_time = current.first;
        int cashier_id = current.second;

        long long process_time = vi[cashier_id] * cj[j];
        long long new_available_time = available_time + process_time;

        pq.push(make_pair(new_available_time, cashier_id));

        total_time = max(total_time, new_available_time);
    }

    cout << total_time << endl;

    return 0;
}
