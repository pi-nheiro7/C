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
  printf("Tamanho: %d", tamanho);
  return tamanho;
  
}

int obterNo(lista *l){
  int resultado = l->dispo;
  if(l->dispo != -1){
    l->dispo = l->elem[l->dispo].IndiceProx;
  }
  return resultado;
}

bool inserir(lista *l){
  if(l->dispo == -1){
    printf("Lista está cheia...\n");
    return false;
  }
  elemento newElemento;
  newElemento.reg.chave = 5;

  int count = l->inicio;
  int chave = newElemento.reg.chave;
  int anterior = -1;
  while((count != -1) && (l->elem[count].reg.chave < chave)){
    anterior = count;
    count = l->elem[count].IndiceProx;
  }
  if((count != -1) && (l->elem[count].reg.chave == chave)){
    printf("Valor inválido!\n");
    return false;
  }
  int posicaoOk = obterNo(l);
  l->elem[posicaoOk] = newElemento;
  if (anterior == -1){
    l->elem[count].IndiceProx = l->inicio;
    l->inicio = count;
  }else{
    l->elem[count].IndiceProx = l->elem[anterior].IndiceProx;
    l->elem[anterior].IndiceProx = 1;
  }
  return true;  
}


void main(){
  lista l;

  iniciarLista(&l);
  inserir(&l);
  tamanhoLista(&l);

}
