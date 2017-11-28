#include <stdio.h>
#include <stdlib.h>

int menu(){
    int m;
    printf ("\n1-SOMA\n2-SUBTRAÇÃO\n3-MULTIPLICAÇÃO\n4-DIVISÃO\n5-SAIR\nESCOLHA SUA OPÇÃO: ");
    scanf ("%d",&m);
    return (m);
}
void soma (int x, int y){
    printf ("\n\no valor de %d + %d = %d",x,y,x+y);
}
void subtracao(int x, int y){
    printf ("\n\no valor de %d - %d = %d",x,y,x-y);
    }
void multiplicacao(int x, int y){
    printf ("\n\no valor de %d x %d = %d",x,y,x*y);
}
void divisao(int x, int y){
    while (y==0){
        printf ("\nNão é permitido divisão por zero. Digite outro valor: ");
		scanf("%d", &y);
	}
    printf ("\n\no valor de %d / %d = %d",x,y,x/y);
}

int main (){

    int a,b,r;

    r=menu();

    if(r==5){
        printf("\nFechando...\n");
    }
    else{
    printf ("\n\nDigite 2 valores inteiros: ");
    scanf ("%d %d",&a,&b);
    }

    if (r==1) soma(a,b);
    if (r==2) subtracao(a,b);
    if (r==3) multiplicacao(a,b);
    if (r==4) divisao(a,b);










}
