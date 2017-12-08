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
	system("pause");
}

//2
void unPack (struct pilha *p){
	
	printf("\n*****|DESEMPILHANDO|*****");
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
	
	printf("\n*****|MOSTRAR PILHA|*****");
	
	if (p->topo == -1){
		printf ("\nERROR - NADA PARA MOSTRAR\n\n");
	}else {
		printf ("\n----*NOTA's*----");
		for (cont = 0; cont < x+1; cont++){			
			printf ("\n   %0.2f\n",p->nota[cont]);
		}		
	}
	printf ("\n\n");
	system("pause");
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
<<<<<<< HEAD:Estrutura de dados/Pilha/Atividade_Pilha_1.c.cpp
				printf ("\nNota n�o encontrada - INEXISTENTE\n");
=======
				printf ("\nNota não encontrada - INEXISTENTE\n");
>>>>>>> cb7cc10d4e64e23ba612a44d79c20b8dc7d75729:Estrutura de dados/Pilha/Atividade_Pilha_1.cpp
			}
	}
	printf ("\n\n");
	system("pause");
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
<<<<<<< HEAD:Estrutura de dados/Pilha/Atividade_Pilha_1.c.cpp
		printf ("\nQual n� deseja encontrar: ");
=======
		printf ("\nQual nó deseja encontrar: ");
>>>>>>> cb7cc10d4e64e23ba612a44d79c20b8dc7d75729:Estrutura de dados/Pilha/Atividade_Pilha_1.cpp
		scanf ("%d",&posicaoNo);
	
		while(posicaoNo > x){
			printf ("\nERROR - PROCURANDO NO FORA DOS LIMITES, TENTE NOVAMENTE: ");
			scanf ("%d",&posicaoNo);	
		}
		for (cont = 0; cont <x+1; cont++){
			if (posicaoNo == cont){
				aux = p->nota[cont];
			}
		}
<<<<<<< HEAD:Estrutura de dados/Pilha/Atividade_Pilha_1.c.cpp
		printf ("\nValor do %d� n� �: %0.2f\n\n ",posicaoNo,aux);
=======
		printf ("\nValor do %dº nó é: %0.2f\n\n ",posicaoNo,aux);
>>>>>>> cb7cc10d4e64e23ba612a44d79c20b8dc7d75729:Estrutura de dados/Pilha/Atividade_Pilha_1.cpp
		}
		printf ("\n\n");
		system("pause");
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
	system("pause");
}

//7
void topElement (struct pilha *p){
	
	float aux;
	printf("\n*****|ELEMENTO DO TOPO|*****");
	if (p->topo == -1){
		printf ("\nERROR - PILHA VAZIA\n");
	} else {
		aux = p->nota[p->topo];
		printf ("\nNota do topo: %0.2f\n\n", aux);
	}
	printf ("\n\n\n");	
	system("pause");	
}

//8
void ParElement (struct pilha *p){
	
	int soma;
	int cont, x = p->topo;
	float notasPar[5];
	
<<<<<<< HEAD:Estrutura de dados/Pilha/Atividade_Pilha_1.c.cpp
	printf("\n*****|ELEMENTOS NAS POSI��ES PARES|*****");
=======
	printf("\n*****|ELEMENTOS NAS POSIÇÕES PARES|*****");
>>>>>>> cb7cc10d4e64e23ba612a44d79c20b8dc7d75729:Estrutura de dados/Pilha/Atividade_Pilha_1.cpp
	if (p->topo == -1){
		printf ("\nERROR - PILHA VAZIA\n");
	}else{
		printf ("\n---*NOTAS DE NÓ PAR*---");
		for (cont = 0; cont < x+1; cont++){
			if (cont%2 == 0){
				printf ("\nNOTAS DO NÓ %dº: %0.2f ",cont, p->nota[cont]);
			}
		}
	}
	printf ("\n\n\n");
	system("pause");
}

//9
void order (struct pilha *p){
	
	float aux;
	int x,y;
	
	printf("\n*****|NOTAS EM ORDEM CRESCENTE|*****");
	
	if (p->topo == -1){
		printf ("\nERROR - PILHA VAZIA\n");
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
	printf ("\n");
	system("pause");
}


main (){
	
	setlocale(LC_ALL,"portuguese_Brazil");
	
	int escolha;
	struct pilha p;
	
	startpile (&p);
	escolha = menu();
	
	while (escolha > 9 || escolha < 0){
<<<<<<< HEAD:Estrutura de dados/Pilha/Atividade_Pilha_1.c.cpp
		printf ("\nOP��O INEXISTENTE, TENTE NOVAMENTE: ");
=======
		printf ("\nOPÇÃO INEXISTENTE, TENTE NOVAMENTE: ");
>>>>>>> cb7cc10d4e64e23ba612a44d79c20b8dc7d75729:Estrutura de dados/Pilha/Atividade_Pilha_1.cpp
		scanf ("%d",&escolha);
	}
	
	while (escolha != 0){
		if (escolha == 1){
			system ("cls");
			stackUp(&p);
			system ("cls");
		} 
		else if (escolha == 2){
			system ("cls");
			unPack(&p);	
			system ("cls");	
		} 
		else if (escolha == 3){
			system ("cls");
			showPile(&p);
			system ("cls");
		} 
		else if (escolha == 4){
			system ("cls");
			findElement(&p);
			system ("cls");
		} 
		else if (escolha == 5){
			system ("cls");
			findNode(&p);
			system ("cls");
		} 
		else if (escolha == 6){
			system ("cls");
			bigSmall(&p);
			system ("cls");
		} 
		else if (escolha == 7){
			system ("cls");
			topElement(&p);
			system ("cls");
		} 
		else if (escolha == 8){
			system ("cls");
			ParElement(&p);
<<<<<<< HEAD:Estrutura de dados/Pilha/Atividade_Pilha_1.c.cpp
			system("pause");
=======
>>>>>>> cb7cc10d4e64e23ba612a44d79c20b8dc7d75729:Estrutura de dados/Pilha/Atividade_Pilha_1.cpp
			system ("cls");
		} 
		else if (escolha == 9){
			system ("cls");
			order(&p);
			system ("cls");
		} 
		
		escolha = menu();
		
		while (escolha > 9 || escolha < 0){
<<<<<<< HEAD:Estrutura de dados/Pilha/Atividade_Pilha_1.c.cpp
			printf ("\nOP��O INEXISTENTE, TENTE NOVAMENTE: ");
=======
			printf ("\nOPÇÃO INEXISTENTE, TENTE NOVAMENTE: ");
>>>>>>> cb7cc10d4e64e23ba612a44d79c20b8dc7d75729:Estrutura de dados/Pilha/Atividade_Pilha_1.cpp
			scanf ("%d",&escolha);
		}
		
	}
	
}


