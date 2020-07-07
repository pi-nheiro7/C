#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max 30

typedef struct{
  char nome[30];
  float media;
  int matricula;
}estudante;

typedef struct{
  estudante aluno[max];
  int totalAlunos;
} listaAlunos;


// int menu (){}

void iniciarEstrutura(listaAlunos *alunos){
  alunos->totalAlunos = 0;
}

int quantidadeelementos(listaAlunos *alunos){
  printf("Quantidade de alunos registrados: %d\n", alunos->totalAlunos);
  return alunos->totalAlunos;
}

void exibirAlunos(listaAlunos *alunos){
  if(alunos->totalAlunos == 0){
    printf("Não temos nenhum aluno cadastrado!!\n");
  }else{
    for(int count = 0; count < alunos->totalAlunos; count++){
      printf("Nome: %s - Matricula: %d - Média Escolar: %f\n", alunos->aluno[count].nome, alunos->aluno[count].matricula, alunos->aluno[count].media);
    }
  }
}

int buscarPosicaoPeloNome(listaAlunos *alunos, char nomeBuscado){
  if(alunos->totalAlunos == 0){
    printf("Não temos nenhum aluno cadastrado !!\n");
    return -1;
  }else{
    int indice = 0;
    while (indice < alunos->totalAlunos){
      if (alunos->aluno[indice].nome == nomeBuscado)
      {
        printf("Aluno encontrado na posição %d, e tem a matricula: %d\n", indice ,alunos->aluno[indice].matricula);
        return indice;
      }else{
        indice++;
      }
    }
    return -1;
  }
}

bool cadastrarAluno(listaAlunos *alunos){
  if(alunos->totalAlunos == max-1){
    printf("Sem espaço para cadastrar mais alunos\n");
  }else{
    int posicao = 0;
    printf("Digite em qual posição você deseja inserir o novo aluno: \n");
    scanf("%d", &posicao);
    if(posicao > max-1 || posicao < 0){
      printf("Posição inexistente no arranjo.");
    }else{
      printf("Digite o nome do aluno a ser cadastrado: ");
      fflush(stdin);
      fgets(alunos->aluno[posicao].nome, 30, stdin);
      printf("\nDigite o numero de matricula: ");
      scanf("%d", &alunos->aluno[posicao].matricula);
      printf("\nDigite a média escolar do aluno: ");
      scanf("%f", &alunos->aluno[posicao].media);
      
    }
    
  }
}


