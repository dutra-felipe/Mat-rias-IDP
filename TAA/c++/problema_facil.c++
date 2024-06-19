#include <iostream>

using namespace std;

long long int testa(long long int n){
    if(n == 1){
        cout << n;
        return n;
    }
    if(n != 1)
        cout << n << " ";

    if(n % 2  == 0){
        n = n / 2;
    }
    else {
        n = n * 3 + 1;
    }
    return testa(n);
}


int main() {
    long long int N;
    cin >> N;
    N = testa(N);
    return 0;
}