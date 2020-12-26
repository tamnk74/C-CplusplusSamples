#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
//Nhap mang	he so
void Finput(int heso[], int &n)
{
  FILE *f;
  f = fopen("dulieutt.txt", "r");
  fscanf(f, "%d", &n);
  for (int i = 0; i <= n; i++)
    fscanf(f, "%d", &heso[i]);
}
void Nhap(int heso[], int &n)
{
  FILE *f;
  f = fopen("dulieutt.txt", "w");
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
float fxdh(int heso[], int n, float x)
{
  float p = n * heso[0];
  for (int i = 1; i < n; i++)
    p = p * x + (n - i) * heso[i];
  return p;
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
  int n, heso[20], c = 0, ch;
  float x, y;
  printf("Giai phuong trinh bang phuong phap tiep tuyen");
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
  printf("Giai phuong trinh bang phuong phap tiep tuyen");
  printf("\nf(x)= ");
  Output(heso, n);
  printf("= 0");
  do
  {
    printf("\nNhap gia tri xo ban dau:\nx= ");
    scanf("%f", &x);
    do
    {
      c++;
      y = x;
      x = y - fx(heso, n, y) / fxdh(heso, n, y);
      printf("\n%10.3f	%10.3f", x, fx(heso, n, y) / fxdh(heso, n, y));
    } while (fabs(x - y) > 0.0001 && c < 100);

    if (c < 100)
      printf("\nNghiem cua phuong trinh xo = %f", x);
    else
      printf("\nNhap lai xo");
  } while (cont());
  system("pause");
  return 1;
}