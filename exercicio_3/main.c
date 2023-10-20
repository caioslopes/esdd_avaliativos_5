#include "pilha.h"


int main(){
    Pilha pilha;
    int input, val, resto;

    init(&pilha);

    scanf("%d", &input);

    val = input;

    while(val != 0){

        resto = val%2;

        push(pilha, resto);

        val /= 2;
    }

    printf("\n%d em binario:\n", input);
     while(!is_empty(pilha)){
        Tipo_Informacao retorno;
        pop(pilha, &retorno);
        printf("%d", retorno);
    }
    printf("\n\n");
    
    return 0;
}
