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
  f->
}
