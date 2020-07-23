#include <stdio.h>
#include <stdlib.h>


void main(){
  int x = 10;
  int *p = &x;
  int **pp = &p;

  printf("Valor de PP: %d", pp);
  //Que é o mesmo que &p, é o que ele guarda;
  printf("\nValor de *PP: %d", *pp);
  //Que é o mesmo que &x, pois é o valor que *p carrega, logo *pp == p;
  printf("\nValor de **PP: %d\n", **pp);
  //Que é o mesmo que x, logo **pp == *p;

  // não existe limite pra nivéis de ponteiro. voce poderia ter 50 ponteiros de ponteiros de ponteiros...

}