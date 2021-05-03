struct cliente{
	char nome[50];
	int cpf;
};



typedef struct nodescritor Fila;
//i) Básicas. Criar, destruir, inserir, remover e acessar;
Fila *criar();
int inserir(Fila *,struct cliente);
int remover(Fila *);
int acessar(Fila *,struct cliente*);
void destruir(Fila *);
int tamanho(Fila *);
//ii) Imprimir Fila Completa. Mostrar cada elemento da Fila, um após o outro;
void Imprimir(Fila *);
//iv) Migrar Fila. Dado duas Filas A e B, colocar todos elementos de B em A e deixar B sem nenhum elemento.
int migrar(Fila *,Fila*);
//iii) Inverter Fila. Alterar os apontamentos da Fila atual para que ela se inverta, isto é, o primeiro vira o último e o último o primeiro;
int inverter(Fila *);
