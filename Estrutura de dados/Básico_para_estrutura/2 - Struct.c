#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
  typedef struct //typedef serve para definir um novo "tipo de variável".
  {
    int peso;
    float altura;
    char nome[30];
  } pessoa;

  pessoa junior;

  // junior.peso = 68;
  // junior.altura = 1.92;
  // junior.nome = "Junior Pinheiro"; infelizmente não é possível passar valor pra esse tipo de array assim.
  // strcpy(junior.nome, "Junior Pinheiro"); jeito certo de se passar um string pra array em struct.

  fflush(stdin); //fflush server para limpar o buffer, 'stdin' representa o teclado, no lugar poder ser um arquivo tbm, é o tipo da fonte.

  /*usarei o comando fgets() para ler strings, no caso
  fgets(variavel, tamanho da string, entrada)
  como estamos lendo do teclado a entrada é stdin (entrada padrão),
  porém em outro caso, a entrada tambem poderia ser um arquivo */
  printf("Por favor digite o seu nome: ");
  fgets(junior.nome, 20, stdin); //usando o fgets para ler string do teclado (var, tamanho do array, fonte(stdin = teclado));

  fflush(stdin);

  printf("Altura: ");
  scanf("%f", &junior.altura);

  fflush(stdin);

  printf("Peso: ");
  scanf("%d", &junior.peso);

  printf("\nNome: %sAltura: %0.2f\nPeso: %d\n", junior.nome, junior.altura, junior.peso);

}