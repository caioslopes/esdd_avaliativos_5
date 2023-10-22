
#include "pilha.h"


struct stack{
    Tipo_Informacao itens[MAX_STACK_SIZE];
    int topo;
    int size;
    bool inverteu;
};


void init(Pilha* pilha){

	*pilha = malloc(sizeof(struct stack));

	if(*pilha != NULL){
		(*pilha)->topo = -1;
        (*pilha)->size = 0;
        (*pilha)->inverteu = false;
	}
}


bool is_full(Pilha pilha){
	
	if(pilha->size == MAX_STACK_SIZE){
		return true;
    }else{
	    return false;
    }
}

bool is_empty(Pilha pilha){
	
    return pilha->size == 0 ? true : false;

}


bool push(Pilha pilha, Tipo_Informacao elemento){
	bool deuCerto = false;

	if( pilha != NULL ){
		if(!is_full(pilha)){
            if(is_reverse(pilha)){
                if(pilha->topo == 0){
                    pilha->topo = MAX_STACK_SIZE -1;
                }
                pilha->topo -= 1;
            }else{
             pilha->topo += 1;
            }
            pilha->itens[pilha->topo] = elemento;
            pilha->size += 1;
			deuCerto = true;
		}
	}

	return deuCerto;
}

bool pop(Pilha pilha, Tipo_Informacao* elemento){
	bool deuCerto = false;

	if( pilha != NULL ){
		if( ! is_empty(pilha) ){
			
            if(is_reverse(pilha)){
                *elemento = pilha->itens[pilha->topo];
                pilha->topo += 1;
                if(pilha->topo == MAX_STACK_SIZE){
                    pilha->topo = 0;
                }
            }else{
                *elemento = pilha->itens[pilha->topo];
			    pilha->topo -= 1;
            }
             pilha->size -= 1;
			deuCerto = true;
		}
	}

	return deuCerto;
}
bool inverter(Pilha pilha){
    pilha->inverteu = true;
    pilha->topo = 0;
}

bool is_reverse(Pilha pilha){
    return pilha->inverteu;
}
