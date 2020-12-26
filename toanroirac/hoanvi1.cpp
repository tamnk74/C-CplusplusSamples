#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>

int count = 0;
int a[20], b[20], n;

void Init(int a[], int n)
{
	for(int i = 1; i <= n; i++)
	{
		a[i] = 0;
	}
}
void Out(int a[], int n)
{
	count ++;
	printf("\n%d.\t", count);
	for(int i = 1; i <= n; i++)
	{
		printf("%d", a[i]);
	}
}

void hoanvi(int a[], int b[], int n, int i)
{
	
	int j;
	for(j = 1; j <= n; j++)
	{
		if(b[j] == 0)	
		{
			a[i] = j;
			b[j] = 1;
			if(i == n) Out(a, n);
			else hoanvi(a, b, n, i + 1);
			b[j] = 0;
		}
		
	}
}

bool cont()
{
	printf("\n\nPress key K to exit, any key to continue...");
	char c = getch();
	if(toupper(c)== 'K') return false;
	count = 0;
	return true; 
}

int main()
{
	Init(a, n);
	Init(b, n);
	do
	{
		system("cls");
		printf("Nhap n = ");
		scanf("%d", &n);
		hoanvi(a, b, n, 1);
	}
	while(cont());

	printf("\nPress any key to exit...");
	getch();
	return 0;
}