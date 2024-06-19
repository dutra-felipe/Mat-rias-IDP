#include <bits/stdc++.h>

using namespace std;

bool verificarExpressao(const string& expression) {
    stack<char> pilha;
    unordered_map<char, char> brackets_pairs = {{')', '('}, {']', '['}, {'}', '{'}};
    
    for (char c : expression) {
        if (c == '(' || c == '[' || c == '{') {
            pilha.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (pilha.empty() || pilha.top() != brackets_pairs[c]) {
                return false;
            }
            pilha.pop();
        }
    }
    
    return pilha.empty();
}

int main() {
    ios_base::sync_with_stdio(false);

    string expressao;
    getline(cin, expressao);
    
    if (verificarExpressao(expressao)) {
        cout << "OK" << endl;
    } else {
        cout << "SyntaxError" << endl;
    }
    
    return 0;
}
