#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
int count = 0;
void Init(int a[], int n)
{
	for(int i=1;i<=n;i++) a[i]=0;
}
void Out(int a[], int n)
{
	count++;
	printf("\n%d.\t",count);
	for(int i=1;i<=n;i++) printf("%d",a[i]);
}
void Bin(int a[], int n,int i)
{
	int j;
	for(j=0; j<=1; j++)
	{
		a[i]=j;
		if(i==n) Out(a,n);
		else Bin(a,n,i+1);
	}
}
bool cont()
{
	printf("\nTiep tuc hay khong?C/N");
	char c = getch();
	if(toupper(c)=='K') return false;
	count = 0;
	return true; 
}
main()
{
	int a[20],n;
	do
	{
	system("cls");
	printf("Nhap n = ");
	scanf("%d",&n);
	Bin(a,n,1);
	}while(cont());
	getch();
}
