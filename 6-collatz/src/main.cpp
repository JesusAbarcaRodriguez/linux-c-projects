#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
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
    int number = atoi(argv[1]);
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