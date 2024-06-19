#include <bits/stdc++.h>

using namespace std;

int main() {
    int P, R;
    cin >> P >> R;

    set<int> cadeiras;
    for (int i = 0; i < P; i++) {
        int num_cadeira;
        cin >> num_cadeira;
        cadeiras.insert(num_cadeira);

        int possivel_vencedor = 0;
        int index = 0;
        for (auto cadeira : cadeiras) {
            if (++index >= R) {
                possivel_vencedor = cadeira;
                break;
            }
        }

        if (possivel_vencedor == 0) {
            possivel_vencedor = *cadeiras.rbegin();
        }

        cout << possivel_vencedor << endl;
    }

    return 0;
}
