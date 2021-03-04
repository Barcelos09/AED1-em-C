/*
Nome : João Pedro Barcelos Lacerda
RA : 140977
Turma : Integral
*/
#include <stdio.h>
#include <stdlib.h>
#define MAXFILHOS 30 //numero maximo de filhos= (x-4)/2

typedef struct arv
{
    char info;
    struct arv *esq;
    struct arv *dir;
} TArv;
typedef TArv *PArv;

PArv inicia(PArv a)  //Funcao para iniciar a arvore
{
    a = (PArv)malloc(sizeof(TArv));
    a->esq = NULL;
    a->dir = NULL;
    a->info = '0';
    return a;
}

void cria(PArv a, char *filhos)
{
    char *numfilhos = &filhos[2];
    int nfilhos = atoi(numfilhos),i;  //transforma char em int
    if (a->info == '0')
    {
        a->info = filhos[0];
        a->dir = NULL;
    }
    PArv novo = (PArv)malloc(sizeof(TArv));
    novo->esq = NULL;
    novo->info = filhos[4];
    nfilhos--;
    PArv percorre = novo;
    PArv novo2;
    for(i=6; nfilhos>0; i+=2,nfilhos--) //Preencher a arvore
    {
        novo2 = (PArv)malloc(sizeof(TArv));
        novo2->info=filhos[i];
        novo2->esq = NULL;
        percorre->dir=novo2;
        percorre=novo2;
    }
    percorre->dir=NULL;
    a->esq=novo;
}

void imprime_fei (PArv a) //Imprimir irmaos
{
    if (a!=NULL)
    {
        printf("%c ", a->info); /* mostra raiz */
        imprime_fei(a->dir); /* mostra sad */
    }
}

void imprime_pre (PArv a) //Imprime dos slides
{
    if (a!=NULL)
    {
        printf("%c", a->info); /* mostra raiz */
        imprime_pre(a->esq); /* mostra sae */
        imprime_pre(a->dir); /* mostra sad */
    }
}

void imprime_in(PArv a) //Imprime adaptada
{
    //mostra a arvore em ordem
    if (a->esq)  //Percorre a arvore pela esquerda, para depois imprimir
    {
        imprime_in(a->esq);
    }
    printf("%c", a->info);
    if (a->dir)
    {
        imprime_in(a->dir);
    }
}

void buscaArv(PArv a, char *filhos)
{
    if (a->info == filhos[0])
        cria(a, filhos); //se encontrou o valor, ele é o pai a receber filhos a esquerda
    if (a->esq)
        buscaArv(a->esq, filhos); //busca na sub arvore esquerda
    if (a->dir)
        buscaArv(a->dir, filhos); //busca na sub arvore direita
}

void busca_filhos(PArv a, char resp)
{
    if (a->info == resp)
        imprime_fei(a->esq); //encontrando o valor, imprime a esquerda e todos a direita posteriormente
    if (a->esq)
        busca_filhos(a->esq, resp); //busca na sub arvore esquerda
    if (a->dir)
        busca_filhos(a->dir, resp); //busca na sub arvore direita
}

void busca_irmaos(PArv a, char resp)
{
    if (a->info == resp)
        imprime_fei(a->dir); //se encontrou o valor, imprime todos a direita
    if (a->esq)
        busca_irmaos(a->esq, resp); //busca na sub arvore esquerda
    if (a->dir)
        busca_irmaos(a->dir, resp); //busca na sub arvore direita
}

PArv libera (PArv a) // Libera dos slides
{
    if (a!=NULL)
    {
        libera(a->esq); /* libera sae*/
        libera(a->dir); /* libera sad*/
        free(a); /* libera raiz*/
    }
    return NULL;
}

int main()
{
    PArv a = inicia(a);
    FILE *arq;
    char linha[MAXFILHOS], *plinha, resp;
    int aux=0, op, z=1;
    arq = fopen("arv.txt", "r");
    if(arq == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return 0;
    }
    else
    {
        do
        {
            if(z==1) // Raiz
            {
                plinha = fgets(linha, MAXFILHOS, arq);
                cria(a, linha);
                z++;
            }
            else
            {
                plinha = fgets(linha, MAXFILHOS, arq);
                buscaArv(a, linha);
            }
        }
        while (!feof(arq));
    }
    printf("\nArvore resultante em pre-ordem :\n");
    imprime_pre (a);
    printf("\nArvore resultante em ordem Infixa :\n");
    imprime_in (a);
    while(aux==0)
    {
        printf("\n\n---------------------------------------------------------\n");
        printf("1) Imprimir a arvore resultante em pre-ordem.\n");
        printf("2) Imprimir a arvore resultante em ordem infixa.\n");
        printf("3) Imprimir os filhos de um dado no.\n");
        printf("4) Imprimir os irmaos de um dado no.\n");
        printf("5) Sair.");
        printf("\n\nSelecione uma opcao \n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
        {
            imprime_pre (a);
            break;
        }
        case 2:
        {
            imprime_in (a);
            break;
        }
        case 3:
        {
            printf("Qual o no, ao qual deseja saber seus filhos?");
            scanf(" %c", &resp);
            printf("Filhos de %c : \n", resp);
            busca_filhos(a, resp);
            printf("\n\n");
            break;
        }
        case 4:
        {
            printf("Qual o no, ao qual deseja saber seus irmaos?");
            scanf(" %c", &resp);
            printf("Irmaos de %c : \n", resp);
            busca_irmaos(a, resp);
            printf("\n\n");
            break;
        }
        case 5:
        {
            aux=5;
            break;
        }
        default :
        {
            printf("Selecione uma opcao correta");
        }
        }
    }
    libera(a);
    fclose(arq);
    return 0;
}
