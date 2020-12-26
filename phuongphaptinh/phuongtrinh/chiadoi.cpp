#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
//Nhap mang	he so
void Input(int a[], int &n)
{
  printf("Bac cua phuong trinh\nn=");
  scanf("%d", &n);
  for (int i = 0; i <= n; i++)
  {
    printf("a[%d] = ", i);
    scanf("%d", &a[i]);
  }
}
void Finput(int heso[], int &n)
{
  FILE *f;
  f = fopen("dulieuchiadoi.txt", "r");
  fscanf(f, "%d", &n);
  for (int i = 0; i <= n; i++)
    fscanf(f, "%d", &heso[i]);
}
void Nhap(int heso[], int &n)
{
  FILE *f;
  f = fopen("dulieuchiadoi.txt", "w");
  printf("\nNhap n = ");
  scanf("%d", &n);
  fprintf(f, "%d \n", n);
  for (int i = 0; i <= n; i++)
  {
    printf("a[%d]=", i);
    scanf("%d", &heso[i]);
    fprintf(f, "%d ", heso[i]);
  }

  fclose(f);
}
// Xuat da thuc
void Output(int a[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    if (a[i] == 1)
      printf("x^%d+ ", n - i);
    else if (a[i] == -1)
      printf("-x^%d+ ", n - i);
    else if (a[i] != 0)
      printf("%dx^%d+ ", a[i], n - i);
  }
  if (a[n - 1] == 1)
    printf("x");
  else if (a[n - 1] == -1)
    printf("-x");
  else if (a[n - 1] != 0)
    printf("%dx", a[n - 1]);
  if (a[n] != 0)
    printf("+ %d", a[n]);
}
// Tinh f(x)
float fx(int heso[], int n, float x)
{
  float p = heso[0];
  for (int i = 1; i <= n; i++)
    p = p * x + heso[i];
  return p;
}
float nghiemcd(int heso[], int n, float a, float b)
{
  float c;
  if (fx(heso, n, a) < 0 && fx(heso, n, b) > 0)
  {
    do
    {
      c = (a + b) / 2;
      if (fx(heso, n, c) > 0)
        b = c;
      else
        a = c;
      printf("%8.5f\n", c);
    } while (fabs(fx(heso, n, c)) > 0.00001);
    return c;
  }
  else
  {
    printf(" ( %f, %f ) khong co nghiem!\nRETURN", a, b);
    //return -1.0;
  }
}
bool cont()
{
  char ch;
  fflush(stdin);
  printf("\nTiep tuc khong?y/n");
  scanf("%c", &ch);
  if (toupper(ch) == 'N' || toupper(ch) == 'K')
    return false;
  return true;
}

int main()
{
  int n, heso[20], c, ch;
  float x, a = 1, b = 2;
  printf("Giai phuong trinh bang phuong phap chia doi");
  printf("\nNhap tu ban phim(1) hay tu file(2)");
  scanf("%d", &ch);
  switch (ch)
  {
  case 1:
    Nhap(heso, n);
    break;
  default:
    Finput(heso, n);
  }
  system("cls");
  printf("Giai phuong trinh bang phuong phap chia doi");
  printf("\nf(x)= ");
  Output(heso, n);
  printf("= 0");
  do
  {
    printf("\nNhap khoang nghiem:\na= ");
    scanf("%f", &a);
    printf("b= ");
    scanf("%f", &b);
    if (fx(heso, n, a) * fx(heso, n, b) <= 0)
    {
      do
      {
        x = (a + b) / 2;
        if (fx(heso, n, a) * fx(heso, n, x) > 0)
          a = x;
        else
          b = x;
        printf("\n%f", a);
      } while (fabs(a - b) > 0.000001 && fx(heso, n, x) != 0);
      printf("\nNghiem cua phuong trinh xo = %f", x);
    }
    else
      printf(" ( %f, %f ) khong co nghiem!\nRETURN", a, b);

  } while (cont());
  getch();
  return 1;
}