#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore();  
    
    for (int i = 0; i < T; ++i) {
       string C, P;
       cin >> C >> P;       
        
       unordered_set<char> catalog;
        for (char c : C) {
            catalog.insert(c);
        }
        
        int count = 0;
        for (char p : P) {
            if (catalog.find(p) != catalog.end()) {
                ++count;
            }
        }
        
       cout << "Contem " << count << " pedras negociaveis" << endl;
    }

    return 0;
}
