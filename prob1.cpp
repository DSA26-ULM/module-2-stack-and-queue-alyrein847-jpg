#include <iostream>
#include <sstream>
#include "stack.h"
using namespace std;

int main() {
    Stack s;
    init(&s);

    int n;
    cin >> n;
    cin.ignore();

    string input;
    getline(cin, input);

    stringstream ss(input);
    string token;

    while (ss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = peek(&s); pop(&s);
            int a = peek(&s); pop(&s);

            int hasil;
            if (token == "+") hasil = a + b;
            else if (token == "-") hasil = a - b;
            else if (token == "*") hasil = a * b;
            else if (token == "/") hasil = a / b;

            push(&s, hasil);
        } 
        else {
            int angka = stoi(token);
            push(&s, angka);
        }
    }

    cout << peek(&s) << endl;

    return 0;
}