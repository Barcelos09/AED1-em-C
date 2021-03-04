/*
Nome : João Pedro Barcelos Lacerda
RA : 140977
Turma : Integral
Comentarios : Ao realizar o programa me deparei com diversos erros referentes aos ponteiros, na hora de trocar as letras, não consegui resolve-los a tempo da entrega do programa, porém
em alguns casos, como o exemplo dado, o programa funciona da forma correta.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista2 {
	char letra;
	struct lista2* ant;
	struct lista2* prox;
} TLista2;

typedef TLista2 *PLista2;

PLista2 Insere_Fim (PLista2 l, char *v) {
	PLista2 novo = (PLista2) malloc(sizeof(TLista2));
	if (novo == NULL) return NULL;
	novo->letra=v;
	//printf("%c", novo->letra);
	novo->prox = NULL;
	if (l == NULL) { // sera o primeiro
		novo->ant = NULL;
		l = novo;
		return novo;
	} else {
		PLista2 aux;
		aux = l;
		while(aux->prox != NULL) {
			aux = aux->prox;
		}
		aux->prox = novo;
		novo->ant = aux;
	}
	return l;
}

// IMPRIME OS PRODUTOS //
void imprime(PLista2 l) {
	PLista2 p; // PONTEIRO PARA PERCORRER A LISTA //
	//printf("entrou\n");
	for (p = l; p != NULL; p = p->prox)
		printf("%c", p->letra);
}

PLista2 trocaLetras(PLista2 l, char a, char b) {
	PLista2 p, k, aux, aux2;
	for (p=l; p!=NULL; p=p->prox) {
		//	printf("Compara letra %c com %c \n", a, p->letra);
		if(p->letra==a) {
			for (k=l; k!=NULL; k=k->prox) {
				//printf("letra %c com %c \n", b, k->letra);
				if(k->letra==b) {
					/*Logica encontrada para realizar a troca de letras dentro da frase, porém, com alguns erros, por exemplo, caso a primeira palavra da frase seja trocada,caso troque palavras adjacentes e caso a ultima letra seja trocada,o programa tende a funcionar incorretamente. */
					//printf("entrou if");
					aux=p->prox;
					aux2=p->ant;
					p->ant->prox=k;
					p->prox->ant=k;
					aux->ant=k;
					p->prox=k->prox;
					p->ant=k->ant;
					k->ant->prox=p;
					k->prox->ant=p;
					k->prox=aux;
					k->ant=aux2;
					return l;
				}
			}
		}
	}
	printf("Erro");
	return NULL;
}

int main() {
	PLista2 palavra = NULL;
	char string[30], chara , charb ;
	int tam,i;
	printf("Digite a palavra : \n");
	scanf("%s", &string);
	tam = strlen(string);
	for(i=0; i<tam; i++) {
		palavra=Insere_Fim (palavra, string[i]);// Inserindo a palavra na lista
	}
	printf("\n Insira a primeira letra : \n");
	scanf(" %c", &chara);
	printf("\n Insira a segunda letra : \n");
	scanf(" %c", &charb);
	//printf(" %c com %c \n", chara, charb);
	palavra=trocaLetras(palavra, chara, charb);//trocando as letras
	//printf("saiu de trocaletras\n");
	imprime(palavra); //imprimindo
	free(palavra);
	return 0; //Encerrando o programa
}

