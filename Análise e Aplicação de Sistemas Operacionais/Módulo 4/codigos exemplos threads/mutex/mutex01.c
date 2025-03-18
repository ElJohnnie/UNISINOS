#include <pthread.h>
#include <stdio.h>

// Variável global para armazenar um item
char buffer;

// Variável global para indicar se há um item disponível (0 = nenhum, 1 = disponível)
int count = 0;

// Mutex para garantir acesso exclusivo às variáveis globais
pthread_mutex_t mutex;

// Função executada pela thread do produtor
void *produtor() {
    char item;
    // Loop infinito para produção de itens
    while(1) {
        // Entra na região crítica
        pthread_mutex_lock(&mutex);
        
        // Produz o item 'A'
        item = 'A';
        printf("Produzi  A\n");
        
        // Armazena o item produzido no buffer global
        buffer = item;
        
        // Indica que um item está disponível
        count = 1;
        
        // Sai da região crítica
        pthread_mutex_unlock(&mutex);
    }
}

// Função executada pela thread do consumidor
void *consumidor() {
    char item;
    // Loop infinito para consumir itens
    while(1) {
        // Entra na região crítica
        pthread_mutex_lock(&mutex);
        
        // Verifica se há um item disponível
        if (count == 1) {
            // Lê o item presente no buffer
            item = buffer;
            printf(">>>>>>>>>>>> Consumi o item %c\n", item);
            
            // Indica que o item foi consumido
            count = 0;
        }
        
        // Sai da região crítica
        pthread_mutex_unlock(&mutex);
    }
}

int main() {
    pthread_t t1, t2;

    // Inicializa o mutex
    pthread_mutex_init(&mutex, NULL);

    // Cria as threads do produtor e do consumidor
    (void) pthread_create(&t1, NULL, produtor, NULL);
    (void) pthread_create(&t2, NULL, consumidor, NULL);
   
    // Aguarda o término das threads (neste caso, elas rodam indefinidamente)
    (void) pthread_join(t1, NULL);
    (void) pthread_join(t2, NULL);
    
    return 0;
}