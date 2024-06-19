#include <iostream>

using namespace std;

struct No {
    int valor;
    No* esquerdo;
    No* direito;
    
    No(int val) : valor(val), esquerdo(nullptr), direito(nullptr) {}
};

No* insere(No* no, int val) {
    if (no == nullptr) {
        return new No(val);
    }
    if (val < no->valor) {
        no->esquerdo = insere(no->esquerdo, val);
    } else {
        no->direito = insere(no->direito, val);
    }
    return no;
}

void emordem(No* no) {
    if (no == nullptr) {
        return;
    }
    emordem(no->esquerdo);
    cout << no->valor << " ";
    emordem(no->direito);
}

void preordem(No* no) {
    if (no == nullptr) {
        return;
    }
    cout << no->valor << " ";
    preordem(no->esquerdo);
    preordem(no->direito);
}

void posordem(No* no) {
    if (no == nullptr) {
        return;
    }
    posordem(no->esquerdo);
    posordem(no->direito);
    cout << no->valor << " ";
}

int main() {
    int N;
    cin >> N;

    No* no = nullptr;

    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        no = insere(no, val);
    }

    cout << "In.: ";
    emordem(no);
    cout << endl;

    cout << "Pre: ";
    preordem(no);
    cout << endl;

    cout << "Pos: ";
    posordem(no);
    cout << endl;

    return 0;
}
