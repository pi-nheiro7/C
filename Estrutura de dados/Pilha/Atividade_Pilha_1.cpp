#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tam 5

struct pilha {
	int topo;
	float nota[tam];
};


int menu (){
	int r;
	
	printf ("\n*-----*MENU*-----*");
	printf ("\n");
	printf ("0 – SAIR\n");
	printf ("1 – EMPILHAR\n");
	printf ("2 – DESEMPILHAR\n");
	printf ("3 – EXIBIR A PILHA\n");
	printf ("4 - LOCALIZAR NÓ ATRAVÉS DE UMA NOTA\n");
	printf ("5 - LOCALIZER NOTA ATRAVÉS DO NÓ\n");
	printf ("6 - MAIOR E MENOR NOTA\n");
	printf ("7 - MOSTRAR NOTA DO TOPO\n");
	printf ("8 - MOSTRAR NOTAS DE NÓS PARES\n");
	printf ("9 - ORDENAR PILHA DE FORMA CRESCENTE\n");
	printf ("ESCOLHA SUA OPÇÃO>  ");
	scanf ("%d",&r);
	return (r);	
}


//Inicia pilhar.
void startpile (struct pilha *p){ 
	p->topo = -1;
}

//1
void stackUp (struct pilha *p){
	
	printf ("\n*----EMPILHANDO----*\n");
	printf ("OBS: USE VÍGURLAS \",\" AO INVÉS DE PONTO\".\".\n");
	
	float n;
	if (p->topo == tam-1){
		printf ("\nERROR - PILHA CHEIA\n");
	} else {
		printf ("\nDigite uma nota: ");
		scanf ("%f",&n);
		
		p->topo++;
		p->nota[p->topo] = n;			
	}
	printf ("\n\n");
}

//2
void unPack (struct pilha *p){
	
	if (p->topo == -1){
		printf ("\nERROR - PILHA VAZIA\n\n");
	} else {
		p->topo--;
	}
}

//3
void showPile (struct pilha *p){
	
	int cont;
	int x = p->topo;
	
	printf("\n~~~~~~~MOSTRAR PILHA~~~~~~");
	
	if (p->topo == -1){
		printf ("\nERROR - NADA PARA MOSTRAR\n\n");
	}else {
		printf ("----*NOTA's*----");
		for (cont = 0; cont < x+1; cont++){			
			printf ("\n   %0.2f\n",p->nota[cont]);
		}		
	}
	printf ("\n");
}

//4
void findElement (struct pilha *p){
	
	int cont,aux=0;
	int x = p->topo;
	float auxNota;
	
	printf("\n*****|ENCONTRAR ELEMENTO PELA NOTA|*****");
	
	if (p->topo == -1){
		printf ("\nERROR - PILHA VAZIA\n\n");
	}else {
		printf ("\n\nDigite a nota que deseja encontrar: ");
		scanf ("%f",&auxNota);
	
	 	for (cont = 0; cont < x+1; cont++){
			if (auxNota == p->nota[cont]){
				printf ("\nPosição: %d\n",cont);
				} else {
					aux++;
				}		
			}
			if (aux > x){
				printf ("\nNota não encontrada - INEXISTENTE\n");
			}
	}
	printf ("\n\n");
}

//5
void findNode (struct pilha *p){
	
	int posicaoNo;
	int cont, x = p->topo;
	float aux;
	
	printf("\n*****|ENCONTRAR NOTA PELO NÓ|*****");
	
	if (x == -1){
		printf ("\nERROR - PILHA VAZIA\n\n");
	}else{
		printf ("Qual nó deseja encontrar: ");
		scanf ("%d",&posicaoNo);
	
		while(posicaoNo > x){
			printf ("ERROR - PROCURANDO NO FORA DOS LIMITES...");
			scanf ("\n%d\n\n",&posicaoNo);	
		}
		for (cont = 0; cont <x+1; cont++){
			if (posicaoNo == cont){
				aux = p->nota[cont];
			}
		}
		printf ("\nValor do %dº No é: %0.2f\n\n ",posicaoNo,aux);
		}
		printf ("\n\n");
}

//6
void bigSmall (struct pilha *p){
	
	float bigNo = p->nota[p->topo];
	float smallNo = p->nota[p->topo];
	int cont, x = p->topo;
	
	printf("\n*****|MAIOR E MENOR|*****");
	
	if ( x == -1){
		printf ("\nERROR - PILHA VAZIA\n\n");
	}else{
		for (cont = 0; cont <x; cont++){
			if (bigNo < p->nota[cont]){
				bigNo = p->nota[cont];
			} 
			else if (smallNo > p->nota[cont]){
				smallNo = p->nota[cont];	
			}		
		}
		printf ("\nMAIOR NOTA: %0.2f\n",bigNo);
		printf ("MENOR NOTA: %0.2f\n\n",smallNo);
	}
	printf ("\n\n");
}

//7
void topElement (struct pilha *p){
	
	float aux;
	printf("\n*****|ELEMENTO DO TOPO|*****\n");
	if (p->topo == -1){
		printf ("ERROR - PILHA VAZIA\n");
	} else {
		aux = p->nota[p->topo];
		printf ("\nNota do topo: %0.2f\n\n", aux);
	}
	printf ("\n\n");		
}

//8
void ParElement (struct pilha *p){
	
	int soma;
	int cont, x = p->topo;
	float notasPar[5];
	
	if (p->topo == -1){
		printf ("ERROR - PILHA VAZIA\n");
	}else{
		printf ("\n---*NOTAS DE NÓ PAR*---");
		for (cont = 0; cont < x+1; cont++){
			if (cont%2 == 0){
				printf ("\nNOTAS DO NÓ %dº: %0.2f ",cont, p->nota[cont]);
			}
		}
	}
	printf ("\n\n");
}

//9
void order (struct pilha *p){
	
	float aux;
	int x,y;
	
	printf("\n*****|NOTAS EM ORDEM CRESCENTE|*****");
	
	if (p->topo == -1){
		printf ("ERROR - PILHA VAZIA\n");
	}else{
		for (x = 0; x < p->topo+1; x++){
			for (y = 0; y < p->topo+1; y++){
				if (p->nota[y] > p->nota[x]){
					aux = p->nota[x];
					p->nota[x] = p->nota[y];
					p->nota[y] = aux;
				}
			}
		}
	
		printf ("\nNOTAS ORDENADAS: ");
		for (x = 0; x < p->topo+1; x++){
			printf ("\n%0.2f\n",p->nota[x]);
		}
	}
	printf ("\n\n");
}


main (){
	
	setlocale(LC_ALL,"portuguese_Brazil");
	
	int escolha;
	struct pilha p;
	
	startpile (&p);
	escolha = menu();
	
	while (escolha != 0){
		
		if (escolha == 1){
			system ("cls");
			stackUp(&p);
		} 
		else if (escolha == 2){
			system ("cls");
			unPack(&p);		
		} 
		else if (escolha == 3){
			system ("cls");
			showPile(&p);
			
		} 
		else if (escolha == 4){
			system ("cls");
			findElement(&p);
		} 
		else if (escolha == 5){
			system ("cls");
			findNode(&p);
		} 
		else if (escolha == 6){
			system ("cls");
			bigSmall(&p);
		} 
		else if (escolha == 7){
			system ("cls");
			topElement(&p);
		} 
		else if (escolha == 8){
			system ("cls");
			ParElement(&p);
		} 
		else if (escolha == 9){
			system ("cls");
			order(&p);
		} 
		
		escolha = menu();
		
	}
	
}


