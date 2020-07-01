#include <stdio.h>
#include <stdlib.h>

void main()
{
	int *numero = (int *)malloc(sizeof(int));
	// aloque o espaço de um 'int', faça o casting para um valor int e guarde dentro de um ponteiro '*numero';

	*numero = 1000;

	printf("\nvalor do conteúdo do ponteiro: %d\n", *numero);
	printf("Endereço que está sendo apontado: %p\n", numero);
	printf("Endereço do próprio ponteiro: %p\n", &numero);

	free(numero); //Avisa ao S.O. que este endereço está livre para a reciclagem;

}