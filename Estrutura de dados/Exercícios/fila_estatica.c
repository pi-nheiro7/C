#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max 10

typedef struct{
  int chave;
} registro;

typedef struct{
  registro reg[max];
  int inicio;
  int NroElem;
} fila;

void iniciarFila(fila *f){
  f->inicio = 0;
  f->NroElem = 0;
}

int tamanhoFila(fila *f){
  printf("Números de elementos: %d\n", f->NroElem);
  return f->NroElem;
}

void exibirFila(fila *f){
  if(f->NroElem == 0){
    printf("A fila está vazia!!\n");
  }else{
    int i = f->inicio;
    int count;
    printf("Elementos: ");
    for(count = 0; count < f->NroElem; count++){
      printf("[%d]", f->reg[i].chave);
      i = (i+1) % max;
    }
    printf("\n");
  }
}

bool inserir(fila *f){
  if(f->NroElem >= max){
    printf("A fila está cheia!!");
    return false;
  }
  registro newValor;
  printf("Digite o valor que deseja inserir: ");
  scanf("%d", &newValor.chave);
  int posicao = (f->inicio + f->NroElem) % max;
  f->reg[posicao] = newValor;
  f->NroElem++;
  printf("Valor inserido com sucesso!\n");
  return true;
}

bool deletar(fila *f){
  if(f->NroElem == 0){
    printf("A pilha está vazia!\n");
    return false;
  }
  f->inicio = (f->inicio+1)%max;
  f->NroElem--;
  return true;
}

void resetFila(fila *f){
  f->inicio = 0;
  f->NroElem = 0;
}

int menu()
{
  int r;
  printf("0 - Stop");
  printf("\n1 - Tamanho da Fila");
  printf("\n2 - Mostrar Elementos");
  printf("\n3 - Inserir Elemento");
  printf("\n4 - Excluir Elemento");
  printf("\n5 - Reiniciar Pilha.");
  printf("\nDigite sua opção: ");
  scanf("%d", &r);

  return r;
}

void main()
{
  fila f;

  iniciarFila(&f);

  int r;

  r = menu();

  while (r != 0)
  {
    switch (r)
    {
    case 1:
      system("clear");
      tamanhoFila(&f);
      break;
    case 2:
      system("clear");
      exibirFila(&f);
      break;
    case 3:
      system("clear");
      inserir(&f);
      break;
    case 4:
      system("clear");
      deletar(&f);
      break;
    case 5:
      system("clear");
      resetFila(&f);
      break;
    }
    r = menu();
  }
}
