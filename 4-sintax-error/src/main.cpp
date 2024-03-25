#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <vector>
using namespace std;
stack<char> keys;
stack<char> parenthesis;
stack<char> corchetes;
int numberLine = 1;
void validKeys(char c);
void validParenthesis(char c);
void validCorchetes(char c);
int main()
{
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
            {validKeys(c);}
            else if (c == '(' || c == ')')
            {validParenthesis(c);}
            else if (c == '[' || c == ']')
            {validCorchetes(c);}
        }
        numberLine++;
    }

    file.close();
    return 0;
}
void validKeys(char c)
{
    if (c == '{')
    {
        keys.push(c);
    }
    else if (c == '}')
    {
        if (!keys.empty())
        {
            if (keys.top() == '}')
            {
                cout << "Error en la linea: " << numberLine << " Problemas con: {}" << endl;
            }
            keys.pop();
        }
        else
        {
            cout << "Error en la linea: " << numberLine << " Problemas con: {}" << endl;
        }
    }
}
void validParenthesis(char c)
{
    if (c == '(')
    {
        if (!parenthesis.empty() && parenthesis.top() == '(')
        {
            cout << "Error en la linea: " << numberLine << " Problemas con: ()" << endl;
        }
        else
        {
            parenthesis.push(c);
        }
    }
    else if (c == ')')
    {
        if (!parenthesis.empty() && parenthesis.top() == ')')
        {
            cout << "Error en la linea: " << numberLine << " Problemas con: ()" << endl;
        }
        else
        {
            parenthesis.pop();
        }
    }
}

void validCorchetes(char c)
{
    if (c == '[')
    {
        if (!corchetes.empty() && corchetes.top() == '[')
        {
            cout << "Error en la linea: " << numberLine << " Problemas con: []" << endl;
        }
        else
        {
            corchetes.push(c);
        }
    }
    else if (c == ']')
    {
        if (!corchetes.empty() && corchetes.top() == ']')
        {
            cout << "Error en la linea: " << numberLine << " Problemas con: []" << endl;
        }
        else
        {
            corchetes.pop();
        }
    }
}