#include <stdio.h>
#include <stdlib.h>

#define max 10

void imprimirVetor1(int vetor[]){
  for(int cont = 0; cont < max; cont++){
    printf("[%d] ", vetor[cont]);
  }
  printf("\n");
}

void imprimirVetor2(int *vetor[])
{
  for (int cont = 0; cont < max; cont++)
  {
    printf("[%d] ", *vetor[cont]);
  }
  printf("\n");
}

int main()
{
  int vetor[max];
  int *vetorP[max];
  // preenchendo o vetor com valores aleatórios;
  for (int cont = 0; cont < max; cont++)
  {
    int numRandom = rand() % 100;
    vetor[cont] = numRandom;
  }

  imprimirVetor1(vetor);
  //fazendo o segundo apontar pro primeiro;
  int aux;
  for(int cont1 = 0; cont1<max; cont1++){
    for(int cont2 = 0; cont2<max; cont2++){
      if(vetor[cont1] < vetor[cont2]){
        vetorP[cont1] = &vetor[cont2];
        
      } 
    }
  }

  // imprimirVetor1(vetor);

  imprimirVetor2(vetorP);

}