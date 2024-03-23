#include <iostream>
#include <iomanip>
using namespace std;
int main() {

    cout << "Fahrenheit\tCelsius" << endl;
    cout << "-----------------------" << endl;

    for (int fahrenheit = 0; fahrenheit <= 300; fahrenheit += 20) {
        double celsius = (5.0 / 9.0) * (fahrenheit - 32);

        cout << fixed << setw(10) << setprecision(2) << fahrenheit << "\t"
             << setw(7) << setprecision(2) << celsius << endl;
    }

    return 0;
}



