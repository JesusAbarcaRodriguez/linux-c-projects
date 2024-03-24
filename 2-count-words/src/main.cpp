#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    char character;
    int countWords = 0;
    bool isLetter = false;
    cout << "Ingrese texto y presione Ctrl+D para terminar:\n";
    while ((character = getchar()) != EOF) {
        if (character == ' ' || character == '\n') {
            countWords++;
            isLetter = false;
    }else{
        isLetter = true;
    }}
    if(isLetter){
        countWords++;
    }
    cout << "\nLa cantidad de palabras digitadas fueron: " << countWords << endl;
    return 0;
}
