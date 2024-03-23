#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    // Variables para almacenar los límites y el incremento de la tabla
    int inicio, fin, incremento;

    // Solicitar al usuario que ingrese los límites y el incremento de la tabla
    cout << "Ingrese el inicio de la tabla (en grados Fahrenheit): ";
    cin >> inicio;
    cout << "Ingrese el fin de la tabla (en grados Fahrenheit): ";
    cin >> fin;
    cout << "Ingrese el incremento de la tabla (en grados Fahrenheit): ";
    cin >> incremento;

    // Imprimir encabezado de la tabla
    cout << "Fahrenheit\tCelsius" << endl;
    cout << "-----------------------" << endl;

    // Calcular y mostrar la tabla de conversiones
    for (int fahrenheit = inicio; fahrenheit <= fin; fahrenheit += incremento) {
        // Calcular la temperatura en Celsius
        double celsius = (5.0 / 9.0) * (fahrenheit - 32);

        // Imprimir la fila de la tabla con tabulaciones
        cout << fixed << setw(10) << setprecision(2) << fahrenheit << "\t"
             << setw(7) << setprecision(2) << celsius << endl;
    }

    return 0;
}



