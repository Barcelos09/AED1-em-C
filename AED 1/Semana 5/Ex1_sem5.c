/*
Nome : João Pedro Barcelos Lacerda
RA : 140977
Turma : Integral
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista {
	int info_codigo;
	char info_nome[10];
	float info_valor;
	struct lista* prox;
} TLista;
typedef TLista *PLista;

PLista inicializa_lista() {
	return NULL;
}

PLista Insere_ord (PLista l, int codigo, char *nome, float valor) {
	PLista novo; //novo elemento
	PLista ant = NULL; //ponteiro auxiliar para a posição anterior
	PLista ptaux = l; //ponteiro auxiliar para percorrer a lista
	/*aloca um novo nodo */
	novo = (TLista*) malloc(sizeof(TLista));
	/*insere a informação no novo nodo*/
	novo->info_codigo = codigo;
	strcpy(novo->info_nome, nome);
	novo->info_valor = valor;
	/*procurando a posição de inserção*/
	while ((ptaux!=NULL) && (ptaux->info_codigo)<codigo) {
		ant = ptaux;
		ptaux = ptaux->prox;
	}
	/*encadeia o elemento*/
	if (ant == NULL) { /*o anterior não existe, será inserido na 1a posição*/
		novo->prox = l;
		l = novo;
	} else { /*elemento inserido no meio da lista*/
		novo->prox = ant->prox;
		ant->prox = novo;
	}
	return l;
}

PLista busca (PLista l, char v[]) {
	PLista p;
	for (p=l; p!=NULL; p=p->prox) {
		if (stricmp(p->info_nome, v) == 0) {
			printf("Valor do produto : %f R$ \n", p->info_valor);
			return p;
		}
	}
	printf("Produto nao encontrado\n");
	return NULL;
}

PLista retira (PLista l, char v[]) {
	PLista ant = NULL; /* ponteiro para elemento anterior */
	PLista p; /* ponteiro para percorrer a lista*/
	/* procura elemento na lista, guardando anterior */
	for (p=l; p!=NULL && (stricmp(p->info_nome, v) != 0); p = p->prox) {
		ant = p;
	}
	/* verifica se achou elemento */
	if (p == NULL)
		return l; /* não achou: retorna lista original */
	/* retira elemento */
	if (ant == NULL)
		/* retira elemento do inicio */
		l = p->prox;
	else
		/* retira elemento do meio da lista */
		ant->prox = p->prox;
	free(p);
	return ;
}

void libera (PLista l) {
	PLista p = l, t;
	while (p != NULL) {
		t = p->prox; /* guarda referência para o próximo elemento*/
		free(p);
		p = t; /* faz p apontar para o próximo */
	}
}
int main () {
	int codigo;
	float valor;
	char nome[10];
	char resp[3];
	PLista Lista;
	PLista p;
	Lista = inicializa_lista ();
	printf ("Deseja inserir um produto? (s/n)");
	scanf("%s", &resp);
	while(stricmp(resp, "s") == 0) { // Inserir produtos
		printf("Insira o codigo do produto\n Codigo: ");
		scanf("%d", &codigo);
		printf("\n Insira o nome do produto\n Nome: ");
		scanf("%s", &nome);
		printf("\n Insira o valor do produto\n valor: ");
		scanf("%f", &valor);
		printf(" \n%f\n", valor);
		Lista = Insere_ord (Lista, codigo, nome, valor);
		printf ("Deseja inserir outro produto? (s/n)");
		scanf("%s", &resp);
	}
	printf ("Deseja buscar um produto? (s/n)");
	scanf("%s", &resp);
	while(stricmp(resp, "s") == 0) {	//Buscar produtos
		printf("\nInsira o nome do produto que deseja saber o valor\n Nome: ");
		scanf("%s", &nome);
		busca (Lista, nome);
		printf ("Deseja buscar outro produto? (s/n)");
		scanf("%s", &resp);
	}
	printf ("Deseja excluir um produto? (s/n)");
	scanf("%s", &resp);
	while(stricmp(resp, "s") == 0) { //Excluir produto
		printf("\nInsira o nome do produto que deseja excluir\n Nome: ");
		scanf("%s", &nome);
		retira (Lista, nome);
		printf ("Deseja excluir outro produto? (s/n)");
		scanf("%s", &resp);
	}
	libera (Lista);
	return 0;
}
