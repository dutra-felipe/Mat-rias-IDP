#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T; 

    for (int i = 0; i < T; ++i) {
        int A, B, Y;
        cin >> A >> B >> Y; 

        int aux = (A ^ B);
        int C = aux ^ Y;

        if ((A ^ B ^ C) != Y) {
            cout << "-1" << endl;
        } else {
            cout << C << endl;
        }
    }

    return 0;
}
