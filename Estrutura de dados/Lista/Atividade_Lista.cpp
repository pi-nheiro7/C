#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tam 5

typedef struct{
	int posicao;
	int mat[tam];
	int nota[tam];
}aprovados;


typedef struct {
	int n;
	int mat[tam];
	float nota[tam];
}lista;



int menu (){
	int r;
	
	printf ("\n0 - SAIR");
	printf ("\n1 - INSERIR NOTA NO FINAL");
	printf ("\n2 - MOSTRAR NÚMERO DE ELEMENTOS NA LISTA");
	printf ("\n3 - LOCALIZAR NOTA UTILIZANDO A MATRICULA");
	printf ("\n4 - MOSTRAR NOTA DE UMA DETERMINADA POSIÇÃO");
	printf ("\n5 - EXCLUIR UMA POSIÇÃO DA LISTA");
	printf ("\n6 - MOSTRAR A MAIOR NOTA E A MATRICULA DO ALUNO");
	printf ("\n7 - INSERIR UM NOVO ELEMENTO APÓS O ÚLTIMO INSERIDO");
	printf ("\n8 - ORDERNAR A LISTA");
	printf ("\n9 - SUBLISTA SOMENTE COM ALUNOS APROVADOS");
	printf ("\n10 - MOSTRAR TODOS ELEMENTOS DA LISTA");
	printf ("\nESCOLHA SUA OPÇÃO:  ");
	scanf ("%d",&r);
	
	return r;
}


void inicialista (lista *l, aprovados *ap){ 
	l->n = 0;
	ap->posicao = 0;
}


void inserirfinal (lista *l){ //1
	
	if (l->n > tam-1){
		printf ("\nERROR - LISTA CHEIA\n");
	}else{
		printf ("Insira a matrícula: ");
		scanf ("%d",&l->mat[l->n]);
		
		printf ("Insera a nota: ");
		scanf ("%f",&l->nota[l->n]);
		
		l->n++;	
	}
	system ("pause");
}


void numeronos (lista *l){ //2
	printf ("\nNumero de elementos: %d\n", l->n);
	system ("pause");
}


void localizarpormatricula (lista *l){ //3
	int matricula;
	int cont;
	
	printf ("\nDigite a matricula que deseja consular: ");
	scanf ("%d",&matricula);
	
	for (cont = 0; cont < l->n; cont++){
		if (matricula == l->mat[cont]){
			printf ("Matricula: %d\n",l->mat[cont]);
			printf ("Nota: %0.1f\n",l->nota[cont]);
			printf ("Posição na lista: %d\n",l->n);
		}
	}	
	system ("pause");
}


void mostrarvalorno (lista *l){ //4
	int posicao;
	
	printf ("\nDigite a posição: ");
	scanf ("%d",&posicao);
	
	printf ("\nMatrícula: %d",l->mat[posicao-1]);
	printf ("\nNota: %0.1f\n",l->nota[posicao-1]);
	system ("pause");
}


void removerposicao (lista *l){ //5
	int auxMa, auxNota;
	int remover;
	
	while (remover > tam-1){
		printf ("\nDigite a posição que deseja remover: ");
		scanf ("%d",&remover);
		
		if (remover > tam-1){
			printf ("\nERRO - OPÇÃO NÃO EXISTENTE\n");
		}else {
			remover--;
			
			auxMa = l->mat[remover];
			auxNota = l->nota[remover];
			
			l->mat[remover+1] = l->mat[remover];
			l->nota[remover+1] = l->nota[remover];
			
			l->mat[l->n] = auxMa;
			l->nota[l->n] = auxNota;
			
			l->n--;
		}
	}
	system ("pause");
}


void maiornota (lista *l){ //6
	int cont;
	float auxNota = 0, auxMa = 0;
	
	for (cont = 0; cont < l->n; cont++){
		if (l->nota[cont] > auxNota){
			auxNota = l->nota[cont];
			auxMa = l->mat[cont];
		}
	}
	printf ("Maior nota é %0.1f da matrícula %d\n",auxNota,auxMa);
	system ("pause");
}


void inserirnota (lista *l){ //7
	int posicao;
	int cont;
	
	printf ("\nEm qual posição deseja adicionar um elemento? ");
	scanf ("%d",&posicao);
	
	if (posicao > tam-1){
		printf ("\nERROR - OPÇÃO INVÁLIDA\n");
	}else{
		
		l->n++;
		
		for (cont = tam-1; cont < posicao; cont--){
			if (l->n < tam-1){
				l[cont+1] = l[cont];
			}
		}
		
		printf ("\nDigite a matrícula: ");
		scanf ("%d",&l->mat[posicao-1]);
		
		printf ("\nDigite a nota: ");
		scanf ("%f",&l->nota[posicao-1]);	
			
		printf ("\nAdicionado com sucesso...\n");
	}
	
	system ("pause");
}


void ordenacao (lista *l){ //8
	int i,j;
	lista aux;
	
	for (i = 0; i < l->n; i++){
		for (j = i+1; j < l->n; j++){
			if (l[i].mat > l[j].mat){
				aux = l[i];
				l[i] = l[j];
				l[j] = aux;
			}
		}
	}
	printf ("\nConcluído.\n");
	system ("pause");
}


void subaprovado (lista *l, aprovados *ap){ //9
	int cont;	

	for (cont = 0; cont < l->n; cont++){
		if (l->nota[cont] >= 7){
			ap->mat[cont] = l->mat[cont];
			ap->nota[cont] = l->nota[cont];
			ap->posicao++;
		}
	}
	system ("pause");
}

void mostraraprovados (aprovados *ap){
	int cont;
	
	for (cont = 0; cont < ap->posicao; cont++){
		printf ("\nMatricula: %d",ap->mat[cont]);
		printf ("Nota: %.1f\n",ap->nota[cont]);
	}
}
void mostrar (lista *l){ //10
	int cont;
	
	for (cont = 0; cont < l->n; cont++){
		printf ("\nMatricula: ",l->mat[cont]);
		printf ("Nota: %.1f\n",l->nota[cont]);
	}
	system ("pause");
}


main (){
	setlocale(LC_ALL,"portuguese_Brazil");
	
	int r;
	
	lista l;	
	aprovados ap;
	
	inicialista(&l, &ap);
	
	r = menu();
	
	while (r != 0){
		
		if (r == 1){
			system ("cls");
			inserirfinal(&l);
			system ("cls");		
		}else if(r == 2){
			system ("cls");
			numeronos(&l);
			system ("cls");
		}else if(r == 3){
			system ("cls");
			localizarpormatricula(&l);
			system ("cls");
		}else if(r == 4){
			system ("cls");
			mostrarvalorno(&l);
			system ("cls");
		}else if(r == 5){
			system ("cls");
			removerposicao(&l);
			system ("cls");
		}else if(r == 6){
			system ("cls");
			maiornota(&l);
			system ("cls");
		}else if(r == 7){
			system ("cls");
			inserirnota(&l);
			system ("cls");
		}else if(r == 8){
			system ("cls");
			ordenacao(&l);
			mostraraprovados(&ap);
			system ("cls"); 
		}else if(r == 9){
			system ("cls");
			subaprovado(&l, &ap);
			system ("cls");
		}else if(r == 10){
			system ("cls");
			mostrar(&l);
			system ("cls");
		}
		
		r = menu();
	}
	
	
	return 0;
}

