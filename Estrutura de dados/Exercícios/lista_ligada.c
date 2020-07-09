#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max 30


typedef struct{
  int chave;
} registro;

typedef struct{
  registro reg;
  int IndiceProx; //isso básicamente indica o indice do próximo elemento;
} elemento;

typedef struct{
  elemento elem[max];
  int inicio; //Posição/indice de onde está o primeiro elemento disponivel.
  int dispo; //Diz onde está o indice do primeiro espaço disponivel para uso.
}lista;



void iniciarLista(lista *l){
  int count;
  while(count < max-1){
    l->elem[count].IndiceProx = count+1;
  }
  l->elem[max-1].IndiceProx = -1;
  l->inicio = -1;
  l->dispo = 0; // 0 é a primeira posição disponivel, isso quer dizer que toda lista está disponivel.
}

int tamanhoLista(lista *l){
  int count = l->inicio;
  int tamanho = 0;

  while(count != -1){
    count = l->elem[count+1].IndiceProx;
    tamanho++;
  }
  return tamanho;
  
}

int obterNo(lista *l){
  int resultado = l->dispo;
  if(l->dispo != -1){
    l->dispo = l->elem[l->dispo].IndiceProx;
  }
  return resultado;
}
