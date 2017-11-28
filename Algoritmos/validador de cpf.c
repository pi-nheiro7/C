#include <stdio.h>
#include <stdlib.h>

main (){

	int divP,somaPD,pDigito,pd=10;  //primeiro digito
	int divS,somaSD,sDigito,sd=11; //segundo digito
	int ncpf[11]; //digitos convertidos para int
	char cpf[11]; //digitos printados em char

	printf ("Digite seu CPF: ");
	scanf ("%s",cpf);

	for (int cont=0;cont<11;cont++){
		ncpf[cont] = cpf[cont] - '0';

		if (pd>1){
			pDigito = ncpf[cont]*pd;
			somaPD+=pDigito;
			pd--;
		}
		if (sd>1){
			sDigito = ncpf[cont]*sd;
			somaSD+=sDigito;
			sd--;
		}
    }

    divP = (somaPD*10)%11;
    printf ("Primeiro Dígito: %d\n",divP);

    divS = (somaSD*10)%11;
    printf ("Segundo Dígito: %d\n",divS);


    if ((divP==ncpf[9]) && (divS==ncpf[10])) {
        printf ("\nVálido!");
    }
    else {
        printf ("\nInválido!");
    }


    system ("pause");

}


