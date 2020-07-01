#include <stdio.h>
#include <stdlib.h>
/*
	%li - é utilizando para imprimir o valor do sizeof() no printf.
*/

void main(){
	// sizeof() calcula o valor de qualquer tipo de variável ou qualquer coisa;
 //exemplos abaixo;
	float *ponteiro;
	char nome[10];
	char sobrenome[30];

	printf("%li\n", sizeof(void)); // :D
	printf("%li\n", sizeof(nome));
	printf("%li\n", sizeof(sobrenome));
	printf("%li\n", sizeof(ponteiro)); //olha a diferença, aqui ele mostra o custo por ser um ponteiro.
	printf("%li\n", sizeof(*ponteiro)); //aqui ele mostra o custo do VALOR/TIPO em questão, que no caso é float.
}