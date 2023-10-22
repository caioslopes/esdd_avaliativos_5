#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STACK_SIZE 50

typedef struct stack* Pilha;

typedef char Tipo_Informacao;

void init(Pilha* pilha);

bool is_full(Pilha pilha);

bool is_empty(Pilha pilha);

bool push(Pilha pilha, Tipo_Informacao elemento);

bool pop(Pilha pilha, Tipo_Informacao* elemento);