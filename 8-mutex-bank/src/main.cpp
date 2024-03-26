#include <iostream>
#include <pthread.h>

using namespace std;
void* deposit(void* arg);
pthread_mutex_t mutex;
double balance = 0;

int main() {
    pthread_t threads[10];
    double depositos[10] = {100, 115, 200, 215, 300, 315, 40, 60, 78, 49};
    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < 10; ++i) {
        if (pthread_create(&threads[i], NULL, deposit, (void*)&depositos[i]) !=0) {
            cerr << "Error al crear el hilo " << i << endl;
            return 1;
        }
    }

    for (int i = 0; i < 10; ++i) { pthread_join(threads[i], NULL); }

    cout << "El saldo final es: $" << balance << endl;

    return 0;
}
void* deposit(void* arg) {
    double cantidad = *static_cast<double*>(arg);
    pthread_mutex_lock(&mutex);
    balance += cantidad;
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}