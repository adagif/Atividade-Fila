#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "atFila.h"

//MARIA EDUARDA SOARES CARVALHO

struct nodescritor{
	struct elemento *inicio;
	struct elemento *fim;
	int quantidade;

};

struct elemento{
	struct cliente informacao;
	struct elemento *prox;
};

typedef struct elemento Elem;

Fila *criar(){
		Fila *fi;
		fi = (Fila*)malloc(sizeof(Fila));
		if(fi!=NULL){
			fi->inicio = NULL;
			fi->fim = NULL;
			fi->quantidade = 0;
			
		}
		return fi;
}

int inserir(Fila *fi,struct cliente cli){
	if(fi==NULL){
		return 0;
	}
	else{
		Elem *novo = (Elem*)malloc(sizeof(Elem));
		if(novo == NULL) return 0;
		novo->informacao = cli;
		novo->prox = NULL;
		if(fi->inicio){  
			fi->fim->prox = novo;
		}else{
			fi->inicio = novo;
		}
		fi->fim = novo;
		fi->quantidade++;
		return 1;
	}
}

int remover(Fila *fi){
	if(fi == NULL || fi->inicio==NULL){
		return 0;
	}
	else{
		Elem *aux;
		aux  = fi->inicio;
		fi->inicio = fi->inicio->prox;
		if(fi->inicio == NULL){
			fi->fim=NULL;
		}
		free(aux);
		fi->quantidade--;
		return 1;
	}
}

int acessar(Fila *fi,struct cliente *cli){
	if(fi == NULL || fi->inicio == NULL){
		return 0;
	}
	else{
		*cli = fi->inicio->informacao;
	
		return 1;
	}
}

void destruir (Fila *fi){
	if(fi != NULL){
		Elem *aux;
		while (fi->inicio != NULL){
			aux = fi->inicio;
			fi->inicio = fi->inicio->prox;
			free(aux);
		}
		free(fi);
	}
}

int tamanho(Fila *fi){
	if(fi == NULL){
		return 0;
	}
	else{
		printf("TAMANHO: %d\n",fi->quantidade);
		return 1;
	}
}
int cheia(Fila *fi){
	return 0;
}
int vazia(Fila *fi){
	if(fi == NULL){
		return -1;
	}else if(fi->inicio == NULL){
		return 1;
	}else{
		return 0;
	}
}

void imprimir(Fila *fi){

	if(fi==NULL){
		printf("ERRO!\n");
	}
	if(vazia(fi)==1){
		printf("VAZIA\n");
	}
	Elem * aux;
	aux = fi->inicio;

	while(aux != NULL){
		printf("%s\n",aux->informacao.nome);
		printf("%d\n",aux->informacao.cpf);
		aux = aux->prox;
		}
	}
int migrar(Fila *fi, Fila *fi2){
	
	if(fi==NULL){
		printf("FILA A NAO EXISTE\n");
		return 0;
	}
	if(fi2==NULL){
		printf("FILA B NAO EXISTE\n");
		return 0;
	}
	/*if(fi->inicio == NULL){
		printf("FILA A VAZIA\n");
		return 0;
		}*/
	if(fi2->inicio == NULL){
		printf("FILA B VAZIA\n");
		return 0;
		}

	
		while(fi2->inicio != NULL){
		Elem * aux;
		aux = fi2->inicio;	
		fi->fim->prox = aux;
		fi->fim = aux;
		fi2->inicio = fi2->inicio->prox;
		fi->quantidade++;
		fi2->quantidade--;
	}
		fi2->fim = NULL;
	return 1;
}

int inverter(Fila *fi){

	if(fi==NULL){
		printf("FILA INEXISTENTE\n");
		return 0;
	}
	if(fi->inicio == NULL){
		printf("VAZIA\n");
		return 0;
	}
	if(fi->quantidade==1){
		return 0;
	}

	Fila *nova;
	nova = NULL;
	nova = criar();


	while(fi->inicio->prox != NULL){
		Elem *aux;
		aux = fi->inicio;
		fi->inicio = fi->inicio->prox;
		
		if(nova->inicio == NULL){
			nova->inicio = aux;
			nova->fim = aux;
			nova->fim->prox = NULL;
		}else{
			Elem *aux2;
			aux2 = nova->inicio;
			nova->inicio = aux;
			nova->inicio->prox = aux2;
		}
	}

		migrar(fi,nova);
		destruir(nova);
		

	return 1;

}

