#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no{
	int info;
	struct no *anterior;
}no;

typedef struct{
	no *topo;
}pilha;


int menu(){
	int r;
	
	printf (" 1- STACK UP");
	printf ("\n 2- UNPACK");
	printf ("\n 3- SHOW TOP ELEMENT");
	printf ("\n 4- SHOW PACK");
	printf ("\n 5- DRAIN OUT");
	printf ("\n 6- OUT");
	printf ("\n >CHOOSE YOUR OPTION: ");
	scanf ("%d",&r);
	
	return r;
}

pilha *start(pilha *p){	
	p = (pilha*) malloc (sizeof(pilha));
	p->topo = NULL;
	return p;	
}

no *stackup(pilha *p, int v){
	no *aux;
	aux = (no*) malloc(sizeof(no));
	aux->info = v;
	aux->anterior = p->topo;
	p->topo = aux;
	return aux;
}

bool empty (pilha *p){
	return (p->topo == NULL || p->topo->anterior == NULL);
}

void remove(pilha *p){
	int v;
	no *aux;
	
	if (empty(p)){
		printf ("\nPACK IS EMPTY\n");
	}else{
		v = p->topo->info;
		aux = p->topo;
		p->topo = aux->anterior;
		free(aux);
		printf ("\nTHE DATA REMOVED WAS: %d\n",v);
	}		
}

void showtop (pilha *p){
	
	if (empty(p)){
		printf ("\nPACK IS EMPTY\n");
	}else{
		printf("\nTHE TOP ELEMENT IS: %d\n",p->topo->info);
	}
	
}

void show (pilha *p){
	no *q = p->topo;
	
	if (empty(p)){
		printf ("\nPACK IS EMPTY\n");
	}else{
		printf("\n");
		while(q != NULL){		
			printf ("%d\n",q->info);
			q = q->anterior;
			if (q->anterior == NULL){
				break;
			}
		}
	}
}


void drainout (pilha *p){	
	no *aux = p->topo;
	
	if (empty(p)){
		printf ("\nPACK IS EMPTY\n");
	}else{
		while (aux != NULL){
			aux = p->topo->anterior;
			free (p->topo);
			p->topo = aux;			
		}
		free(p);
		printf("\nSuccess!!\n");
	}	
}

/*void order (pilha *p){
	int indice;
	int j,i,cont;
	int aux;
	
	aux = p->topo;
	
	
}*/

main(){
	setlocale(LC_ALL,"portuguese_Brazil");
	
	pilha p;
	int r,num;
	start(&p);
	
	r = menu();
	
	while ( r != 6){
		switch (r){
			case 1:
				printf ("\nInsert: ");
				scanf ("%d",&num);
				stackup(&p, num);
				printf("\n");
				break;
			case 2:
				remove(&p);
				printf("\n");
				break;
			case 3:
				showtop(&p);
				printf("\n");
				break;
			case 4:
				show(&p);
				printf("\n");
				break;
			case 5:
				drainout(&p);
				printf("\n");
				break;				
			}
		r = menu();					
	}
	
	return 0;
}

