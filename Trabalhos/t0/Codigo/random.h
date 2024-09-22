// random.h
// define um criador de numero aleatorio

#ifndef RANDOM_H
#define RANDOM_H

#include "err.h"

typedef struct random_t random_t;

// cria e inicializa o dispositivo random
random_t *random_cria(void);

void random_destroi(random_t *self);

err_t random_leitura(void *disp, int id, int *pvalor);

#endif