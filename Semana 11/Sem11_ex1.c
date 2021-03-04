/*
João Pedro Barcelos Lacerda
140977
Turma I
*/

int verifica(PArv a)
{
    if (a->esq->info > a->info){
      return 0;
    }
    if (a->dir->info < a->info){
      return 0;
    }
    if (a->esq)
      if(verifica(a->esq)==0){
      return 0;
      }
    if (a->dir)
      if(verifica(a->dir)==0){
      return 0;
      }
    return 1;
}

int main() {

}
