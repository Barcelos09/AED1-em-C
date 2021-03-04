/*
Nome: João Pedro Barcelos Lacerda
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
	
int Imprima_Dados (pessoa Pessoas){
printf("\n Nome: %s \n Idade: %d anos \n Altura: %d cm \n", Pessoas.nome, Pessoas.idade, Pessoas.altura);
}

int main(){
int i, qtd=0;
printf("Insira o Numero de pessoas a serem registradas:\n");
scanf("%d", &qtd);
pessoa Pessoas[qtd];
for(i=0; i<qtd; i++){
	printf("Digite \n Nome: \n Idade: \n Altura: \n");
	scanf("%s", &Pessoas[i].nome);
	scanf("%d", &Pessoas[i].idade);
	scanf("%d", &Pessoas[i].altura);
}
for(i=0; i<qtd; i++){
    Imprima_Dados(Pessoas[i]);
}

free (Pessoas);
return 0;
}
