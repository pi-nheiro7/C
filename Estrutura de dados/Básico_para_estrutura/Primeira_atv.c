#include <stdio.h>
#include <stdlib.h>
//define
#define pesomax 120;

typedef struct
{
  int peso;
  float altura;
} pessoa;

void implementar(pessoa *p);
void imprimir(pessoa *p);

void imprimir(pessoa *p){
  printf("\n----->imprimir<-----\n");

  printf("Seu peso é : %d", p->peso);
  printf("\nSua altura é: %0.2f\n", p->altura);
}

void implementar(pessoa *p)
{
  printf("\n----->Implementar<-----\n");

  printf("Por favor digite o seu peso: ");
  scanf("%d", &p->peso);

  printf("\nPor favor digite o sua altura: ");
  scanf("%f", &p->altura);
}


void main()
{
  pessoa *junior = (pessoa *)malloc(sizeof(pessoa));
  implementar(junior); //se eu passar com o '&', a função receberá o endereço do prório 'junior' e não o que 'junior está apontando';
  // implementar(junior); s eu pasar sem o '&' , a função receberá o endereço da função que está sendo apontada.
  imprimir(junior);
}