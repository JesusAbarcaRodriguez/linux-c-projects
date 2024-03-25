#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

stack<char> keys;
stack<char> parenthesis;
stack<char> corchetes;

stack<int> numberLineKeys;
stack<int> numberLineParenthesis;
stack<int> numberLineCorchetes;

int numberLine = 1;

template<typename T>
void validSymbols(char c, stack<T>& symbols, stack<int>& numberLineSymbols, const T& openSymbol, const string& errorMessage);
template<typename T>
void printAndPopErrors(stack<T>& symbols, stack<int>& numberLineSymbols, const string& errorMessage);

int main(){
    string fileName = "file.c";
    ifstream file(fileName);

    if (!file.is_open())
    {
        cerr << "No se pudo abrir el file " << fileName << endl;
        return 1;
    }
    string line;
    while (getline(file, line))
    {
        for (char c : line)
        {
            if (c == '{' || c == '}')
            {validSymbols(c, keys, numberLineKeys, '{', "{}");}
            else if (c == '(' || c == ')')
            {validSymbols(c, parenthesis, numberLineParenthesis, '(', "()");}
            else if (c == '[' || c == ']')
            {validSymbols(c, parenthesis, numberLineParenthesis, '[', "[]");}
        }
        numberLine++;
    }
    printAndPopErrors(keys, numberLineKeys, "{}");
    printAndPopErrors(parenthesis, numberLineParenthesis, "()");
    printAndPopErrors(corchetes, numberLineCorchetes, "[]");

    file.close();
    return 0;
}
template<typename T>
void validSymbols(char c, stack<T>& symbols, stack<int>& numberLineSymbols, const T& openSymbol, const string& errorMessage) {
    if (c == openSymbol) {
        symbols.push(c);
        numberLineSymbols.push(numberLine);
    } else if (c != openSymbol) {
        if (!symbols.empty() && !numberLineSymbols.empty()) {
            symbols.pop();
            numberLineSymbols.pop();
        } else {
            cout << "Error en la línea: " << numberLine << " Problemas con: " << errorMessage << endl;
        }
    }}
template<typename T>
void printAndPopErrors(stack<T>& symbols, stack<int>& numberLineSymbols, const string& errorMessage) {
    while (!symbols.empty() && !numberLineSymbols.empty()) {
        cout << "Error en la línea: " << numberLineSymbols.top() << " Problemas con: " << errorMessage << endl;
        symbols.pop();
        numberLineSymbols.pop();
    }}