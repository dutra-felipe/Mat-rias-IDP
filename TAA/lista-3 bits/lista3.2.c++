#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int A, B, Y;
        cin >> A >> B >> Y;
 
        int aux = (A | B);
        int C = aux ^ Y;

        if ((A | B | C) != Y) {
            cout << -1 << endl;
        } else {
            cout << C << endl;
        }
    }

    return 0;
}
