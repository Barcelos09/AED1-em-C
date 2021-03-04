/*
Nome: João Pedro Barcelos Lacerda
RA: 140977
email: joao.lacerda09@unifesp.br
Comentarios: Escreve em um arquivo nomes, e depois compara, e verifica quantas pessoas tem com aquele nome
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Nome_compara(char comp[10]){
	FILE *arq2;
	char palavra[100];
	int cont=0;
	arq2=fopen("arquivo.txt", "r");
	if(arq2 == NULL){
		printf("Erro na leitura do arquivo");
		return 1;
	}
	while(fscanf(arq2, "%s", &palavra) != EOF){
		if(strcmp(comp, palavra) == 0){
			cont++;
		}
	}
	fclose(arq2);
	return cont;
}

int main(){
FILE *arq;
char nome[10];
char comp[10];
arq = fopen("arquivo.txt", "w");
if(arq == NULL){
	printf("Erro na criação do arquivo");
	return 1;
}
printf("Digite FIM, para encerrar o processo \n");
while (1)
{
	printf("Digite um nome para gravar no arquivo \n Nome: ");
	scanf("%s", &nome);
	if(strcmp(nome, "FIM") == 0){
		break;
	}
	else{
		fprintf(arq, "%s \n", nome);
	}
}
fclose(arq);
printf("Digite um nome, para verificar quantas pessoas possuem esse nome dentro do arquivo \n");
scanf("%s", &comp);
printf("Quantidade de pessoas com esse nome dentro do arquivo: %d", Nome_compara(comp));
return 0;
}
