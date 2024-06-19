#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    
    while (T--) {
        string R, S;
        cin >> R >> S;
        
        if (R.size() != S.size()) {
            cout << "DIFERENTES" << endl;
            continue;
        }
        
        int frequencia[256] = {0};
        
        for (size_t i = 0; i < R.size(); ++i) {
            frequencia[R[i]]++;
            frequencia[S[i]]--;
        }
        
        bool anagrama = true;
        for (int i = 0; i < 256; ++i) {
            if (frequencia[i] != 0) {
                anagrama = false;
                break;
            }
        }
        
        if (anagrama) {
            cout << "ANAGRAMAS" << endl;
        } else {
            cout << "DIFERENTES" << endl;
        }
    }
    
    return 0;
}