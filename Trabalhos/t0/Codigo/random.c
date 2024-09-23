#include "random.h"

#include <stdlib.h>
#include <time.h>
#include <assert.h>

struct random_t {
    unsigned int seed;
};

random_t *random_cria(void) {
    random_t *self;
    self = malloc(sizeof(*self));
    assert(self != NULL);
    
    self->seed = time(0); 

    return self;
}

void random_destroi(random_t *self) {
    if(self != NULL) {
        free(self);
    }
}

err_t random_leitura(void *disp, int id, int *pvalor) {
    random_t *self = disp;
    err_t err = ERR_OK;
    switch (id) {
        case 0:     // LEITURA
            srand(self->seed);
            *pvalor = (rand() % 100) + 1;     // para deixar o valor aleatório entre 1 e 100
            break;
        default:
            err = ERR_DISP_INV;
    }

    return err;
}