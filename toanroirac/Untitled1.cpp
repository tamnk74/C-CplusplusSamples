#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
int count=0;
void Init(int b[], int n)
{
	for(int i = 1; i<=n; i++ ) b[i]=i;
}
void swap(int &a,int &b)
{
	int temp = a;
	a=b;
	b=temp;
}
void Out(int b[], int k)
{
	count++;
	printf("\n%5d.    ",count);
	for(int i = 1; i<=k; i++ ) printf("%d",b[i]);
}
int isLastconfigure(int b[], int n)
{
	for(int i = 1; i<=n; i++ ) 
		if(b[i]!=n-i+1) return 0;
	return 1;
}
void Nextconfigure(int b[], int n)
{
	int i,j,l,r;
	i=n-1; j=n;
	while(b[i] > b[i+1] && i>0) i--;
	while(b[j] < b[i] && j>0) j--;
	swap(b[j],b[i]);
	l=i+1; r=n;
	while(l<r)
	{
		swap(b[l],b[r]);
		l++;r--;
	}
}
bool tieptuc()
{
	fflush(stdin);
	printf("\nCo muon tiep tuc khong?Y/N");
	char k = getch();
	if(toupper(k)=='K'|| toupper(k)=='N') return false;
	count=0;
	system("cls");
	return true;
}
main()
{
	int n,stop,b[20];
	do
	{
	do
	{
		printf("Nhap n = ");
		scanf("%d",&n);
	}while( n<0 || n>10 );
	Init(b,n);
	Out(b,n);
	stop= isLastconfigure(b,n);
	while(stop==0)
	{
		Nextconfigure(b,n);
		Out(b,n);
		stop= isLastconfigure(b,n);
	}
	}while(tieptuc());
}
