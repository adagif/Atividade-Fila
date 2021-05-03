#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "atFila.h"



void menu();
void imprimir();

int main(){

int opc;
	Fila * fi;
	Fila * fi2;

	fi = NULL;
	fi2 = NULL;

	struct cliente c;
	struct cliente c2;
	
	do{

	menu();
	printf("->");
	scanf("%d",&opc);

	switch (opc){
		case 1:
		fi = criar();
		fi2 = criar();
		printf("\nCRIADO\n");
		break;
		case 2:
		c.cpf = 9988 ;
		strcpy(c.nome,"Maria");
		inserir(fi,c);

		c.cpf = 2827;
		strcpy(c.nome,"Arya Stark");
		inserir(fi,c);

		c.cpf = 1928;
		strcpy(c.nome,"Jon Snow");
		inserir(fi,c);

		c.cpf = 3928;
		strcpy(c.nome,"Sansa Stark");
		inserir(fi,c);

		c.cpf = 6827;
		strcpy(c.nome,"Khal Drogo");
		inserir(fi,c);

		//----------------------
		c2.cpf = 8182;
		strcpy(c2.nome,"Cercei Lannister");
		inserir(fi2,c2);

		c2.cpf = 2928;
		strcpy(c2.nome,"Tyrion Lannister");
		inserir(fi2,c2);

		c2.cpf = 4000;
		strcpy(c2.nome,"Joffrey Lannister");
		inserir(fi2,c2);

		c2.cpf = 8383;
		strcpy(c2.nome,"Daenerys Targaryen");
		inserir(fi2,c2);

		printf("\nINSERIDO\n");
		break;
		case 3:
		remover(fi);
		printf("\nREMOVIDO\n");
		break;
		case 4:
		acessar(fi,&c);
		printf("\nPRIMEIRO: %s %d\n",c.nome,c.cpf);
		break;
		case 5:
		destruir(fi);
		printf("\nDESTRUIDO\n");
		break;
		case 6:
		tamanho(fi);
		break;
		case 7:
		imprimir(fi);
		break;
		case 8:	
		inverter(fi);
		printf("\nINVERTIDO\n");
		break;
		case 9: 
		migrar(fi,fi2);
		printf("\nMIGRADO\n");
		break;
		case 0:
		printf("\nATE :) \n");
		break;
		default:
		printf("OPCAO INEXISTENTE\n");
	}


	}while(opc != 0);
	
	return 0;
}

void menu(){
	printf("-------------------------------\n");
	printf("     TRABALHO #2: FILA         \n");    
	printf("     MARIA EDUARDA (^-^)/        \n");   
	printf("-------------------------------\n");

	printf("1.CRIAR\n");
	printf("2.INSERIR\n");
	printf("3.REMOVER\n");
	printf("4.ACESSAR\n");
	printf("5.DESTRUIR\n");
	printf("6.TAMANHO\n");
	printf("7.IMPRIMIR\n");
	printf("8.INVERTER\n");
	printf("9.MIGRAR\n");
	printf("0.SAIR\n\n");
	
}


	

