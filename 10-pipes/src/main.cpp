#include <unistd.h>
#include <iostream>
#include <unistd.h>
#include <string>
#include <cstring>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout<<"ERROR, La cantidad de Parametros no es la correcta.\n"<<endl;
        return 1;
    }
    pid_t fpidC;
    int pipefd[2];
    pipe(pipefd);
    fpidC = fork();

    if (fpidC > 0) {
        close(pipefd[0]);

        string texto = argv[1];
        write(pipefd[1], texto.c_str(), texto.length());

        close(pipefd[1]);
    }
    else {
        close(pipefd[1]);

        char buffer[1024];
        ssize_t bytesLeidos = read(pipefd[0], buffer, sizeof(buffer));

        buffer[bytesLeidos] = '\0';

        cout << "Texto recibido por el hijo: " << buffer << endl;

        close(pipefd[0]);
    }

    return 0;
}