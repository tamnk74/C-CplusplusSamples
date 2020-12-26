#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#define Pi 3.1415926544102
#define Exp 2.718281828
void nhapmang1c(int *a, int &n);
void xuatmang1c(int *a, int &n);
void nhapmang2c(int a[10][10], int &n);
void xuatmang2c(int a[10][10], int &n);
float dathuc(int *a, int &n, float x);
float lnx(float x);
float expx(float x);
float sinx(float x);
float cosx(float x);
bool tieptuc();
main()
{
  int a[10], n;
  float x;
  /*
	  printf("So phan tu cua mang: ");
      scanf("%d",&n);
      nhapmang1c(a,n);
      printf("Mang A:");
      xuatmang1c(a,n);
      do{
	      printf("\nNhap gia tri can tinh : "); scanf("%f",&x);
	      printf("Gia tri da thuc: %f",dathuc(a,n,x));
      	}while(tieptuc());
      
	  do{
			system("cls");
			printf("Tinh cosx:\n");
			printf("\nx= : "); scanf("%f",&x);
			printf("cos(%f)=%f",x,cosx(x));
			}while(tieptuc());
		do{
			system("cls");
			printf("Tinh sinx:\n");
			printf("\nx= : "); scanf("%f",&x);
			printf("cos(%f)= %f",x,sinx(x));
			}while(tieptuc());
		do{
			system("cls");
			printf("Tinh e^x:\n");
			printf("\nx= : "); scanf("%f",&x);
			printf("e^(%f)= %f",x,expx(x));
			}while(tieptuc());*/
  do
  {
    system("cls");
    printf("Tinh ln(x):\n");
    printf("\nx= : ");
    scanf("%f", &x);
    printf("ln(%f)= %f", x, lnx(x));
  } while (tieptuc());
  system("pause");
}

// Ham-----------------------------------------------
void nhapmang1c(int *a, int &n)
{
  printf("Nhap mang:");
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
}
void xuatmang1c(int *a, int &n)
{
  for (int i = 0; i < n; i++)
    printf("%5d", a[i]);
}
void nhapmang2c(int a[10][10], int &n)
{
  printf("Nhap mang:");
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &a[i][j]);
}
void xuatmang2c(int a[10][10], int &n)
{
  for (int i = 0; i < n; i++)
  {
    printf("\n");
    for (int j = 0; j < n; j++)
      printf("%5d", a[i][j]);
  }
}
float dathuc(int *a, int &n, float x)
{
  float p = a[0];
  for (int i = 1; i < n; i++)
    p = p * x + a[i];
  return p;
}
bool tieptuc()
{
  char ch;
  fflush(stdin);
  printf("\nBan co muon tiep tuc (Y/N):\n");
  scanf("%c", &ch);
  if (toupper(ch) == 'N')
    return false;
  return true;
}
// cosx(float x)
float cosx(float x)
{
  float q = 1, t = 1;
  int k = 2;
  do
  {
    t *= (-1) * x * x / (k * (k - 1));
    q += t;
    k += 2;
  } while (fabs(t) > 0.000001);
  return q;
}
// sinx(float x)
float sinx(float x)
{
  float q = 0, t = x;
  int k = 3;
  do
  {
    q += t;
    t *= (-1) * x * x / (k * (k - 1));
    k += 2;
  } while (fabs(t) > 0.000001);
  return q;
}
// expx(float x)
float expx(float x)
{
  float q = 1, t = 1;
  int k = 1;
  do
  {
    t *= x / k;
    q += t;
    k++;
  } while (fabs(t) > 0.00000001);
  return q;
}
//LNX(X)
float lnx(float x)
{
  if (x <= 0)
    return -1;
  else if (x < 2)
  {
    float q = 0, t = -1;
    int k = 1;
    do
    {
      t *= -(x - 1);
      q += t / k;
      k++;
    } while ((t / k) < 0.0000001 && k < 32767);
    return q;
  }
  else
    return -lnx(1 / x);
}