#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
  int chave;
}registro;

typedef struct aux{
  registro reg;
  struct aux* prox;
}elemento;

typedef struct {
  elemento *topo;
}pilha;


void iniciaPilha(pilha *p){
  p->topo = NULL;
}

int tamanhoPilha(pilha *p){
  elemento *end = p->topo;
  int tamanho = 0;
  while(end != NULL){
    tamanho++;
    end = end->prox;
  }
  printf("Tamanho: %d\n", tamanho);
  return tamanho;
}

void exibirPilha(pilha *p){
  if(p->topo == NULL){
    printf("A pilha está vazia!\n");
  }else{
    elemento *elemento = p->topo;
    printf("Elementos: ");
    while (elemento != NULL)
    {
      printf("[%d]", elemento->reg.chave);
      elemento = elemento->prox;
    }
    printf("\n");
  }
}

bool inserir(pilha *p){
  elemento *novo = (elemento *) malloc(sizeof(elemento));
  int valor;
  printf("Digite o valor da chave que você quer inserir: ");
  scanf("%d", &valor);
  novo->reg.chave = valor;
  novo->prox = p->topo;
  p->topo = novo;
  return true;
}

bool deletar(pilha *p){
  if(p->topo == NULL){
    printf("A pilha está vazia!\n");
    return false;
  }
  printf("Elemento deletado foi: %d",p->topo->reg.chave);
  elemento* deletado = p->topo;
  p->topo = p->topo->prox;
  free(deletado);
  return true;
}

void reiniciar(pilha *p){
  elemento *apagar;
  elemento *posicao = p->topo;
  while (posicao != NULL)
  {
    apagar = posicao;
    posicao = posicao->prox;
    free(apagar);
  }
  p->topo = NULL;
}

int menu()
{
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

void main()
{
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
      exibirPilha(&p);
      break;
    case 3:
      system("clear");
      inserir(&p);
      break;
    case 4:
      system("clear");
      deletar(&p);
      break;
    case 5:
      system("clear");
      reiniciar(&p);
      break;
    }
    r = menu();
  }
}
