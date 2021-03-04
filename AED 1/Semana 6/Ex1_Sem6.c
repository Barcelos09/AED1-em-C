/*
Nome : João Pedro Barcelos Lacerda
RA : 140977
Turma : Integral
Comentarios : Consegui produzir o programa proposto, porém, com muita dificuldade.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista {
	int info;	// Informação do jogador, padrão como contagem
	int soma;	// Soma de suas pontuações a cada carta
	struct lista* prox;
} TLista;
typedef TLista *PLista;

void imprime_circular (PLista ultimo) { //Impressão a cada rodada
	PLista p;
	if (ultimo !=NULL) {
		p = ultimo->prox;
		/* percorre os elementos até alcançar novamente o
		início */
		printf("Situacao da lista: \n");
		do {
			printf("Jogador = %d	", p->info);
			printf("pontuacao = %d\n", p->soma);
			p = p->prox;
		} while (p != ultimo->prox);
	}
}

PLista Pop(PLista ultimo, PLista p) { //Retira elemento da lista circular
	PLista ant = ultimo->prox;
	while(ant->prox != p)
		ant = ant->prox;
	if(ant == NULL)
		printf("Lista vazia!\n\n");
	else {
		ant->prox = p->prox;
		if(p==ant) {
			ant = NULL;
			return NULL;
		}
	}
	return ultimo;
}

PLista Push (PLista ultimo, int val) {	//Função utilizada para criar a lista
	PLista novo = (PLista) malloc (sizeof(TLista));
	novo->info = val;
	if (ultimo == NULL) {
		novo->prox=novo;
		ultimo = novo;
	} else {
		novo -> prox = ultimo -> prox;
		ultimo -> prox = novo;
		ultimo = novo;
	}
	ultimo->soma = 0;
	return ultimo;
}

void libera (PLista ultimo) {	//Free
	PLista p = ultimo->prox;
	PLista q = ultimo;
	while(p != ultimo) {
		q = p;
		p = p->prox;
		free(q);
	}
	free(ultimo);
}

