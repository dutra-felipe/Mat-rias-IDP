#include <iostream>

using namespace std;

int primos[10000000];

void crivo(){
    for(int i = 0; i < 10000000; i++){
        primos[i] = 1;
    }

    primos[0] = primos[1] = 0;

    for(int i = 2; i < 10000000; i++){
        if(primos[i]){
            for(int j = 2 * i; j < 10000000; j += i){
                primos[j] = 0;
            }
        }
    }
}

int acha_primo(int a){
    return primos[a];
}

int main() {
    int n, valor;
    cin >> n;
    crivo();

    for(int i = 0; i < n; i++){
        cin >> valor;
    
    if(acha_primo(valor)){
        cout << "o numero " << valor << " eh primo" << endl;
    } else {
        cout << "o numero " << valor << " nao eh primo" << endl;
      }
    }
    return 0;
}