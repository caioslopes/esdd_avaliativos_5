#include "pilha.h"

void mostraPilha(Pilha pilha);

int main(){
    Pilha pilha1, pilha2;

    init(&pilha1);
    init(&pilha2);

    push(pilha1, 5);
    push(pilha1, 7);
    push(pilha1, 3);
    push(pilha1, 10);

    push(pilha2, 5);
    push(pilha2, 7);
    push(pilha2, 3);
    push(pilha2, 10);

    if(is_equal(pilha1, pilha2))
    {
        printf("\n**As pilhas 1 e 2 sao iguais!**\n");

        printf("\nPilha 1:\n");
        mostraPilha(pilha1);

        printf("\nPilha 2:\n");
        mostraPilha(pilha2);
    }else{
        printf("\n**As pilhas 1 e 2 NAO sao iguais!**\n");

        printf("\nPilha 1:\n");
        mostraPilha(pilha1);

        printf("\nPilha 2:\n");
        mostraPilha(pilha2);
    
    }
    

    return 0;
}

void mostraPilha(Pilha pilha){
    while(!is_empty(pilha)){
            Tipo_Informacao retorno;
            pop(pilha, &retorno);
            printf("%d\n", retorno);
        }
}
