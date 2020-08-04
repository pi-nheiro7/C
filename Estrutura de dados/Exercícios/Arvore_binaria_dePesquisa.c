#include <stdio.h>
#include <stdlib.h>

typedef struct aux{
  int chave;
  struct aux* esq, dir;
}no, *pont;

pont inicializar(){
  return NULL;
}

pont criarNovoNo(int ch){
  pont no = (pont) malloc(sizeof(no));
  no->chave = ch;
  no->esq = NULL;
  no->dir = NULL;
  return no;
}

pont insercao(pont raiz, pont no){
  if(raiz == NULL){
    return no;
  }
  if(no->chave < raiz->chave){
    raiz->esq = insercao(raiz->esq, no);
  }else if(no->chave > raiz->chave){
    raiz->dir = insercao(raiz->dir, no);
  }
  return raiz;
}

void main(){
  pont r = inicializar();
  int newValue;
  printf("Digite o novo Nó a ser inserido: ");
  scanf("%d", &newValue);
  pont no = criarNovoNo(newValue);
  r = insercao(r, no);
}