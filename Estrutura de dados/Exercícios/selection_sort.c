#include <stdio.h>
#include <stdlib.h>

#define max 10

void main()
{
  int vetor[10] = {5, 9, 4, 1, 2, 0, 8, 7, 3, 6};
  int menor, count1, count2;
  menor = vetor[0];
  int posicao = 0;
  int valor;
  for (count1 = 0; count1 < max; count1++)
  {
    for(count2 = count1; count2 < max; count2++){
      if (menor > vetor[count2])
      {
        menor = vetor[count2];
        posicao = count2;
        
      }
    }
    vetor[count1] = menor;
  }

  printf("%d - %d\n", menor, posicao);

  for (int cont = 0; cont < max; cont++)
  {
    printf("[%d] ", vetor[cont]);
  }
  printf("\n");
}