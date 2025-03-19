// Jonatha Rodrigo Follmer

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdbool.h>
#include <unistd.h>
#include <errno.h>


// quando usamos define estamos criando uma constante imutável
// MAX_PERFECTS é o número máximo de números perfeitos que queremos encontrar
#define MAX_PERFECTS 5

/*
A seção crítica de um processo é a parte do código de um algoritmo que acessa um recurso compartilhado. Também é conhecida como região crítica ou trecho crítico. 
*/

/*
O Mutex (Mutual Exclusion) é um mecanismo de sincronização que garante que apenas um processo por vez execute sua sessão crítica. Ele funciona como uma "trava" que um processo precisa adquirir antes de entrar na sessão crítica e liberar ao sair.
*/

// essas variáveis são globais, ou seja, podem ser acessadas por qualquer função
// mutex é uma variável do tipo pthread_mutex_t que será usada para controlar o acesso à variável next_number
// next_number é a próxima variável a ser verificada
// found_perfects é o número de números perfeitos encontrados
pthread_mutex_t mutex;
int next_number = 2;
int found_perfects = 0;

/*
``` 

**Como funciona:**

1. Declaramos uma variável global do tipo pthread_barrier_t chamada barrier.
2. No main, inicializamos essa barreira com o número de threads executáveis.
3. Em cada função find_perfect_numbers, logo no início, a thread chama pthread_barrier_wait(&barrier) para aguardar que todas as threads sejam criadas.
4. Após todas atingirem a barreira, elas iniciam a busca pelos números perfeitos.
Dessa forma, a busca só começarará depois que todas as threads estiverem prontas.
*/

pthread_barrier_t barrier; // barreira para sincronizar as threads executáveis

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
// void *print_progress(void *arg) é uma função que não retorna nada e recebe um ponteiro void como argumento
// void *arg é um ponteiro void que pode ser usado para passar qualquer tipo de argumento para a função
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

// aqui estamos passando um ponteiro void como argumento para a função
// void *arg é um ponteiro void que pode ser usado para passar qualquer tipo de argumento para a função
// o que é um ponteiro? um ponteiro é uma variável que armazena um endereço de memória
// um ponteiro void é um ponteiro que pode apontar para qualquer tipo de dado
// void *find_perfect_numbers(void *arg) é uma função que não retorna nada e recebe um ponteiro void como argumento
void *find_perfect_numbers(void *arg) {
    int thread_id = *(int *)arg;
    
    // Espera até que todas as threads estejam prontas
    pthread_barrier_wait(&barrier);
    
    // Encontra números perfeitos
    while (1) {
        pthread_mutex_lock(&mutex);
        if (found_perfects >= MAX_PERFECTS) {
            pthread_mutex_unlock(&mutex);
            break;
        }
        int num = next_number;
        next_number++;
        pthread_mutex_unlock(&mutex);

        // Verifica se o número é perfeito e imprime se for de acordo com qual thread encontrou
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
    // Obtendo o número de processadores disponíveis
    int num_threads = sysconf(_SC_NPROCESSORS_ONLN);
    if (num_threads < 1) {
        fprintf(stderr, "Erro ao detectar número de processadores.\n");
        return 1;
    }

    // malloc para alocar memória para as threads e seus IDs, malloc = memory allocation
    pthread_t *threads = malloc(num_threads * sizeof(pthread_t));
    int *thread_ids = malloc(num_threads * sizeof(int));
    if (threads == NULL || thread_ids == NULL) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        return 1;
    }

    pthread_t progress_thread;
    struct timeval start, end;

    // Inicializa o mutex para controlar o acesso à variável next_number
    pthread_mutex_init(&mutex, NULL);
    gettimeofday(&start, NULL);

    // Inicializa a barreira para sincronizar todas as threads executáveis
    pthread_barrier_init(&barrier, NULL, num_threads);

    // Criando thread de progresso
    pthread_create(&progress_thread, NULL, print_progress, NULL);

    // Criando threads para encontrar números perfeitos
    for (int i = 0; i < num_threads; i++) {
        thread_ids[i] = i + 1;
        printf("Criando Thread %d.\n", thread_ids[i]);
        pthread_create(&threads[i], NULL, find_perfect_numbers, &thread_ids[i]);
    }

    // Aguardando as threads finalizarem
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Aguardando thread de progresso finalizar
    pthread_join(progress_thread, NULL);

    // Finalizando o mutex
    gettimeofday(&end, NULL);
    // pthread_mutex_destroy(&mutex) faz a destruição do mutex
    pthread_mutex_destroy(&mutex);
    

    // Finalizando a barreira
    pthread_barrier_destroy(&barrier);

    // Cálculo do tempo de execução
    long elapsed_time = (end.tv_sec - start.tv_sec) * 1000L + (end.tv_usec - start.tv_usec) / 1000;
    printf("Tempo total de execução: %ld ms\n", elapsed_time);


    // Liberando memória alocada
    // função free libera a memória alocada por malloc
    free(threads);
    free(thread_ids);
    return 0;
}
