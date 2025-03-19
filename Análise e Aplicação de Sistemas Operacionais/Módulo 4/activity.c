// Jonatha Rodrigo Follmer

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdbool.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PERFECTS 5

pthread_mutex_t mutex;
int next_number = 2;
int found_perfects = 0;
pthread_barrier_t barrier;

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

void *find_perfect_numbers(void *arg) {
    int thread_id = *(int *)arg;
    
    pthread_barrier_wait(&barrier);
    
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
    int num_threads = sysconf(_SC_NPROCESSORS_ONLN);
    if (num_threads < 1) {
        fprintf(stderr, "Erro ao detectar número de processadores.\n");
        return 1;
    }

    pthread_t *threads = malloc(num_threads * sizeof(pthread_t));
    int *thread_ids = malloc(num_threads * sizeof(int));
    if (threads == NULL || thread_ids == NULL) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        return 1;
    }

    pthread_t progress_thread;
    struct timeval start, end;

    pthread_mutex_init(&mutex, NULL);
    gettimeofday(&start, NULL);

    pthread_barrier_init(&barrier, NULL, num_threads);

    pthread_create(&progress_thread, NULL, print_progress, NULL);

    for (int i = 0; i < num_threads; i++) {
        thread_ids[i] = i + 1;
        printf("Criando Thread %d.\n", thread_ids[i]);
        pthread_create(&threads[i], NULL, find_perfect_numbers, &thread_ids[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_join(progress_thread, NULL);

    gettimeofday(&end, NULL);

    pthread_mutex_destroy(&mutex);
    
    pthread_barrier_destroy(&barrier);

    long elapsed_time = (end.tv_sec - start.tv_sec) * 1000L + (end.tv_usec - start.tv_usec) / 1000;
    printf("Tempo total de execução: %ld ms\n", elapsed_time);

    free(threads);
    free(thread_ids);
    return 0;
}
