#include "pilha.h"

void analisa(Pilha pilha, char *input);

int main(){
    Pilha pilha;
    init(&pilha);

    char *input;
    input = malloc(sizeof(char)*30);

    fgets(input, 30, stdin);

    analisa(pilha, input);

    free(input);
    
    return 0;
}

void analisa(Pilha pilha, char *input){
    Pilha temp;
    init(&temp);
    Tipo_Informacao caracter;
    int i = 0;
    int chave = 0, colchete = 0, parentese = 0;
    bool parar = false, ordem = true;

    while(input[i] != '\0'){
        push(pilha, input[i]);
        i++;
    }

    push(pilha, input[i]);

    while(!is_empty(pilha)){
        pop(pilha, &caracter);
        push(temp, caracter);
    }

    i = 0;
    while(!parar && ordem){
        pop(temp, &caracter);

        if(caracter == '\0'){
            parar = true;
        }else{

            switch (caracter){
            case '{':
                if(!chave && !colchete && !parentese){
                    chave += 1;
                }else{
                    ordem = false;
                }
                break;

            case '}':
                if(chave && !colchete && !parentese){
                    chave -= 1;
                }else{
                    ordem = false;
                }
                break;

            case '[':
                if(!colchete && !parentese){
                    colchete += 1;
                }else{
                    ordem = false;
                }
                break;

            case ']':
                if(colchete && !parentese){
                    colchete -= 1;
                }else{
                    ordem = false;
                }
                break;

            case '(':
                if(!parentese){
                    parentese += 1;
                }else{
                    ordem = false;
                }
                break;

            case ')':
                if(parentese){
                    parentese -= 1;
                }else{
                    ordem = false;
                }
                break;
            }


        }
    }

    if(ordem){
        printf("\nParenteses, colchetes e chaves bem formados!\n\n");
    }
}