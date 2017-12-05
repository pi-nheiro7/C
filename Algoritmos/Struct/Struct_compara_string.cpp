#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct cadastro{
	char nome[10];
	int endereco;
	int telefone;
};

int main(){	
	setlocale(LC_ALL, "Portuguese");
	  
	cadastro clientes[2];
	int i,j=1;
	char n[10];
	
	while (j!=0){
		system ("cls");
		
		printf ("1 - CADASTRAR\n2 - CONSULTAR CLIENTE\nDIGITE SUA OPÇÃO:  ");
		scanf ("%d", &j);
	
		if (j==1){

		for (i=0;i<2;i++){
			printf ("\nDigite o nome do cliente:  ");
			scanf("%s", clientes[i].nome);
			
			printf ("\nDigite o endereco: ");
			scanf ("%d", &clientes[i].endereco);
			
			printf ("\nDigite o telefone: ");
			scanf ("%d", &clientes[i].telefone);
			
			system("cls");
			}
		}
		else{
			printf ("\nDigite o nome que deseja consultar: ");
			scanf ("%s", n);
			
		for (i=0;i<2;i++){
			if (strcmp (n, clientes[i].nome) == 0){
				printf ("\nEndereço: %d e Telefone: %d", clientes[i].endereco, clientes[i].telefone);
				}
			}
		}
		
	printf ("\n\n0 - PARA SAIR\n1 - PARA CONTINUAR\nDIGITE SUA OPÇÃO: ");
	scanf("%d", &j);
	}
	return 0;
}
