#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout<<"ERROR, La cantidad de Parametros no es la correcta.\n"<<endl;
        return 1;
    }

    int num_childrens = atoi(argv[1]);
    if (num_childrens <= 0) {
        cout<<"Error: La cantidad de hijos debe ser un entero positivo.\n"<<endl;
        return 1;
    }

    pid_t pid;
        cout<<"Proceso padre: PID = "<<getpid()<<" PPID = "<<getppid()<<endl;
        cout<<endl;

    for (int i = 1; i <= num_childrens; i++) {
        pid = fork();

        if (pid < 0) {
            cout<<"ERROR Creando el proceso hijo"<<endl;
            return 1;
        } else if (pid == 0) {
            cout<<"Proceso hijo:"<<i<<" PID = "<<getpid()<<" PPID = "<<getppid()<<endl;
            return 0;
        }
    }

    for (int i = 0; i < num_childrens; i++) {
        wait(NULL);
    }

    return 0;
}