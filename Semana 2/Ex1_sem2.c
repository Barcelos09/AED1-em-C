/*

Nome : João Pedro Barcelos Lacerda
RA : 140977
Turma : Integral
Comentarios : Adicionado comentarios nas linhas: 15, 20 e 30, referentes a verificação de erros  e um comentario na linha 26, referente a logica utilizada.

*/
#include <stdio.h>
#include <stdlib.h>

int main(){
	int i, *vet, qtd, voto, ganhador=0;
	printf("Insira a quantidade de candidatos\n");
	scanf("%d", &qtd);
	if(qtd<1){
		printf("Quantidade invalida de candidatos!, finalizando o programa."); //Verificação de erros
		return 0;
	}
	vet = (int *) calloc(qtd,sizeof(int));
	if(vet == NULL){
		printf("Erro na alocaçao"); //Verificação de erros
		return 0;
	}
	while(1){
		printf("Insira seu voto\n"); 
		scanf("%d", &voto);
		if(voto<=0){ // Na teoria,  0 não é um numero inteiro negativo, porém resolvi fazer dessa forma, visto que não existiria candidato 0.
			break;
		}
		if(voto>qtd){
			printf("Candidato inexistente!\n"); //Verificação de erros
		}
		else{
			voto--;
			*(vet+voto)+=1;
		}
	}
	for(i=1;i<qtd;i++){
		if(*(vet+ganhador)==*(vet+i)){ //Metodo de desempate
			if(i>ganhador){
				ganhador=i;
			}
		}
		else{
			if(*(vet+ganhador)<*(vet+i)){
			ganhador=i;
			}
		}
	}
	printf("O ganhador foi o candidato %d", ganhador+1);
	free (vet);
	return 0;
}
