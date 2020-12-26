#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#define max 10
int count = 0;
int a[10][10], n=8;
int x,y;
void delay()
{
	for(int i= -100000;i< 100000;i++);
}
void Init(int a[max][max], int n)
{
	for(int i = 1; i <= n; i++)
	for(int j = 1; j <= n; j++)
	{
		a[i][j] = 1;
	}
}
void Out(int a[max][max], int n)
{
	
	printf("\n%d.\n", ++count);
	
	for(int i = 1; i<= n; i++)
	{
	for(int j = 1; j<= n; j++)
	{
		if( a[i][j] == 0 )printf(" x "); else printf(" _ ");
	}
	printf("\n");
	}
}
bool check(int a[max][max], int n)
{
	for(int i = 1; i <= n; i++)
	for(int j = 1; j <= n; j++)
	{
		if(a[i][j] != 0) return false;
	}
	return true;
}
void xep_hau(int a[max][max],int n, int i,int j)
{
	
	
	if(i>0 && i<=n && j>0 && j<=n)
	{
	for(x = i-2;  x<=i+2; x++)
	for(y = j-2;  y<=j+2; y++)
		{
if(a[i][j] && x>0 &&y>0 && x<=n&& y<=n &&((abs(x-i) ==2 && abs(y-j) ==1) ||( abs(x-i) ==1 && abs(y-j) ==2)))	
			{
				++count;
				a[x][y] = 0;
				if(count >= n*n)
					{
						count =0;
						if(check(a,n)) 		{
												Out(a,n);printf("\n\nabc\n\n");
												getch();
											}
						else {printf("false\a");	delay();delay();delay();delay();delay();delay();}
					}
				else
					{
						system("cls");
						xep_hau(a,n,x,y);
						Out(a,n);delay();delay();delay();delay();delay();delay();delay();
					}
				a[x][y]=1;
			}
			else continue;
		}
	}
}

bool cont()
{
	printf("\npress key k to exit,any key to continue...");
	char c = getch();
	
	if(toupper(c)== 'K') return false;
	count = 0;
	return true; 
}
int main()
{
	
//	do
	{
		system("cls");
		//printf("Nhap n = ");
	//	scanf("%d", &n);
		Init(a,n);
		xep_hau(a,n,1,1);
		printf("\a");
	}
	//while(cont());
	getch();
	return 1;
}
