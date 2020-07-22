#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  int chave;
}registro;

typedef struct aux{
  registro reg;
  struct aux *prox;
}elemento, *pont;

typedef struct{
  pont inicio;
  pont fim;
}fila;


void iniciarFila(fila *f)
{
  f->inicio = NULL;
  f->fim = NULL;
}

int tamanhoFila(fila *f)
{
  int somadora = 0;
  pont elemento = f->inicio;
  while(elemento != NULL){
    somadora++;
    elemento = elemento->prox;
  }
  printf("O tamanho da fila é: %d\n", somadora);
  return somadora;
}

void exibirFila(fila *f)
{
  pont elemento = f->inicio;
  while (elemento != NULL){
    printf("[%d]", elemento->reg.chave);
    elemento = elemento->prox;
  }
  printf("\n");
}

bool inserir(fila *f)
{
  pont novo = (pont) malloc(sizeof(elemento));
  novo->prox = NULL;
  int newValor;
  printf("Digite o valor que você quer inserir: ");
  scanf("%d", &newValor);
  novo->reg.chave = newValor;
  if(f->inicio == NULL){
    f->inicio = novo;
  }else{
    f->fim->prox = novo;
  }
  f->fim = novo;
  return true;
}

bool deletar(fila *f)
{
  pont deletado = f->inicio;
  printf("O valor da chave deletada foi: %d\n", deletado->reg.chave);
  f->inicio = f->inicio->prox;
  if(f->inicio == NULL){
    f->fim = NULL;
  }
  free(deletado);
  return true;
}

void resetFila(fila *f)
{
  pont elemento = f->inicio;
  pont apagar;
  while (elemento != NULL){
    apagar = elemento;
    elemento = elemento->prox;
    free(apagar);
  }
  f->inicio = NULL;
  f->inicio = NULL;
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
