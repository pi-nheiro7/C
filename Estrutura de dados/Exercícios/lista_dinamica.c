#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
  int chave;
}registro;

typedef struct aux{
  registro reg;
  struct aux* prox;
}elemento, *pont;

typedef struct{
  pont inicio;
}lista;

void iniciar(lista *l){
  l->inicio = NULL;
}

int tamanho(lista *l){
  pont cont = l->inicio;
  int somadora;
  while(cont != NULL){
    somadora++;
    cont = cont->prox;
  }
  printf("Total: %d\n", somadora);
  return somadora;
}

void exibir(lista *l){
  pont cont = l->inicio;
  while(cont != NULL){
    printf("[%d]", cont->reg.chave);
    cont = cont->prox;
  }
  printf("\n");
}

int buscar(lista *l){
  pont cont = l->inicio;
  int valorBuscado;
  printf("Digite o valor que você quer encontrar: ");
  scanf("%d", &valorBuscado);
  while(cont != NULL && cont->reg.chave < valorBuscado){
    if(cont != NULL && cont->reg.chave == valorBuscado){
      printf("Valor encontrado.\n");
      return cont;
    }
  }
  return NULL;
}

pont buscaSequencialExc(lista *l, int chave, pont* ant){
  *ant = NULL;
  pont atual = l->inicio;
  while((atual != NULL) && (atual->reg.chave < chave)){
    *ant = atual;
    atual = atual->prox;
  }
  if((atual != NULL) && (atual->reg.chave == chave)){
    return atual;
  }
  return NULL;
}






// int menu()
// {
//   int r;
//   printf("0 - Stop");
//   printf("\n1 - Tamanho da Fila");
//   printf("\n2 - Mostrar Elementos");
//   printf("\n3 - Inserir Elemento");
//   printf("\n4 - Excluir Elemento");
//   printf("\n5 - Reiniciar Pilha.");
//   printf("\nDigite sua opção: ");
//   scanf("%d", &r);

//   return r;
// }

// void main()
// {
//   fila f;

//   iniciarFila(&f);

//   int r;

//   r = menu();

//   while (r != 0)
//   {
//     switch (r)
//     {
//     case 1:
//       system("clear");
//       tamanho(&f);
//       break;
//     case 2:
//       system("clear");
//       exibir(&f);
//       break;
//     case 3:
//       system("clear");
//       inserir(&f);
//       break;
//     case 4:
//       system("clear");
//       deletar(&f);
//       break;
//     case 5:
//       system("clear");
//       resetar(&f);
//       break;
//     }
//     r = menu();
//   }
// }
