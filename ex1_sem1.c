/*
Nome: Jo�o Pedro Barcelos Lacerda
RA: 140977
email: joao.lacerda09@unifesp.br
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char nome[10];
	int idade;
	int altura;
	}pessoa;

int main(){
pessoa *Pessoas;
Pessoas = (pessoa*)malloc(sizeof(pessoa));
if (Pessoas == NULL){
	printf("Erro na aloca��o");
	return 1;
}
printf("Digite \n Nome: \n Idade: \n Altura: \n");
gets(Pessoas->nome);
scanf("%d", &Pessoas->idade);
scanf("%d", &Pessoas->altura);
printf("\n Nome: %s \n Idade: %d anos \n Altura: %d cm \n", Pessoas->nome, Pessoas->idade, Pessoas->altura);
free (Pessoas);
return 0;
}
