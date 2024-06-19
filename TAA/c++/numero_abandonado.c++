#include <iostream>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    while (1) {
        int N;
        cin >> N;
        if (N == -1){
            break;
        }

        int num_diferente = 0;

        for (int i = 0; i < N; i++) {
            int numeros;
            cin >> numeros;
            num_diferente ^= numeros;
        }

        cout << num_diferente << endl;
    }
    return 0;
}
