#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
#include <iostream>
using namespace std;
void collatz(int n) {
    cout<<n<<",";
    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
        cout<<n<<",";
    }
    cout<<"\n";
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout<<"ERROR, La cantidad de Parametros no es la correcta.\n"<<endl;
        return 1;
    }
    int number = atoi(argv[1]);
    if (number <= 0) {
        cout<<"Error: La cantidad debe ser un entero positivo.\n"<<endl;
        return 1;
    }
    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Error al crear el proceso hijo.\n");
        return 1;
    } else if (pid == 0) {
        collatz(number);
    } else {
        wait(NULL);
    }
    return 0;
}