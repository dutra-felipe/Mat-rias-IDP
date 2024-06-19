/*O IDP resolveu classificar todos os alunos de todos os cursos de todas as unidades do Brasil em uma classificação geral.

Todo aluno, possui uma nota que é a média de todas as notas que ele já obteve cursando disciplinas até o momento. Dessa forma, você recebeu a atribuição de, dadas as notas de todos os alunos da instituição, ordenar todo mundo em ordem crescente por essas notas.

Input
A primeira linha da entrada possui um inteiro A (1≤A≤7000000) que indica a quantidade de alunos no total. As A linhas seguintes possuem um inteiro N (0≤N≤10) cada, que são as notas de cada um dos alunos.

Output
A saída deve conter A linhas, onde cada linha é um inteiro e todas as linhas estão ordendas em ordem crescente de acordo com a nota de cada aluno. */

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int A;
    scanf("%d", &A);

    priority_queue<int, vector<int>, greater<int>> pq;

    while(A--) {
        unsigned long long int N;
        scanf("%llu", &N);
        pq.push(N);
    }

    while (!pq.empty()) {
        printf("%d\n", pq.top());
        pq.pop();
    }

    return 0;
}
