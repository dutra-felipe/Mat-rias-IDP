#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N; 

    for (int i = 0; i < N; ++i) {
        long long int T;
        cin >> T;

        long long int triguinhos = 0;
        for (T; T > 0; T = T/2) {
            if (T % 2 != 0) {
                triguinhos++;
            }
        }

        cout << triguinhos << endl; 
    }

    return 0;
}
