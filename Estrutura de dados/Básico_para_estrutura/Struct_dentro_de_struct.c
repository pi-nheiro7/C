#include <stdio.h>
#include <stdlib.h>
//criando struct dentro de uma struct com vetor :o
#define max 50

typedef struct{
  int chave;
} registro;

typedef struct{
  registro a[max];
  int ElementPosition;
} lista;

void main(){
  lista l;
  l.a[0].chave = 20;

  printf("O valor da struct dentro da struct é: %d\n", l.a[0].chave);
}