int main() {
	PLista ultimo = NULL;
	char carta[3];
	int cont, i, qtd = 0, val;
	PLista p;
	ultimo = NULL;
	printf("Digite a quantidade de jogadores: ");
	scanf("%d", &qtd);
	if(qtd<=1) {
		printf("Quantidade invalida, insira a quantidade de jogadores (>1): ");
		scanf("%d", &qtd);
	}
	for(i=1; i<=qtd; i++) {
		ultimo = Push(ultimo, i);	//Inicializa a Lista circular
	}
	p = ultimo->prox;
	while(qtd>1) {
		printf("Digite uma carta (numero de 2 a 9 ou as letras A,J,K ou Q):");
		scanf("%s", carta);
		if(strcmp(carta,"A")==0) {	//Tranformação da letra A pelo seu valor equivalente
			strcpy(carta, "11");
		}
		if(strcmp(carta, "J")==0 || strcmp(carta, "K")==0 || strcmp(carta, "Q")==0) {	//Tranformação da letra J,K,Q pelo seu valor equivalente
			strcpy(carta, "10");
		}
		val = atoi(carta);	//Função utilizada para transformar uma string em um valor int, para possibilitar a utilização da função switch
		switch(val) {
			case 11: {
				p->soma+=11;
				if(p->soma>21) {	//caso o jogador perda, se repete em cada case
					printf("\nJogador %d perdeu. Pontuacao %d \n", p->info, p->soma);
					ultimo = Pop(ultimo,p);
					qtd--;
					cont--;
				}
				if(p->soma==21) {	//caso o jogador ganhe, se repete em cada case
					printf("O jogador vencedor: %d pontuacao: %d", p->info, p->soma);
					libera (ultimo);
					return 0;
				}
				p=p->prox;
				cont++;
				break;
			}
			case 10: {
				p->soma+=10;
				if(p->soma>21) {
					printf("\nJogador %d perdeu. Pontuacao %d \n", p->info, p->soma);
					ultimo = Pop(ultimo,p);
					qtd--;
					cont--;
				}
				if(p->soma==21) {
					printf("O jogador vencedor: %d pontuacao: %d", p->info, p->soma);
					libera (ultimo);
					return 0;
				}
				p=p->prox;
				cont++;
				break;
			}
			case 2: {
				p->soma+=2;
				if(p->soma>21) {
					printf("\nJogador %d perdeu. Pontuacao %d \n", p->info, p->soma);
					ultimo = Pop(ultimo,p);
					qtd--;
					cont--;
				}
				if(p->soma==21) {
					printf("O jogador vencedor: %d pontuacao: %d", p->info, p->soma);
					libera (ultimo);
					return 0;
				}
				p=p->prox;
				cont++;
				break;
			}
			case 3: {
				p->soma+=3;
				if(p->soma>21) {
					printf("\nJogador %d perdeu. Pontuacao %d \n", p->info, p->soma);
					ultimo = Pop(ultimo,p);
					qtd--;
					cont--;
				}
				if(p->soma==21) {
					printf("O jogador vencedor: %d pontuacao: %d", p->info, p->soma);
					libera (ultimo);
					return 0;
				}
				p=p->prox;
				cont++;
				break;
			}
			case 4: {
				p->soma+=4;
				if(p->soma>21) {
					printf("\nJogador %d perdeu. Pontuacao %d \n", p->info, p->soma);
					ultimo = Pop(ultimo,p);
					qtd--;
					cont--;
				}
				if(p->soma==21) {
					printf("O jogador vencedor: %d pontuacao: %d", p->info, p->soma);
					libera (ultimo);
					return 0;
				}
				p=p->prox;
				cont++;
				break;
			}
			case 5: {
				p->soma+=5;
				if(p->soma>21) {
					printf("\nJogador %d perdeu. Pontuacao %d \n", p->info, p->soma);
					ultimo = Pop(ultimo,p);
					qtd--;
					cont--;
				}
				if(p->soma==21) {
					printf("O jogador vencedor: %d pontuacao: %d", p->info, p->soma);
					libera (ultimo);
					return 0;
				}
				p=p->prox;
				cont++;
				break;
			}
			case 6: {
				p->soma+=6;
				if(p->soma>21) {
					printf("\nJogador %d perdeu. Pontuacao %d \n", p->info, p->soma);
					ultimo = Pop(ultimo,p);
					qtd--;
					cont--;
				}
				if(p->soma==21) {
					printf("O jogador vencedor: %d pontuacao: %d", p->info, p->soma);
					libera (ultimo);
					return 0;
				}
				p=p->prox;
				cont++;
				break;
			}
			case 7: {
				p->soma+=7;
				if(p->soma>21) {
					printf("\nJogador %d perdeu. Pontuacao %d \n", p->info, p->soma);
					ultimo = Pop(ultimo,p);
					qtd--;
					cont--;
				}
				if(p->soma==21) {
					printf("O jogador vencedor: %d pontuacao: %d", p->info, p->soma);
					libera (ultimo);
					return 0;
				}
				p=p->prox;
				cont++;
				break;
			}
			case 8: {
				p->soma+=8;
				if(p->soma>21) {
					printf("\nJogador %d perdeu. Pontuacao %d \n", p->info, p->soma);
					ultimo = Pop(ultimo,p);
					qtd--;
					cont--;
				}
				if(p->soma==21) {
					printf("O jogador vencedor: %d pontuacao: %d", p->info, p->soma);
					libera (ultimo);
					return 0;
				}
				p=p->prox;
				cont++;
				break;
			}
			case 9: {
				p->soma+=9;
				if(p->soma>21) {
					printf("\nJogador %d perdeu. Pontuacao %d \n", p->info, p->soma);
					ultimo = Pop(ultimo,p);
					qtd--;
					cont--;
				}
				if(p->soma==21) {
					printf("O jogador vencedor: %d pontuacao: %d", p->info, p->soma);
					libera (ultimo);
					return 0;
				}
				p=p->prox;
				cont++;
				break;
			}
			default: {	//Caso o jogador digite algo errado
				printf("Valor invalido!! Digite novamente um novo valor.\n");
				break;
			}
		}
		if(p->prox == p) {	//Caso reste somente um jogador
			printf("O jogador vencedor: %d pontuacao: %d", p->info, p->soma);
			libera (ultimo);
			return 0;
		}
		if(cont==qtd) {	//Imprime a situação da lista a cada rodada
			cont=0;
			p=ultimo->prox;
			imprime_circular(ultimo);
		}
	}
	libera (ultimo);
	return 0;
}
