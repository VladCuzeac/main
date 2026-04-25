#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct thread_config{
    int produs_cur;
    int l, r;
    int *v1, *v2;
} thread_config;

void *calc(void *config);

int main(int argc, char *argv[]){
    FILE *f = 0;
    int i, n, diviziune, total_sum = 0, nr_thread = atoi(argv[1]);
    int *vector1, *vector2;
    char *nume = argv[2];
    pthread_t *threads;
    thread_config *configurare;

    f = fopen(nume, "r");
    if(f == 0)
    {
        fprintf(stderr,"Eroare la deschiderea fisierului\n");
        exit(EXIT_FAILURE);
    }

    fscanf(f, "%d", &n);
    n /= 2;

    vector1 = (int*) malloc(n * sizeof(int));
    if(vector1 == 0)
    {
        fprintf(stderr,"Eroare la alocarea dinamica\n");
        exit(EXIT_FAILURE);
    }

    vector2 = (int*) malloc(n * sizeof(int));
    if(vector2 == 0)
    {
        fprintf(stderr,"Eroarea la alocarea dinamica");
        exit(EXIT_FAILURE);
    }

    for(i = 0;i < n;++i)
    {
        fscanf(f, "%d", &vector1[i]);
    }

    for(i = 0;i < n;++i)
    {
        fscanf(f, "%d", &vector2[i]);
    }
    fclose(f);
    f = 0;


    threads = (pthread_t*) malloc(nr_thread * sizeof(pthread_t));
    if(threads == 0)
    {
        fprintf(stderr,"Eroare la alcoarea dinamica\n");
        exit(EXIT_FAILURE);
    }
    
    configurare = (thread_config*) malloc(nr_thread * sizeof(thread_config));
    if(configurare == 0)
    {
        fprintf(stderr,"Eroare la alocarea dinamica\n");
        exit(EXIT_FAILURE);
    }

    diviziune = n / nr_thread;
    for(i = 0;i < nr_thread;++i)
    {
        configurare[i].produs_cur = 0;
        configurare[i].v1 = vector1;
        configurare[i].v2 = vector2;
        configurare[i].l = i * diviziune;
        configurare[i].r = (i == nr_thread - 1 ? n : (i + 1) * diviziune);

        pthread_create(&threads[i], NULL, calc, (void*)&configurare[i]);
    }

    for(i = 0;i < nr_thread;++i){
        pthread_join(threads[i], NULL);
        total_sum += configurare[i].produs_cur;
    }

    printf("Produsul scalar:%d\n", total_sum);
    return 0;
}

void *calc(void *arg){
    int i;
    thread_config *config = (thread_config*)arg;
    for(i = config->l;i < config->r;++i){
        config->produs_cur += config->v1[i] * config->v2[i];
    }
    return NULL;
}