#include <stdio.h>
#include <stdlib.h>

int MaxBit(int n)
{
  int x = 0, i = 0;
  do
  {
    n & 1 ? x = (x << 1) | 1 : i++;
  } while (n = n >> 1);
  return x << i;
}

int OddEvenBit(int n)
{
  int x = (n & 0x55555555) << 1;
  n = (n >> 1) & 0x55555555;
  return n | x;
  ;
}
int main()
{
  printf("\n%d", OddEvenBit(7));
  system("pause");
  return 1;
}