#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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


int menu (){
  int resposta;
  printf("----->Painel Escolar<-----\n");
  printf("0 - Sair\n");
  printf("1 - Inserir Aluno.\n");
  printf("2 - Exibir todos os alunos.\n");
  printf("3 - Mostrar quantidade alunos cadastrados.\n");
  printf("4 - Buscar aluno pelo nome.\n");
  printf("5 - Remover aluno.\n");
  printf("6 - Resetar lista.\n");
  printf("Opção: ");
  scanf("%d", &resposta);
  return resposta;
}

void iniciarEstrutura(listaAlunos *alunos){
  alunos->totalAlunos = 0;
}

int quantidadeAlunos(listaAlunos *alunos){
  printf("Quantidade de alunos registrados: %d\n", alunos->totalAlunos);
  return alunos->totalAlunos;
}

void exibirAlunos(listaAlunos *alunos){
  if(alunos->totalAlunos == 0){
    printf("Não temos nenhum aluno cadastrado!!\n");
  }else{
    for(int count = 0; count < alunos->totalAlunos; count++){
      printf("Posição: %d  - Nome: %s - ", count, alunos->aluno[count].nome);
      printf("Matricula: %d - Média Escolar: %.2f", alunos->aluno[count].matricula, alunos->aluno[count].media);
      printf("\n");
    }
  }
}

int buscarPosicaoPeloNome(listaAlunos *alunos){
  if(alunos->totalAlunos == 0){
    printf("Não temos nenhum aluno cadastrado !!\n");
    return -1;
  }else{
    char nomeBuscado[30];
    printf("Digite o nome a ser buscado: ");
    scanf("%s", &nomeBuscado);
    int indice = 0;
    while (indice < alunos->totalAlunos){
      if (strcmp(alunos->aluno[indice].nome, nomeBuscado) == 0)
      {
        printf("\nAluno encontrado na posição %d, e tem a matricula: %d\n", indice ,alunos->aluno[indice].matricula);
        return indice;
      }else{
        indice++;
      }
    }
    printf("\nNenhum aluno com esse nome foi encontrado\n");
    return -1;
  }
}

// Ordenando a inserção pelas matricula em ordem crescente.
bool cadastrarAluno(listaAlunos *alunos){
  if(alunos->totalAlunos == max-1){
    printf("Sem espaço para cadastrar mais alunos\n");
    return false;
  }else{
      estudante novoAluno;
      printf("Digite o nome do aluno a ser cadastrado: ");
      scanf("%s", &novoAluno.nome);
      printf("Digite o numero de matricula: ");
      scanf("%d", &novoAluno.matricula);
      printf("Digite a média escolar do aluno: ");
      scanf("%f", &novoAluno.media);
      int count = alunos->totalAlunos;
      while(count > 0 && alunos->aluno[count-1].matricula > novoAluno.matricula){
        alunos->aluno[count] = alunos->aluno[count-1];
        count--;
      }
      alunos->aluno[count] = novoAluno;
      alunos->totalAlunos++;
      return true;      
  }
}

int buscarAlunoPelaMatricula(listaAlunos *alunos, int matricula){
  if(alunos->totalAlunos == 0){
    printf("Não tem nenhum aluno cadastrado.\n");
    return -1;
  }else{
    int count = 0;
    while(count < alunos->totalAlunos){
      if(matricula == alunos->aluno[count].matricula){
        printf("Aluno encontrado na posição: %d\n", count);
        return count;
      }else{
        count++;
      }
    }
    printf("Nada encontrado nesse numero de matricula...\n");
    return -1;
  }
}

// Removendo o aluno pela matricula
bool removerAluno(listaAlunos *alunos){
  int matriculaDeletada;
  printf("Digite a matricula do aluno que será deletado: ");
  scanf("%d", &matriculaDeletada);
  int indexAlunoDeletado = buscarAlunoPelaMatricula(alunos, matriculaDeletada);
  printf("voltei, %d\n", indexAlunoDeletado);
  if(alunos->totalAlunos == 0 || indexAlunoDeletado == -1){
    printf("Não tem nenhum aluno para ser removido!\n");
    return false;
  }else{
    printf("foo");
    int count = indexAlunoDeletado;
    while (count < alunos->totalAlunos)
    {
      alunos->aluno[count] = alunos->aluno[count + 1];
    }
    alunos->totalAlunos--;
    printf("Aluno deletado!\n");
    return true;
  }
}


void resetar(listaAlunos *alunos){
  alunos->totalAlunos = 0;
}


void main(){
  listaAlunos alunos;
  
  iniciarEstrutura(&alunos);
  
  int r = menu();

  while(r != 0){
    switch (r)
    {
    case 1:
      system("clear");
      cadastrarAluno(&alunos);
      break;
    case 2:
      system("clear");
      exibirAlunos(&alunos);
      break;
    case 3:
      system("clear");
      quantidadeAlunos(&alunos);
      break;
    case 4:
      system("clear");
      buscarPosicaoPeloNome(&alunos);
      break;
    case 5:
      system("clear");
      removerAluno(&alunos);
      break;
    case 6:
      system("clear");
      resetar(&alunos);
      break;
    }
    r = menu();
  }

}


