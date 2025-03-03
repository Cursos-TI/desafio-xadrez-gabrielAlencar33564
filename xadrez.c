#include <stdio.h>
#include <string.h>

void moviment(char *moviment)
{
  if (strcmp(moviment, "top") == 0)
  {
    printf("Cima\n");
  }
  else if (strcmp(moviment, "bottom") == 0)
  {
    printf("Baixo\n");
  }
  else if (strcmp(moviment, "left") == 0)
  {
    printf("Esquerda\n");
  }
  else if (strcmp(moviment, "right") == 0)
  {
    printf("Direita\n");
  }
}

void rook(int moviments)
{
  if (moviments == 0)
    return;
  moviment("right");
  rook(moviments - 1);
}

void bishopRecursive(int moviments)
{
  if (moviments == 0)
    return;
  moviment("top");
  moviment("right");
  bishopRecursive(moviments - 1);
}

void bishopLoop(int moviments)
{
  for (int i = 0; i < moviments; i++)
  {
    moviment("top");
    for (int j = 0; j < moviments; j++)
    {
      if (i == j)
        moviment("right");
    }
  }
}

void queen(int moviments)
{
  if (moviments == 0)
    return;
  moviment("left");
  queen(moviments - 1);
}

void khight()
{
  int i = 0;
  do
  {
    moviment("top");
    i++;
  } while (i < 3);
}

void kight()
{
  for (int i = 0; i < 3; i++)
  {
    while (i == 2)
    {
      moviment("left");
      return;
    }
    moviment("bottom");
  }
}

int main()
{
  printf("Torre:\n");
  rook(5);
  printf("\n");

  printf("Bispo recursivo:\n");
  bishopRecursive(5);
  printf("\n");

  printf("Bispo loop:\n");
  bishopLoop(5);
  printf("\n");

  printf("Rainha:\n");
  queen(8);
  printf("\n");

  printf("Cavalo:\n");
  kight();
  printf("\n");

  return 0;
}