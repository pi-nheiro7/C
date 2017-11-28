#include <stdio.h>
#include <stdlib.h>

main(){
	/*Como usar ponteiro em Struct.*/
	struct horario{
		int hora;
		int minutos;
		int segundos;
	};
	
	struct horario agora, *depois;
	
	depois = &agora;
		
	
	depois->hora = 1; 
	depois->minutos = 10; 
	depois->segundos = 50; 
	
	int soma = 100;
	
	struct horario antes;
	antes.hora = soma + depois->segundos;
	antes.minutos = agora.hora - depois->minutos;
	antes.segundos = depois->minutos + depois->segundos; 
	
	printf ("%d:%d:%d\n", antes.hora, antes.minutos, antes.segundos);
	
}
