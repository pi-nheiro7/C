#include <stdio.h>
#include <stdlib.h>
// isso aqui é daora, passar struct por referência;
//ISSO POSSIBLITA RETORNAR VÁRIOS VALORES DE UMA FUNCTION;

struct ponto
{
  int x,y,z;
};

void atribui(struct ponto *p){ //precisa definir "struct tipo *nome"
  (*p).x = 10; // p->x = 10 é a mesma coisa
  p->y = 10; // (*p).y = 10 é a mesma coisa;
  (*p).z = (*p).x + (*p).y;
  // É IMPORTANTE USAR O () NO *p POIS VC ESTÁ PASSANDO A STRUCT TODA POR REFERÊNCIA E NÃO UM ATRIBUTO DELA, SE NÃO USAR O COMPILADOR FICARÁ CONFUSO .
  // E PENSARÁ QUE É PARA USAR *(p.y) AO INVÉS DE (*p).y;
  /*
    PODEMOS USAR O OPERADOR SETA "->" PARA ACESSAR ALGUM CAMPO DE UMA ESTRUTURA PASSADA POR REFERÊNCIA.
  */
}


void main(){
  struct ponto p1;
  atribui(&p1); //IMPORTANE PASSSAR COM & POR É POR REFERÊNCIA.
  printf("valor de x: %d\n", p1.x);
  printf("valor de y: %d\n", p1.y);
  printf("valor de z: %d\n", p1.z);
}