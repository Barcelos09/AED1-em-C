/*
Nome : João Pedro Barcelos Lacerda
RA : 140977
Turma : Integral
Comentarios : Realizei ordenação de vetores, e utilizei as filas para imprimir a lista de candidatos convocados, Utilizei 2 filas para não modificar a função retira, pois a mesma só retira o primeiro da fila,
logo, criei outra fila para receber o ID dos candidatos que responderam Sim.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FILA 100

typedef struct {
	int itens [MAX_FILA];
	int n; /*numero de elementos armazenados na fila*/
	int ini; /* indice para o inicio da fila */
} TFila;

typedef TFila *PFila ;

PFila cria_fila() { //Função dos Slides
	PFila fila = (PFila) malloc (sizeof (TFila));
	fila->n = 0;
	fila->ini = 0;
	return (fila);
}

int incr_indice(int i) { //Função dos Slides
	if (i==MAX_FILA-1)
		return 0;
	else
		return i+1;
}

int insere (PFila p, int *val) { //Função dos Slides
	int fim;
	if (p==NULL) {
		printf("Fila nao inicializada!\n");
		return -1;
	}
	if (p->n == MAX_FILA ) {
		printf("Fila cheia!\n");
		return -1;
	}
	fim = (p->ini+p->n)%MAX_FILA;
	p->itens[fim] = val;
	p->n++;
	return 0;
}

int retira (PFila p, int* val) { //Função dos Slides
	if (p==NULL) {
		printf("Fila nao inicializada!\n");
		return -1;
	}
	if (p->n ==0) {
		printf("Fila vazia!\n");
		return -1;
	}
	*val = p->itens[p->ini];
	p->ini = incr_indice(p->ini);
	p->n--;
	return 0;
}

int main() {
	PFila fila, fila2;
	int qtd, vagas, i, k, val; //qtd = n , vagas = i
	int *notas, *id;
	fila=cria_fila();
	fila2=cria_fila(); //Fila dos que responderam "S"
	int aux[10];
	char resp[5];
	printf("\nInsira a quantidade de candidatos:\n");
	scanf("%d", &qtd);
	notas=(int *)malloc(sizeof(int)*qtd);
	id=(int *)malloc(sizeof(int)*qtd);
	printf("\nInsira a quantidade de vagas:\n");
	scanf("%d", &vagas);
	for(i=0; i<qtd; i++) {
		printf("\nNumero Identificador do candidato:\nNota do candidato: \n");
		scanf("%d %d", &id[i], &notas[i]);
		printf("Candidato Inserido\n"); //Optei por Inserir os candidatos posteriormente, após ordenar as notas
	}
	for(i=0; i<qtd; i++) { // Ordenar em ordem crescente
		for(k=i+1; k<qtd; k++) {
			if(notas[i]<notas[k]) {
				aux[0]=notas[i];
				aux[1]=id[i];
				notas[i]=notas[k];
				id[i]=id[k];
				notas[k]=aux[0];
				id[k]=aux[1];
			}
		}
		insere(fila, id[i]); //Insere na fila os ID's já de forma ordenada
	}
	printf("\n -IMPRESSAO DA FILA- \n");
	for(i=0; i<qtd; i++) {
		printf("\nCandidato %d, nota: %d\n", id[i], notas[i]);
	}
	for(i=0, k=0; (i!=qtd) && (k!=vagas); i++) {
		printf("Resposta do candidato, cujo ID e : %d (S/N) \n", id[i]);
		scanf("%s", resp);
		if(stricmp(resp, "n") == 0) { //Se o candidato responder não, seu ID só será retirado da fila
			retira(fila, &val);
		} else { //Caso o candidato responda Sim, seu ID será retirado da fila e inserido em outra fila, essa que contém somente os candidatos que serão chamados
			retira(fila, &val);
			insere(fila2, val);
			k++;
		}
	}
	printf("-Lista dos novos alunos- \n \n");
	while(fila2->n > 0){	
		retira(fila2, &val); //Val recebe o ID's dos novos candidatos
		printf("Candidato id: %d \n", val);
	}
	free(notas);
	free(id);
	free(fila);
	free(fila2);
	return 0;
}
