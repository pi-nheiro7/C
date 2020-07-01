#include <stdio.h>
#include <stdlib.h>
/*É uma função que chama ela mesma, esse programa resolve um fatorial...*/
main (){
	
	int fatorial (int x); //->assinatura da função.
	int numero, resultado;
	
	printf ("Digite um número inteiro: ");
	scanf ("%d",&numero);
	
	resultado = fatorial(numero);
	
	printf ("\nResultado da fatorial: %d",resultado);
}

int fatorial(int x){
	int resultado;
	
	if (x == 0){
		resultado = 1;
	} else {
		resultado = x * fatorial (x - 1);
	}
	
	return resultado;
	/*vale lembrar que fatorial funciona como se os resultados fossem ficando empilhados até que
		as condições sejam satisfeitas, é uma maneira elegante , muito "cara".
	*/
}

