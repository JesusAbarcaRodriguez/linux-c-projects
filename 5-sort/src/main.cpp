#include <iostream>
#include <string>
#include <vector>

using namespace std;

void quickSort(vector<string*>& arr, int inicio, int fin) {
    int izq, der;
    string* pivote;
    izq = inicio;
    der = fin;
    pivote = arr[(izq + der) / 2];
    do {
        while (*(arr[izq]) < *pivote && izq < fin) {
            izq++;
        }

        while (*(arr[der]) > *pivote && der > inicio) {
            der--;
        }

        if (izq <= der) {
            swap(arr[izq], arr[der]);
            izq++;
            der--;
        }

    } while (izq <= der);

    if (inicio <= der) {
        quickSort(arr, inicio, der);
    }

    if (fin > izq) {
        quickSort(arr, izq, fin);
    }
}

int main() {
    vector<string*> lines;
    string line;

    cout << "Ingrese las líneas (Presione Ctrl + D para finalizar):\n";
    while (getline(cin, line)) {
        lines.push_back(new string(line));
    }

    quickSort(lines, 0, lines.size() - 1);

 
    cout << "\nResultado ordenado:\n";
    for (string* ptr : lines) {
        cout << *ptr << endl;
        delete ptr;
    }
    return 0;
}