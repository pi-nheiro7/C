#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max 2

typedef struct{
  int chave;
}registro;

typedef struct{
  registro reg[max];
  int topo1;
  int topo2;
} pilhadupla;

void iniciar(pilhadupla *p){
  p->topo1 = -1;
  p->topo2 = max;
}

int tamanho(pilhadupla *p){
  int tamanho = (p->topo1+1) + (max - p->topo2);
  printf("Tamanho: %d\n", tamanho);
  return tamanho;
}

bool exibir(pilhadupla *p){
  int pilha;
  printf("Digite qual pilha você quer ver(escolah entre 1 ou 2): ");
  scanf("%d", &pilha);
  if(pilha < 1 || pilha > 2){
    printf("Opção inválida.");
    return false;
  }
  if(pilha == 1){
    int count;
    for(count = p->topo1; count >= 0; count--){
      printf("[%d]", p->reg[count].chave);
    }
  }else{
    int count;
    for(count = p->topo2; count < max; count++){
      printf("[%d]", p->reg[count].chave);
    }
  }
  printf("\n");
  return true;
}

bool inserir(pilhadupla *p){
  int pilha;
  printf("Digite qual pilha você quer inserir(escolah entre 1 ou 2): ");
  scanf("%d", &pilha);
  if (pilha < 1 || pilha > 2)
  {
    printf("Opção inválida.\n");
    return false;
  }
  if(p->topo1+1 == p->topo2){
    printf("Pilha cheia.\n");
    return false;
  }
  registro newReg;
  printf("Digite qual valor da chave você quer inserir: ");
  scanf("%d", &newReg.chave);

  if(pilha == 1){
    p->topo1++;
    p->reg[p->topo1] = newReg;
  }else{
    p->topo2--;
    p->reg[p->topo2] = newReg;
  }
  printf("Inserido com sucesso!!\n");
  return true;
}

bool deletar(pilhadupla *p){
  int pilha;
  printf("Digite qual pilha você quer deletar(escolah entre 1 ou 2): ");
  scanf("%d", &pilha);
  if (pilha < 1 || pilha > 2)
  {
    printf("Opção inválida.");
    return false;
  }
  if(pilha == 1){
    if (p->topo1 == -1){
      printf("Pilha 1 está vazia...\n");
      return false;
    }else{
      p->topo1--;
    }
  }else{
    if(p->topo2 == max){
      printf("A pilha 2 está vazia...\n");
      return false;
    }else{
      p->topo2++;
    }
  }
  printf("Deletado com sucesso!\n");
  return true;
}


void reset(pilhadupla *p){
  p->topo1 = -1;
  p->topo2 = max;
}



int menu()
{
  int r;
  printf("0 - Stop");
  printf("\n1 - Tamanho");
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
  pilhadupla p;

  iniciar(&p);

  int r;

  r = menu();

  while (r != 0)
  {
    switch (r)
    {
    case 1:
      system("clear");
      tamanho(&p);
      break;
    case 2:
      system("clear");
      exibir(&p);
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
      reset(&p);
      break;
    }
    r = menu();
  }
}
