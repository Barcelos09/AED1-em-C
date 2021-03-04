/*
Nome : Jo�o Pedro Barcelos Lacerda
RA : 140977
Turma : Integral
Comentarios : N�o consegui realizar o programa exigido, s� consegui transformar o n�mero de in-fixo para p�s-fixo
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PILHA 10

typedef struct {
	char vet[MAX_PILHA];
	int topo;

} TPilha;

TPilha* nova() {
	TPilha* np = (TPilha *) malloc (sizeof (TPilha));
	np->topo = -1;
	return np;
}

int push (TPilha* p, char val) {
	if (p->topo >=MAX_PILHA-1) { // Pilha cheia
		return -1;
	}
	(p->topo)++;
	p->vet[p->topo] = val;
	return 0;
}

int pop (TPilha* p, char *val) {
	if (p->topo < 0) { // Pilha vazia
		return -1;
	}
	*val = p->vet[p->topo];
	p->topo--;
	return 0;
}

TPilha *remover (TPilha* p) {
	free (p);
	return (NULL);
}

int main () {
	TPilha *minhapilha;
	char Prefix [MAX_PILHA];
	int Num [MAX_PILHA];
	char Posfix [MAX_PILHA];
	minhapilha = nova();
	int i, k=0, tam, cont=0;
	if(minhapilha == NULL) {
		printf("Erro na aloca��o da pilha");
		return 1;
	}
	gets(Prefix);
	tam=strlen(Prefix);
	for(i=0; i<40; i++) {
		switch(Prefix[i]) {
			case '+':
				Posfix [tam-1]='+';
				tam--;
				break;

			case '-' :
				Posfix [tam-1]='-';
				tam--;
				break;

			case '*' :
				Posfix [tam-1]='*';
				tam--;
				break;

			case '^' :
				Posfix [tam-1]='^';
				tam--;
				break;

			case '/' :
				Posfix [tam-1]='/';
				tam--;
				break;

			default :
				if(push(minhapilha, Prefix[i])==-1) {
					printf("Pilha cheia");
				}
				cont++;
				break;
		}
	}
	for(i=0; i<cont; i++) {
		pop(minhapilha, Posfix[i]);
	}
	printf("%s", Posfix);
	remover(minhapilha);
	return 0;

}
