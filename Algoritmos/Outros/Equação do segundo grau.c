#include <stdio.h>
#include <math.h>

main (){
	float a,b,c,x1,x2,x,delta; 
		
	printf ("\t\t EQUAÇAO DO SEGUNDO GRAU \t\t\n\n");
	
	printf ("Escreva o valor de A: ");
	scanf ("%f",&a);
	
	printf ("Escreva o valor de B: ");
	scanf ("%f",&b);
	
	printf ("Escreva o valor de C: ");
	scanf ("%f",&c);
	
	delta= (pow(b,2)-4*a*c);
	printf ("Delta: %0.1f\n",delta);
	
	if (delta > 0){
		x1= (-b+(sqrt(delta)))/(2*a);
		printf ("\nX1: %0.1f", x1); 
		
		x2= (-b-(sqrt(delta)))/(2*a);
		printf ("\nX2: %0.1f", x2);
	}
	else if (delta == 0){
		x=((-b+0)/(2*a));
		printf ("\nX: %0.1f", x);
	}
	else if (delta < 0){
		printf ("\nEssa equecao nao e valida");
	}
	
	return 0;	
	
	
}
