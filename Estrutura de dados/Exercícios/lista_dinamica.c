#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
  int chave;
} registro;

typedef struct aux
{
  registro reg;
  struct aux *prox;
} elemento, *pont;

typedef struct
{
  pont inicio;
} lista;

void iniciar(lista *l)
{
  l->inicio = NULL;
}

int tamanho(lista *l)
{
  pont cont = l->inicio;
  int somadora = 0;
  while (cont != NULL)
  {
    somadora++;
    cont = cont->prox;
  }
  printf("Total: %d\n", somadora);
  return somadora;
}

void exibir(lista *l)
{
  pont cont = l->inicio;
  while (cont != NULL)
  {
    printf("[%d]", cont->reg.chave);
    cont = cont->prox;
  }
  printf("\n");
}

int buscar(lista *l)
{
  pont cont = l->inicio;
  int valorBuscado;
  printf("Digite o valor que você quer encontrar: ");
  scanf("%d", &valorBuscado);
  while (cont != NULL && cont->reg.chave < valorBuscado)
  {
    if (cont != NULL && cont->reg.chave == valorBuscado)
    {
      printf("Valor encontrado.\n");
      return cont;
    }
  }
  return NULL;
}

pont buscaSequencialExc(lista *l, int chave, pont *ant)
{
  *ant = NULL;
  pont atual = l->inicio;
  while ((atual != NULL) && (atual->reg.chave < chave))
  {
    *ant = atual;
    atual = atual->prox;
  }
  if (atual != NULL && atual->reg.chave == chave)
  {
    return atual;
  }
  return NULL;
}

bool inserir(lista *l)
{
  int newChave;
  printf("Digite o novo valor a ser inserido: ");
  scanf("%d", &newChave);
  pont ant = NULL;
  pont i = buscaSequencialExc(l, newChave, &ant);
  if (i != NULL)
  {
    printf("Não é permetido valores repetidos...\n");
    return false;
  }
  i = (pont)malloc(sizeof(elemento));
  i->reg.chave = newChave;
  if (ant == NULL)
  {
    i->prox = l->inicio;
    l->inicio = i;
  }
  else
  {
    i->prox = ant->prox;
    ant->prox = i;
  }
  return true;
}

bool deletar(lista *l)
{
  exibir(l);
  int valorDeletado;
  printf("\nQual chave você quer deletar: ");
  scanf("%d", &valorDeletado);
  pont ant;
  pont atual = buscaSequencialExc(l, valorDeletado, &ant);
  if (atual == NULL)
  {
    printf("Lista Vazia\n");
    return false;
  }
  if (ant == NULL)
  {
    l->inicio = atual->prox;
  }
  else
  {
    ant->prox = atual->prox;
  }
  free(atual);
  return true;
}

void resetar(lista *l)
{
  pont cont = l->inicio;
  while (cont != NULL)
  {
    pont apagar = cont;
    cont = cont->prox;
    free(apagar);
  }
  l->inicio = NULL;
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
  lista f;

  iniciar(&f);

  int r;

  r = menu();

  while (r != 0)
  {
    switch (r)
    {
    case 1:
      system("clear");
      tamanho(&f);
      break;
    case 2:
      system("clear");
      exibir(&f);
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
      resetar(&f);
      break;
    }
    r = menu();
  }
}
