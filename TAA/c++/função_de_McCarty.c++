#include <iostream>
using namespace std;

int testa(int n) {
    if (n > 100)
        return n - 10;
    else
        return testa(testa(n + 11));
}

int main() {
    int C;
    cin >> C;

    for(int i = 0; i < C; i++){ //while(C--)
        int N;
        cin >> N;
        cout << testa(N) << endl;
    }
    return 0;
}