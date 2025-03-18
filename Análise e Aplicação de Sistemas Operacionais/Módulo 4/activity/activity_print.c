#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdbool.h>
#include <unistd.h>

#define NUM_THREADS 4
#define MAX_PERFECTS 5

pthread_mutex_t mutex;
int next_number = 2;
int found_perfects = 0;

// Função para verificar se um número é perfeito
bool is_perfect(int num) {
    int sum = 1;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            sum += i;
            if (i != num / i) {
                sum += num / i;
            }
        }
    }
    return sum == num;
}

// Função para exibir progresso periodicamente
void *print_progress(void *arg) {
    while (1) {
        sleep(2);
        pthread_mutex_lock(&mutex);
        if (found_perfects >= MAX_PERFECTS) {
            pthread_mutex_unlock(&mutex);
            break;
        }
        printf("Progresso: atualmente verificando o número %d\n", next_number);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

// Função executada por cada thread
void *find_perfect_numbers(void *arg) {
    int thread_id = *(int *)arg;
    while (1) {
        pthread_mutex_lock(&mutex);
        if (found_perfects >= MAX_PERFECTS) {
            pthread_mutex_unlock(&mutex);
            break;
        }
        int num = next_number;
        next_number++;
        pthread_mutex_unlock(&mutex);

        if (is_perfect(num)) {
            pthread_mutex_lock(&mutex);
            found_perfects++;
            printf("Thread %d encontrou o número perfeito: %d\n", thread_id, num);
            pthread_mutex_unlock(&mutex);
        }
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    pthread_t progress_thread;
    int thread_ids[NUM_THREADS];
    struct timeval start, end;

    pthread_mutex_init(&mutex, NULL);
    gettimeofday(&start, NULL);

    // Criando thread de progresso
    pthread_create(&progress_thread, NULL, print_progress, NULL);

    // Criando threads para encontrar números perfeitos
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, find_perfect_numbers, &thread_ids[i]);
    }

    // Aguardando as threads finalizarem
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Aguardando thread de progresso finalizar
    pthread_join(progress_thread, NULL);

    gettimeofday(&end, NULL);
    pthread_mutex_destroy(&mutex);

    // Cálculo do tempo de execução
    long elapsed_time = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;
    printf("Tempo total de execução: %ld ms\n", elapsed_time);

    return 0;
}
