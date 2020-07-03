#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 50

typedef struct
{
  int key;
} registry;

typedef struct
{
  registry reg[MAX];
  int numElements;
} list;

//functions interface
int menu();
void initializeList(list *l);
int numberOfElements(list *l);
void showAllElements(list *l);
int searchPositionByElement(list *l, int element);
bool insertElement(list *l, registry reg, int position);

//Functions implemention
int menu()
{
  int r;
  printf("0 - Stop");
  printf("\n1 - Return quantity of elements.");
  printf("\n2 - Show All elements.");
  printf("\n3 - Search position by element.");
  printf("\n4 - Insert");
  printf("\n5 - Delete");
  printf("\n6 - Reset");
  printf("\nTell us what you want: ");
  scanf("%d", &r);

  return r;
}

void initializeList(list *l)
{
  l->numElements = 0;
}

int numberOfElements(list *l)
{
  printf("---> Number of elements: %d <---\n\n", l->numElements);
  return l->numElements;
}

void showAllElements(list *l)
{
  if (l->numElements == 0)
  {
    printf("Your list is empty, please insert something.\n\n");
  }
  else
  {
    int i;
    printf("\n----->Elements<-----\n");
    for (i = 0; i < l->numElements; i++)
    {
      printf("Elemento: [%d] na Posição: %d \n", l->reg[i].key, i);
    }
    printf("\n\n");
  }
}

int searchPositionByElement(list *l, int element)
{
  if (l->numElements == 0)
  {
    printf("Your list is empty, please insert something.\n");
    return -1;
  }
  else
  {
    int i = 0;
    while (i < l->numElements)
    {
      if (i == element)
      {
        printf("Posição do elemento é: %d\n", i);
        return i;
      }
      else
      {
        i++;
      }
    }
    return -1;
  }
}

bool insertElement(list *l, registry reg, int position)
{
  if (l->numElements == MAX || position < 0 || position > l->numElements)
  {
    printf("invalid position, please try again!\n");
    return false;
  }
  else
  {
    for (int i = l->numElements; i > position; i--)
    {
      l->reg[i].key = l->reg[i - 1].key;
    }
    l->reg[position] = reg;
    l->numElements++;
    return true;
  }
}

bool deleteElement(list *l){
  if(l->numElements == 0){
    printf("There is nothing to delete.\n\n");
    return false;
  }else{
    int positionToDelete;
    printf("FRIST I'm showing to you the complete list: \n");
    showAllElements(l);
    printf("And then I want to know the position that you want delete: ");
    scanf("%d", &positionToDelete);
    if(positionToDelete < 0 || positionToDelete > l->numElements){
      printf("Invalid input, try again\n");
      return false;
    }else{
      for (int i = positionToDelete; i < l->numElements; i++)
      {
        l->reg[i] = l->reg[i + 1];
      }
      l->numElements--;
      return true;
    }
  }
}

void resetList(list *l){
  l->numElements = 0;
}

void main()
{
  list listOne;
  registry reg;
  int valuePosition = 0;

  int option = 0;
  option = menu();

  initializeList(&listOne);
  while (option != 0)
  {
    switch (option)
    {
    case 1:
      system("clear");
      int r = numberOfElements(&listOne);
      break;
    case 2:
      system("clear");
      showAllElements(&listOne);
      break;
    case 3:
      system("clear");
      int number;
      printf("Please type the number that you want to find: ");
      scanf("%d", &number);
      searchPositionByElement(&listOne, number);
      break;
    case 4:
      system("clear");
      printf("Tell the key that you want insert: ");
      scanf("%d", &reg.key);
      printf("Now I need to the position that you want insert it: ");
      scanf("%d", &valuePosition);
      insertElement(&listOne, reg, valuePosition);
      break;
    case 5:
      system("clear");
      deleteElement(&listOne);
      break;
    case 6:
      system("clear");
      resetList(&listOne);
      break;
    }
    option = menu();
  }
}