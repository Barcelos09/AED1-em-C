#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINHA 100

typedef struct no *pme;
struct no {
	int col, val;
	char gen;
	pme prox;
};
typedef pme matriz[MAX_LINHA];

void inicializa(matriz m, int l) {
	int i;
	for (i=0; i<l; i++)
		m[i] = NULL;
}

void insere(matriz m, int i,int j) {
	pme novo, p, z;
	int aux = 0;
	novo = (pme)malloc(sizeof(struct no));
	novo->val = 1;
	novo->col = j;
	novo->prox = NULL;
	do {
		printf("Digite o genero do filme: ");
		scanf(" %c", &novo->gen);
		if(novo->gen=='A') break;	//AÇÃO
		if(novo->gen=='R') break;	//ROMANCE
		if(novo->gen=='S') break;	//SUSPENSE
		if(novo->gen=='C') break;	//COMEDIA
		if(novo->gen=='M') break;	//MUSICAL
		if(novo->gen=='D') break;	//DRAMA
		if(novo->gen=='F') break;	//FICÇÃO
		if(novo->gen=='P') break;	//POLICIAL
		printf("\nGenero invalido!!\n\n");
	} while (aux==0);
	if (m[i]==NULL) {
		m[i] = novo;
	} else {
		p=m[i];
		while(p->prox!=NULL) {
			if(p->col>novo->col){ //Teste
				/*z=p;
				p=novo;
				novo=z;	*/
				printf("Entrou");
			}
			p=p->prox;
		}
		p->prox = novo;
	}
}

void imprime(matriz m, int tlin, int tcol ) {
	int i,j;
	pme p;
	printf("Matriz inteira: \n");
	for(i=0; i<tlin; i++) {
		p = m[i];
		for(j=0; j<tcol; j++)
			if ((p!=NULL) && (p->col==j)) {
				printf(" %d ",p->val);
				p = p->prox;
			} else
				printf(" 0 ");
		printf("\n");
	}
	printf("\n\n");
}

void imprime2(matriz m, int tlin, int tcol ) {
	int i,j,x;
	pme p;
	printf("Matriz condensada: \n");
	for(i=0; i<tlin; i++) {
		p = m[i];
		printf("Cliente: %d \n 	Filmes assistidos (filme e genero): ", i+1);
		for(j=0; j<tcol; j++)
			if ((p!=NULL) && (p->col==j)) {
				//x=p->col=1;
				printf("\n	 %d 	%c ",p->col+1, p->gen);
				p = p->prox;
			}
		printf("\n\n");
	}
	printf("\n\n");
}

char *contgen(matriz m, int lin, int col) {
	int i,j, vet[8], aux, aux2;
	char *Retorno;
	pme p;
	for(i=0; i<8; i++) {
		vet[i]=0;
	}
	for(i=0; i<lin; i++) {
		p = m[i];
		for(j=0; j<col; j++)
			if ((p!=NULL) && (p->col==j)) {
				if(p->gen=='A') vet[0]++;
				if(p->gen=='R') vet[1]++;
				if(p->gen=='S') vet[2]++;
				if(p->gen=='C') vet[3]++;
				if(p->gen=='M') vet[4]++;
				if(p->gen=='D') vet[5]++;
				if(p->gen=='F') vet[6]++;
				if(p->gen=='P') vet[7]++;
				p = p->prox;
			}
	}
	aux = vet[0];
	aux2 = 0;
	for(i=1; i<8; i++) {
		if(vet[i]>aux) {
			aux = vet[i];
			aux2 = i;
		}
	}
	switch (aux2) {
		case 0: {
			Retorno = "Acao";
			return Retorno;
		}
		case 1: {
			Retorno = "Romance";
			return Retorno;
		}
		case 2: {
			Retorno = "Suspense";
			return Retorno;
		}
		case 3: {
			Retorno = "Comedia";
			return Retorno;
		}
		case 4: {
			Retorno = "Musical";
			return Retorno;
		}
		case 5: {
			Retorno = "Drama";
			return Retorno;
		}
		case 6: {
			Retorno = "Ficcao";
			return Retorno;
		}
		case 7: {
			Retorno = "Policial";
			return Retorno;
		}
		default: {
			Retorno = "Erro";
			return Retorno;
		}
	}
}

void libera(matriz m, int l) {
	pme p, q;
	int i;
	for(i=0; i<l; i++) {
		p = m[i];
		while (p!=NULL) {
			q = p;
			p = p->prox;
			free(q);
		}
	}
}

int main( ) {
	matriz m;
	int lin, col, i, j, val, aux, num,teste[10],k;
	do {
		printf("Insira a quantidade de clientes (menor que %d: )", MAX_LINHA+1);
		scanf("%d", &lin);
	} while (lin<0 || lin>MAX_LINHA);
	printf("Quantidade de filmes: ");
	scanf("%d", &col);
	inicializa(m,lin);
	for(i=0; i<lin; i++) { //For para cada cliente
		for(k=0;k<10;k++){
			teste[k]=0;
		}
		printf("\nQuantos filmes o cliente %do ja assistiu?", i+1);
		scanf("%d", &aux);
		for(j=0; j<aux; j++) { //For para cada filme assistido
			printf("\nDigite o numero do %do. filme assistido:", j+1);
			scanf("%d", &num);
			for(k=0; k<10; k++) { //Teste se o filme é valido
				if(num>col || num<=0) {
					printf("Filme invalido \n Insira o valor correto \n");
					printf("\nDigite o numero do %do. filme assistido:", j+1);
					scanf("%d", &num);
					k=-1;
				}
				else{
					if(teste[k]==num) {
					printf("Filme ja inserido\nInsira outro filme\n");
					printf("\nDigite o numero do %do. filme assistido:", j+1);
					scanf("%d", &num);
					k=-1;
					}
				}
			}
			teste[j]=num;
			num-=1;
			insere(m,i,num);
		}
	}
	imprime(m,lin,col);	//Matriz Inteira
	imprime2(m,lin,col); //Matriz Condensada
	printf("O genero de filme mais assistido foi: %s", contgen (m, lin, col));
	libera(m,lin);
	return(0);
}
