#ifndef LEITURADADOS_H
#define LEITURADADOS_H

int quant;
int *vector;
int vector_len;
int sum;
int partial_sum;
int flag;
int *vector_aux;
pthread_t *paral;
pthread_mutex_t trava;
// Chama a funcao
int data_read();
void sort();

typedef struct stru {
long index;
long sum;
} stru;

#endif
