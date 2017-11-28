#include <stdio.h>
#include <stdlib.h>

main(){
	
	int *p = (int *) malloc(sizeof(int)); //Malloc == Memory Allocation.
	/*(int *) é um casting, ele força a mudar a memória de void para int... */
	// pois quando vc resorvou memória com o malloc ela era uam memoria vazia.
	//e seu ponteiro é um int...
	
	*p = 1000;
	
	//free(p);
	
	printf ("\n%d\n",*p);
	
	free (p); /*Vai devolver a memória alocada para o S.O.*/ 
	/*Mas os valores colocados continuam...(No exemplo acimao 1000 continua lá...)*/
	
	int *m = (int *) malloc(sizeof(int)); //o *M pode receber o valor 1000 lá de cima...
	// mas não é 100% certeza, já que vc não indicou nenhum endereço, apenas alocou memória.
	
}
