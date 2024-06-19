/*Existe uma estrutura de dados do tipo sacola, suportando duas operações:

1 x
Jogue um elemento x na sacola.

2
Tire um elemento da sacola.

Dada uma sequencia de operações que retornam valores, você vai adivinhar a estrutura de dados. É uma pilha (último-dentro, primeiro-fora), uma fila (primeiro-dentro, primeiro-fora), uma fila de prioridade (sempre tire os elementos grandes por primeiro) ou qualquer outra coisa que você dificilmente consegue imaginar!

Entrada
Existem muitos casos de testes. Cada caso de teste começa com a linha contando um único inteiro n (1 <= n <= 1000). Cada uma das seguintes n linhas é um comando do tipo 1, ou um número inteiro 2, seguido de um número inteiro x. Isso significa que depois de executar um comando do tipo 2, obtemos um elemento x sem erros. O valor de x é sempre um número inteiro, positivo e não maior do que 100. O final da entrada é determinado pelo final do arquivo (EOF). O tamanho do arquivo de entrada não excede 1MB.

Saída
Para cada caso de teste, mostre um dos seguintes:

stack
É definitivamente uma pilha.

queue
É definitivamente uma fila.

priority queue
É definitivamente uma fila de prioridade.

impossible
Não pode ser uma pilha, uma fila ou uma fila de prioridade.

not sure
Pode ser mais de uma das três estruturas mencionadas acima.

Exemplo de Entrada	
6
1 1
1 2
1 3
2 1
2 2
2 3
6
1 1
1 2
1 3
2 3
2 2
2 1
2
1 1
2 2
4
1 2
1 1
2 1
2 2
7
1 2
1 5
1 1
1 3
2 5
1 4
2 4

Exemplo de Saída
queue
not sure
impossible
stack
priority queue*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stoi(line);
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;

        bool isStack = true, isQueue = true, isPQ = true;

        for (int i = 0; i < n; ++i) {
            getline(cin, line);
            stringstream ss(line);
            int type, x;
            ss >> type >> x;
            
            if (type == 1) {
                // Push x to all structures
                if (isStack) s.push(x);
                if (isQueue) q.push(x);
                if (isPQ) pq.push(x);
            } else if (type == 2) {
                // Check all structures
                if (isStack) {
                    if (s.empty() || s.top() != x) isStack = false;
                    else s.pop();
                }
                if (isQueue) {
                    if (q.empty() || q.front() != x) isQueue = false;
                    else q.pop();
                }
                if (isPQ) {
                    if (pq.empty() || pq.top() != x) isPQ = false;
                    else pq.pop();
                }
            }
        }

        if (isStack && !isQueue && !isPQ) cout << "stack" << endl;
        else if (!isStack && isQueue && !isPQ) cout << "queue" << endl;
        else if (!isStack && !isQueue && isPQ) cout << "priority queue" << endl;
        else if (!isStack && !isQueue && !isPQ) cout << "impossible" << endl;
        else cout << "not sure" << endl;
    }

    return 0;
}
