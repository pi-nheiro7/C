#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

typedef struct no{
	int info;
	struct no *lig;
}tno;

typedef struct{
	tno *inicio;
	tno *fim;
}fila;

fila f;
fila f2;

void iniciar (fila *f){
	f->inicio = NULL;
	f->fim = NULL;
}

bool vazia (fila *f){
	return (f->inicio == NULL);
}

void inserir (fila *f, int dado){
	tno *aux;		
	aux = (tno *) malloc (sizeof(tno));
	
	if(aux == NULL){
		printf ("\nVAZIO!");
	}
	aux->info = dado;
	aux->lig = NULL;
	
	if (vazia(f)){
		f->inicio = aux;
	}else{
		f->fim->lig = aux;
	}
	f->fim = aux;
	printf ("\nSuccess!\n");
}

void exibir (fila *f){
	tno *aux;
	aux = f->inicio;
	
	if (vazia(f)){
		printf ("\nVazia!");
	}else{
		printf ("\nFila: ");
		while (aux != NULL){
			printf ("\n%d",aux->info);
			aux = aux->lig;
		}
		printf ("\n");
	}
}

void remover (fila *f){
	tno *aux;
	int info;
	
	if (vazia(f)){
		printf ("\nVazio!");
	}else{		
		aux = f->inicio;
		info = aux->info;
		f->inicio = aux->lig;
		
		if(f->inicio == NULL){
			f->fim = NULL;
		}
		free (aux);
		printf ("\nSuccess!");
	}	
}

void esvaziar (fila *f){
	tno *auxiliar;
	tno *guarda_valor;
	
	auxiliar = f->inicio;
	
	if (vazia(f)){
		printf ("\nVazio!");
	}else{
		while (auxiliar != NULL){
			guarda_valor = auxiliar;
			auxiliar = auxiliar->lig;
			free(guarda_valor);
		}
		f->inicio = NULL;
		f->fim = NULL;
		printf("\n");
	}
	printf ("\n");			
}

void media(fila *f){
	int quantidade = 0;
	float media;
	tno *auxiliar;
	
	auxiliar = f->inicio;
	
	if (vazia(f)){
		printf ("\nVazio!");
	}else{
		while (auxiliar != NULL){
			media = media + auxiliar->info;
			auxiliar = auxiliar->lig;
			quantidade++;			
		}
		media = media/quantidade;
		printf("\nA media eh: %0.2f\n",media);
	}		
}

void pares(fila *f){
	tno *auxiliar;
	int teste;
	
	auxiliar = f->inicio;
	
	if (vazia(f)){
		printf ("\nVazio!");
	}else{
		printf ("\nFila: ");
		while (auxiliar != NULL){
			if (auxiliar->info%2 == 0){
				printf ("\n%d",auxiliar->info);
			}
			auxiliar = auxiliar->lig;
			printf ("\n");
		}		
	}	
}

void quantas_vezes(fila *f){
	tno *auxiliar;
	int num,cont = 0;
	auxiliar = f->inicio;
	
	if (vazia(f)){
		printf ("\nVazio!\n");
	}else{
		printf("\nQual dado deseja consultar?\n");
		scanf("%d",&num);
		
		while(auxiliar != NULL){
			if(num == auxiliar->info){
				cont++;
			}
			auxiliar = auxiliar->lig;
		}
		printf("\nO numero %d aparece %d vezes.\n",num,cont);	
	}
}

void fila_espelho(fila *f, fila *f2){
	int n=0;
	int tam = 0,indice = 0;
	
	iniciar(&f2);
	tno *auxiliar;
	auxiliar = f->inicio;
	
	
	if (vazia(f)){
		printf ("\nVazio!\n");
	}else{
		while (auxiliar != NULL){
			tam++;
			auxiliar = auxiliar->lig;
		}
		int vetor[tam];
		auxiliar = f->inicio;
		while (auxiliar != NULL){
			vetor[indice] = auxiliar->info;
			auxiliar = auxiliar->lig;
			indice++;
		}	
		for(n = tam-1; n >= 0; n--){
        inserir(&f2, vetor[n]);
    	}
    	exibir(&f2);
		
	}
}


main(){
	setlocale(LC_ALL,"portuguese_Brazil");
	int dado;
	int escolha;
	
	iniciar (&f);
	escolha = menu();
	
	while (escolha != 0){
		switch(escolha){
			case 1:{
				printf ("\nDigite o numero que deseja inserir: ");
				scanf ("%d",&dado);
				inserir(&f,dado);
				break;
			}				
			case 2:{
				exibir(&f);
				break;
			}				
			case 3:{
				remover(&f);
				break;
			}
			case 4:{
				esvaziar(&f);
				break;
			}
			case 5:{
				media(&f);
				break;
			}
			case 6:{
				pares(&f);
				break;
			}
			case 7:{
				quantas_vezes(&f);
				break;
			}
			case 8:{
				fila_espelho(&f,&f2);
				break;
			}	
		}
		escolha = menu();		
	}

}

int menu(){
	int r;
	printf ("\n0 - SAIR");
	printf ("\n1 - INSERIR NO FINAL");
	printf ("\n2 - EXIBIR A FILA");
	printf ("\n3 - REMOVER DO INICIO");
	printf ("\n4 - ESVAZIAR A FILA");
	printf ("\n5 - MOSTRAR A MEDIA DA FILA");
	printf ("\n6 - MOSTRAR OS VALORES PARES DA FILA");
	printf ("\n7 - CONTAR QUANTAS VEZES 'X' APARECE NA FILA");
	printf ("\n8 - CRIAR UMA FILA F2 QUE RECEBE F AO CONTRARIO");
	printf ("\nESCOLHA: ");
	scanf ("%d",&r);
	
	return r;	
}
