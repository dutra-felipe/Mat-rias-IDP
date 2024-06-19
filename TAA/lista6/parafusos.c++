#include <bits/stdc++.h>

using namespace std;

int main() {
    int C, Q;
    cin >> C >> Q;

    vector<int> parafusos(1001, 0); 

    for (int i = 0; i < C; ++i) {
        int A, B;
        cin >> A >> B;
        for (int j = A; j <= B; ++j) {
            parafusos[j]++;
        }
    }

    for (int i = 0; i < Q; ++i) {
        int P;
        cin >> P;
        if(parafusos[P]){
            cout << "Contem " << parafusos[P] << " parafuso(s) do tipo " << P << endl;
        } else{
            cout << "Nao contem parafusos do tipo " << P << endl;
        }
    }

    return 0;
}
