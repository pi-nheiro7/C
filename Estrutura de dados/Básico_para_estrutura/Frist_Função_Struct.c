#include <stdio.h>
#include <stdlib.h>

//Passando e receber structs em uma função...

struct horario {
		int horas;
		int minutos;
		int segundos;
	}; //struct global.
	
	
main (){
	
	struct horario teste (struct horario x); //função struct e seu parametros.
	
	
	struct horario agora;	
	agora.horas = 10;
	agora.minutos = 27;
	agora.segundos = 30;
	
	
	struct horario proxima;
	proxima = teste(agora);/* teste(agora) manda para a função os valores do agora*/
	/*Enquanto a próxima vai receber os valores alterados :o*/
	
	printf ("\nMain: \n%d:%d:%d\n", proxima.horas, 
							proxima.minutos, 
							proxima.segundos); //eu to no main.
							//apareço depois pq tive que esperar alterar os valores da função struct.
	system ("pause");
	return 0;	
		
}

struct horario teste (struct horario x){
	
	printf ("\nFunção: \n%d:%d:%d \n",x.horas, 
							x.minutos, 
							x.segundos); //Aparece 1º pq fui jogado primeiro
	
	x.horas = 12;
	x.minutos = 30;
	x.segundos = 59;
	
	return x;
}
