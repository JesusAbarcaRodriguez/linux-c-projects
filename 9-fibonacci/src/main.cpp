#include <iostream>
#include <pthread.h>

using namespace std;

pthread_mutex_t mutex;

int sequence[1000];
void* fibonacci(void* arg);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout<<"ERROR, La cantidad de Parametros no es la correcta.\n"<<endl;
        return 1;
    }

    int num_fibo = atoi(argv[1]);
    if (num_fibo <= 1) {
        cout<<"Error: La secuencia fibonacci debe de ser mayor a 1.\n"<<endl;
        return 1;
    }
    pthread_t thread;

    if (pthread_create(&thread, NULL, fibonacci, (void*)&num_fibo) != 0) {
        cerr << "Error al crear el hilo" << endl;
        return 1;
    }

    pthread_join(thread, NULL);

    cout << "Secuencia de Fibonacci:" << endl;
    for (int i = 0; i < num_fibo; ++i) {
        cout << sequence[i] << " ";
    }
    cout << endl;

    return 0;
}
void* fibonacci(void* arg) {
    int num_fibo = *((int*)arg);

    sequence[0] = 0;
    sequence[1] = 1;

    for (int i = 2; i < num_fibo; ++i) {
        pthread_mutex_lock(&mutex);
        sequence[i] = sequence[i - 1] + sequence[i - 2];
        pthread_mutex_unlock(&mutex);
    }
    
    pthread_exit(NULL);
}