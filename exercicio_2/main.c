#include "pilha.h"

bool contains(Pilha pilha, Tipo_Informacao valor);
bool insert(Pilha pilha, Tipo_Informacao valor);

int main(int argc, char** argv) {
    Pilha minhaPilha;
    int menu;
    Tipo_Informacao valor;

    init(&minhaPilha);

    do{
        printf("\n1 - Empilha");
        printf("\n2 - Desempilha");
        printf("\n3 - Esvaziar");
        printf("\n4 - Sair");
        printf("\nOpcao: ");
        scanf("%d", &menu);

        switch(menu){
            case 1:
                printf("\nEmpilha\n\n\tValor: ");
                scanf("%d", &valor);
                if(insert(minhaPilha, valor)){
                    printf("\nEmpilhado com sucesso\n");
                }else{
                    printf("\nValor inserido já existe na pilha\n");
                }
                break;
            case 2:
                if(pop(minhaPilha, &valor)){
                    printf("\nDesempilha\n\n\tValor: %d", valor);
                }else{
                    printf("\nPilha vazia\n");
                }
                break;
            case 3:
                while(!is_empty(minhaPilha)){
                    pop(minhaPilha, &valor);
                    printf("\nValor: %d", valor);
                }
                break;
        }
    }while(menu != 4);
    return 0;
}

bool contains(Pilha pilha, Tipo_Informacao valor){

    Pilha pilha_intermediaria;
    Tipo_Informacao el;

    bool equals = false;

    init(&pilha_intermediaria);

    while(!is_empty(pilha)){
        pop(pilha, &el);
        push(pilha_intermediaria, el);
        if(valor == el){
            equals = true;
        }
    }

    while(!is_empty(pilha_intermediaria)){
        pop(pilha_intermediaria, &el);
        push(pilha, el);
    }

    return equals;
}

bool insert(Pilha pilha, Tipo_Informacao valor){

    bool insert = false;

    if(!contains(pilha, valor)){

        Pilha pilha_intermediaria;
        Tipo_Informacao el;
        bool find_pos = false;

        init(&pilha_intermediaria);

        if(is_empty(pilha)){
            push(pilha, valor);
        }else{
            while (!is_empty(pilha) && find_pos == false){
                pop(pilha, &el);
                if(valor > el){
                    push(pilha, el);
                    push(pilha, valor);
                    find_pos = true;
                }else{
                    push(pilha_intermediaria, el);
                }
            }
        }

        if(is_empty(pilha)){
            push(pilha, valor);
        }

        while(!is_empty(pilha_intermediaria)){
            pop(pilha_intermediaria, &el);
            push(pilha, el);
        }
        
        insert = true;
    }

    return insert;
}