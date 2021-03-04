/*
Nome : Joao Pedro Barcelos Lacerda
RA : 140977
Turma : Integral
Comentarios : Realizei o programa proposto, porem me deparei com o mesmo Erro
da semana passada, ao inserir o valor, como exemplo, "1,4" e posteriormente
inserir algo menor que 4, o programa da erro e nao insere mais nenhum numero
na matriz, na linha em questao
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINHA 100

typedef struct no *pme;
struct no
{
	int col, val;
	char gen;
	pme prox;
};
typedef pme matriz[MAX_LINHA];

void inicializa(matriz m, int l)
{ // inicializa padrao
	int i;
	for (i = 0; i < l; i++)
		m[i] = NULL;
}

void insere(matriz m, int i, int j)
{ // Insere padrao com o problema do N+1 e dps N
	pme novo, p, z;
	novo = (pme)malloc(sizeof(struct no));
	novo->val = 1;
	novo->col = j;
	novo->prox = NULL;
	if (m[i] == NULL)
	{
		m[i] = novo;
	}
	else
	{
		p = m[i];
		while (p->prox != NULL)
		{
			p = p->prox;
		}
		p->prox = novo;
	}
}

void imprime2(matriz m, int k, int col)
{ // Vertices adjacentes
	pme p = m[k];
	int *vetor = (int *)malloc(col * sizeof(int));
	int i = 0, j;

	while (p != NULL)
	{
		if (p->val == 1)
		{
			vetor[i] = p->col + 1;
			i++;
		}
		p = p->prox;
	}
	if (i == 0)
	{
		printf("O vertice %d nao possui vertices adjacentes.\n", k + 1);
	}
	else
	{ // tem um ou mais adjacente
		printf("Os vertices adjacentes do vertice %d sao: ", k + 1);
		for (j = 0; j < i; j++)
		{
			printf("%d", vetor[j]);
			if (j + 1 != i)
				printf(", ");
		}
	}
	printf(".\n");
}

void imprime(matriz m, int tlin, int tcol, int k)
{ // Matriz de adjacencia
	int i, j;
	pme p;
	printf("Matriz de adjacencia: \n		");
	for (i = 1; i <= tlin; i++)
	{
		printf("%d	", i);
	}
	printf("\n \n");
	for (i = 0; i < tlin; i++)
	{
		p = m[i];
		printf("	%d	", i + 1);
		for (j = 0; j < tcol; j++)
			if ((p != NULL) && (p->col == j))
			{
				printf("%d	", p->val);
				p = p->prox;
			}
			else
				printf("0	");
		printf("\n");
	}
	printf("\n\n");
	imprime2(m, k - 1, tcol);
}

void libera(matriz m, int l)
{ // Libera Padrao
	pme p, q;
	int i;
	for (i = 0; i < l; i++)
	{
		p = m[i];
		while (p != NULL)
		{
			q = p;
			p = p->prox;
			free(q);
		}
	}
}

int main()
{
	matriz m;
	int i, j, vertices, v = 0, k, orientado;
	char ori[5];
	printf("Informe numero de vertices:");
	scanf("%d", &vertices);
	while (vertices > MAX_LINHA || vertices <= 0)
	{ // Verificar erro no n de vertices
		printf("Digite um valor valido: ");
		scanf("%d", &vertices);
	}
	inicializa(m, vertices);
	printf("\nO grafo e orientado?");
	scanf("%s", &ori);
	while (v == 0)
	{ // Verificar erro na palavra digitada
		if ((strcmp(ori, "sim") == 0) || (strcmp(ori, "SIM") == 0))
		{
			v = 1;
			orientado = 1;
			break;
		}
		else
		{
			if ((strcmp(ori, "nao") == 0) || (strcmp(ori, "NAO") == 0))
			{
				v = 1;
				orientado = 0;
				break;
			}
		}
		printf("Erro\nDigite sim ou nao\n");
		scanf("%s", &ori);
	}
	v = 0;
	printf("Informe as conexoes, digite 0 para encerrar.\n");
	while (v == 0)
	{
		scanf("%d", &i);
		if (i == 0)
		{
			v = 1;
			break;
		}
		scanf(", %d", &j);
		if (j == 0)
		{
			v = 1;
			break;
		}
		if (orientado == 1)
		{
			insere(m, i - 1, j - 1);
		}
		else
		{
			insere(m, i - 1, j - 1);
			insere(m, j - 1, i - 1);
		}
	}
	printf("Informe o vertice que deseja saber seus adjacentes: ");
	scanf("%d", &k);
	imprime(m, vertices, vertices, k);
	libera(m, vertices);
	return (0);
}
