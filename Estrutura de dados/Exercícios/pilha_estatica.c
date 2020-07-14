#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max 50


typedef struct{
  int chave;
} registro;

typedef struct{
  registro reg[max];
  int topo;
}pilha;

void iniciaPilha(pilha *p){
  p->topo = -1;
}

int tamanhoPilha(pilha *p){
  printf("Quantidade de elementos na pilha: %d\n", p->topo+1);
  return p->topo+1;
}

void mostrarElementos(pilha *p){
  if(p->topo == -1){
    printf("A pilha está vazia!\n");
  }else{
    int count;
    for(count = 0; count <= p->topo; count++){
      printf("[%d]", p->reg[count].chave, count);
    }
    printf("\n");
  }
}

bool inserirElemento(pilha *p){
  if(p->topo == max-1){
    printf("A pilha está cheia!!\n");
    return false;
  }else{
    registro valorAInserir;
    printf("Digite o número que você quer inserir: ");
    scanf("%d", &valorAInserir.chave);
    p->reg[p->topo + 1] = valorAInserir;
    p->topo++;
    printf("Inserido com sucesso!!\n");
  }
  return true;
}

bool excluirElemento(pilha *p){
  if(p->topo == -1){
    printf("A pilha está vazia!!\n");
    return false;
  }else{
    printf("Elemento deletado: %d", p->reg[p->topo].chave);
    printf("\n");
    p->topo--;
  }
  return true;
}

void reiniciarPilha(pilha *p){
  p->topo = -1;
}

int menu(){
  int r;
  printf("0 - Stop");
  printf("\n1 - Tamanho da pilha");
  printf("\n2 - Mostrar Elementos");
  printf("\n3 - Inserir Elemento");
  printf("\n4 - Excluir Elemento");
  printf("\n5 - Reiniciar Pilha.");
  printf("\nDigite sua opção: ");
  scanf("%d", &r);

  return r;
}

void main(){
  pilha p;

  iniciaPilha(&p);

  int r;

  r = menu();

  while (r != 0)
  {
    switch (r)
    {
    case 1:
    system("clear");
    tamanhoPilha(&p);
      break;
    case 2:
      system("clear");
      mostrarElementos(&p);
      break;
    case 3:
      system("clear");
      inserirElemento(&p);
      break;
    case 4:
      system("clear");
      excluirElemento(&p);
      break;
    case 5:
      system("clear");
      reiniciarPilha(&p);
      break;
    }
    r = menu();
  }
  

}
