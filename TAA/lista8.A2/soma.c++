#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    long long K;
    cin >> N >> K;

    vector<long long> elementos(N);
    int i = 0;
    while (i < N) {
        cin >> elementos[i];
        i++;
    }

    unordered_set<long long> x;

    i = 0;
    while (i < N) {
        long long atual = elementos[i];
        long long par = K - atual;
        
        if (x.find(par) != x.end()) {
            cout << par << " " << atual << endl;
            return 0;
        }

        x.insert(atual);
        i++;
    }

    cout << "Nao existe" << endl;
    return 0;
}
