#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int menu(){
	int r;
	printf ("\n0 - SAIR");
	printf ("\n1 - INSERIR");
	printf ("\n2 - EXIBIR LISTA");
	printf ("\n3 - CONTAR VALORES MAIORES QUE 'X'");
	printf ("\n4 - REMOVER");
	printf ("\n5 - MOSTRAR ENDERECO DE 'X' SALARIO");
	printf ("\n6 - CONTAR QUANTAS VEZES O SALARIO 'X' APARECE");
	printf ("\n7 - EZVAZIAR A LISTA");		
	printf ("\n8 - MAIOR E MENOR SALARIO");
	printf ("\n9 - ORDERNAR (DECRESCENTE)");
	printf ("\nEscolha sua opcao: ");
	scanf ("%d",&r);
	
	return r;
}

typedef struct no{
	float salario;
	struct no* prox;
}tno;

typedef tno* tlista;

void criar (tlista *L){
	*L = NULL;
}

tno* aloca(){
    tlista p;
    p = (tlista) malloc(sizeof(tno));
	return(p);
}

void inserir (tlista *L, float sal){
	tlista aux, novo;
	
	novo = aloca();
	if (novo == NULL){
		printf("\nVazio!\n");
	}else{
		novo->salario = sal;
		novo->prox = *L;
		*L = novo;
		printf("\nSucesso!\n");		
	}
}

void exibir(tlista L){
	tlista aux = L;	
	
	if(aux == NULL){
		printf ("\nVazio!\n");
	}else{
		printf("\nSalarios: \n");
		while (aux != NULL){
			printf("%0.2f\n",aux->salario);
			aux = aux->prox;
		}		
	}	
}

void maior(tlista L){
	float valor;
	int cont = 0;
	
	printf ("\nDigite qual valor deseja comparar: ");
	scanf ("%f",&valor);
	
	tlista aux = L;
	
	while(aux != NULL){
		if (aux->salario > valor){
			cont++;
		}
		aux = aux->prox;
	}
	printf("\nexitem %d valores maior que o digitado\n",cont,valor);
}

void remover (tlista *L){
	tlista deleta;
	
	if(*L == NULL){
		printf("\nVazio!\n");
	}else{
		deleta = *L;
		*L = deleta->prox;
		
		free(deleta);
		
		printf ("\nSucesso!\n");
	}	
}

void endereco_sal (tlista *L){
	float salario;
	tlista aux = *L;
	
	printf("\nQual salario deseja encontrar: ");
	scanf("%f",&salario);
	
	if(aux == NULL){
		printf("\nVazio!\n");
	}else{
		while(aux != NULL){
			if(aux->salario == salario){
				printf("\nEndereco: %p\n",&aux->salario);
				break;
			}
			aux->prox;
		}
	}	
}

void vezes_sal(tlista L){
	float sal;
	int cont = 0;
	
	tlista aux = L;
	
	printf("\nDigite qual salario deseja verificar: ");
	scanf ("%f",&sal);
	
	if(aux == NULL){
		printf("\nVazio!\n");
	}else{
		while (aux != NULL){
			if(aux->salario == sal){
				cont++;
			}
			aux = aux->prox;
		}
		printf ("\n%0.2f aparece %d vezes.\n",sal,cont);	
	}
}

void esvaziar(tlista *L){
	tlista deleta;
	
	if(*L == NULL){
		printf("\nVazio!\n");
	}else{
		while(*L != NULL){
			deleta = *L;
			*L = deleta->prox;
			free(deleta);
		}
		printf("\nSucesso!\n");
	}		
}

void maior_menor(tlista L){
	tlista aux = L;
	float maior = 0, menor = 0;
	int cont = 0;
	
	if(L == NULL){
		printf("\nVazio!\n");
	}else{
		while(aux != NULL){
			if (cont == 0){
				menor = aux->salario;
			}else if (menor > aux->salario){
				menor = aux->salario;				
			}
			
			if (maior < aux->salario){
				maior = aux->salario;
			}
			cont++;
			aux = aux->prox;
		}
		printf ("\nO maior e: %0.2f e o menor e: %0.2f\n",maior,menor);
	}	
}

void ordenar(tlista *L){
	tlista paux, p = *L;
	float aux;
	
	while(p != NULL){
		paux = p->prox;
		while(paux != NULL){
			if (p->salario < paux->salario){
				aux = p->salario;
				p->salario = paux->salario;
				paux->salario = aux;
			}
			paux = paux->prox;
		}		
		p = p->prox;
	}
	printf("\nSucesso!\n");	
}


main(){
	setlocale(LC_ALL,"portuguese_Brazil");
	int escolha;
	float sal;
	tlista l;
	
	criar(&l);
	
	escolha = menu();
	
	while (escolha != 0){
		switch (escolha){
			case 1:{
				printf ("\nDigite o salario que deseja inserir: ");
				scanf ("%f",&sal);
				inserir(&l,sal);
				break;
			}
			case 2:{
				exibir(l);
				break;
			}
			case 3:{
				maior(l);				
				break;
			}
			case 4:{
				remover(&l);
				break;
			}
			case 5:{
				endereco_sal(&l);
				break;
			}
			case 6:{
				vezes_sal(l);
				break;
			}	
			case 7:{
				esvaziar(&l);
				break;
			}	
			case 8:{
				maior_menor(l);
				break;
			}	
			case 9:{
				ordenar(&l);
				break;
			}		
		}
		escolha = menu();
	}
	
	return 0;
}

