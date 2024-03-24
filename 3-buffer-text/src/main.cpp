#include <iostream>

using namespace std;
const int BUFFER_SIZE = 1000;
char* buffer = new char[BUFFER_SIZE];
int main() {
    
    char character;
    int index = 0;
    cout<<"Hola, este programa elimina los espacios en blanco y tabuladores que ingrese el usuario."<<endl;
    cout << "Ingrese texto y presione Ctrl+D para terminar:\n";

    while ((character = getchar()) != EOF && index < BUFFER_SIZE - 1) {
        if (character != ' ' && character != '\t') {
            buffer[index] = character;
            index++;
        }
    }

    cout << "\nTexto resultante:\n";
    cout << buffer << endl;

    delete[] buffer;

    return 0;
}
