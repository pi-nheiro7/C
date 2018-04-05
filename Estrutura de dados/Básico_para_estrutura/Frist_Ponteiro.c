#include <stdio.h>
#include <stdlib.h>

main (){
	
	int variavel = 250; 
	int *ponteiro;
	int exibir;
	
	
	ponteiro = &variavel; //Passando o edenreço de memória da variavel pro ponteiro;
	exibir = *ponteiro; //Passando o contéudo do *ponteiro para a variável exibir;
	
	printf ("\n%d - %p\n",exibir,ponteiro); //%p serve para mostrar o endereço da memoria :D
	
	
}
