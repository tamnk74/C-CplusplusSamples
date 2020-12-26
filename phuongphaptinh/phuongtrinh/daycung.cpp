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
  f = fopen("dulieudaycung.txt", "r");
  fscanf(f, "%d", &n);
  for (int i = 0; i <= n; i++)
    fscanf(f, "%d", &heso[i]);
}
void Nhap(int heso[], int &n)
{
  FILE *f;
  f = fopen("dulieudaycung.txt", "w");
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
  float x, a, b;
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
    printf("\ta\tb\tx\tf(x)");
    x = a - (b - a) * fx(heso, n, a) / (fx(heso, n, b) - fx(heso, n, a));
    if (fx(heso, n, a) * fx(heso, n, x) <= 0)
    {
      do
      {
        c++;
        b = x;
        x = a - (b - a) * fx(heso, n, a) / (fx(heso, n, b) - fx(heso, n, a));
        printf("\n%10.3f%8.3f%8.3f%8.3f", a, b, x, fx(heso, n, x));
      } while (fabs(b - x) > 0.00010 && c < 100);
    }
    else
    {
      do
      {
        c++;
        a = x;
        x = a - (b - a) * fx(heso, n, a) / (fx(heso, n, b) - fx(heso, n, a));
        printf("\n%10.3f\t%8.3f\t%8.3f\t%8.3f", a, b, x, fx(heso, n, x));
      } while (fabs(a - x) > 0.0001 && c < 500);
    };
    if (c < 100)
      printf("\nNghiem cua phuong trinh xo = %f", x);
    else
      printf("\n\nkhong co nghiem!!!\n");
  } while (cont());
  getch();
  return 1;
}