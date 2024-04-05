#include <iostream>
using namespace std;
int main() {

    cout << "Fahrenheit\tCelsius" << endl;
    cout << "-----------------------" << endl;

    for (int fahrenheit = 0; fahrenheit <= 300; fahrenheit += 20) {
        double celsius = (5.0 / 9.0) * (fahrenheit - 32);

        cout << fahrenheit<<"\t"<<"\t"<<celsius<<endl;
    }

    return 0;
}



