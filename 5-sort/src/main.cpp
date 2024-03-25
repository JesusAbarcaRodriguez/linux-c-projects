#include <iostream>
#include <string>
#include <vector>

using namespace std;

void quicksort(vector<string*>& arr, int left, int right) {
    if (left < right) {
        int pivot = right;
        int partitionIndex = left;
        for (int i = left; i < right; ++i) {
            if (*(arr[i]) < *(arr[pivot])) {
                swap(arr[i], arr[partitionIndex]);
                ++partitionIndex;
            }
        }
        swap(arr[pivot], arr[partitionIndex]);
        quicksort(arr, left, partitionIndex - 1);
        quicksort(arr, partitionIndex + 1, right);
    }
}

int main() {
    vector<string*> lines;
    string line;

    cout << "Ingrese las líneas (Presione Ctrl + D para finalizar):\n";
    while (getline(cin, line)) {
        lines.push_back(new string(line));
    }

    quicksort(lines, 0, lines.size() - 1);

    cout << "\nResultado ordenado:\n";
    for (string* ptr : lines) {
        cout << *ptr << endl;
        delete ptr;
    }

    return 0;
}