#include <stdio.h>
#include <stdlib.h>
/*
  OPERADORES:
  & = ENDEREÇO em si;
  * = VALOR CONTIDO NO ENDEREÇO Em QUESTÃO;
  %p = é utilizado para imprimir valores de endereço dos ponteiros.
*/

void main()
{
  int *ponteiro;
  int numero;

  numero = 10;
  ponteiro = &numero; //CUIDADO AO PASSAR VALOR DA VARIÁVEL, SE DEVE PASSAR SEM O '*', POIS ELE PEGARÁ APENAS O VALOR DO ENDEREÇO.

  printf("Valor da var numero: %d", numero);
  printf("\nEndereço da var numero: %x", &numero);

  printf("\nO valor do ponteiro: %d", *ponteiro);
  // printf("\nO valor do ponteiro: %d", ponteiro); OBS: PARA IMPRIMIR O VALOR DO PONTEIRO É PRECISO DO '*' OU ELE IRÁ BUSCAR PELO ENDEREÇO.

  printf("\nO endereço de memória do ponteiro: %p\n", ponteiro);

  // OBS: quando a var vem COM '*' significa q ele ta usando o valor apontado e não o endereço, pra usar o endereço tme que ser SEM o '*'

  *ponteiro = *ponteiro + 11; //atualizar o valor pelo ponteiro tbm atualiza o valor da variável que está sendo apontada.
  printf("\nO valor novo do ponteiro: %d", *ponteiro);
  printf("\nValor novo da var numero: %d\n", numero);
}