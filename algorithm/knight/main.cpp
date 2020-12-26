#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#define max 20
int count = 0,n;
int a[max],b[max],c[max],d[max];
void Init(int n)
{
	int i;
	for(i = 0; i < n; i++) b[i] = 0;
	for(i = 0; i < 2*n-1; i++) c[i]=d[i]=0;
}
void Out(int a[], int n)
{
	int i,j;
	printf("\n%d.\n", ++count);
	for(i = 1; i < n; i++)
	{
		for(j = 1; j < n; j++)
		{
			if( j == a[i]) printf(" x "); else printf(" . ");
		}
		printf("\n");
	}
}
void xep_hau(int i)
{
	int j;
	for(j =0; j<n; j++)
	{
		if( b[j]==0 && c[i-j+7]==0 && d[i+j]==0)
		{
			a[i] = j;
			b[j] = 1;
			c[i-j+7] = 1;
			d[i+j] = 1;
			if( i==n ) Out(a,n);
			else xep_hau(i+1);
			b[j] = 0;
			c[i-j+7] = 0;
			d[i+j] = 0;
		}
	}
}

bool cont()
{
	printf("\nPress key k to exit,any key to continue...");
	char c = getch();
	if(toupper(c)== 'K') return false;
	count = 0;
	return true; 
}
int main()
{
	do
	{
		system("cls");
		printf("Nhap kich thuoc ban co n = ");
		scanf("%d", &n);
		Init(n);
		xep_hau(1);
		printf("\n\nCO %d KET QUA\n\a",count);
	}
	while(cont());
	getch();
	return 1;
}
