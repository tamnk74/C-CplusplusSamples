#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
int count=0;
void Init(int b[], int k)
{
	for(int i = 1; i<=k; i++ ) b[i]=i;
}
void Out(int b[], int k)
{
	count++;
	printf("\n%5d.    ",count);
	for(int i = 1; i<=k; i++ ) printf("%d",b[i]);
}
int isLastconfigure(int b[], int k, int n)
{
		if( b[k] < n ) return 0;
	return 1;
}
void Nextconfigure(int b[], int k, int n)
{
	int i = k;
	while(b[i] == 0 && i>0) i--;
	b[i]--;b[i-1] ++;
	for(int j = i+1; j<=k; j++ ) b[j]=b[i]+j-i;
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
	int n,k,stop,b[20];
	do
	{
	do
	{
		printf("Nhap n = ");
		scanf("%d",&n);
		printf("Nhap k = ");
		scanf("%d",&k);
		if(k>n) printf("%d > %d",k,n);
	}while(k>n);
	Init(b,k);
	Out(b,k);
	stop= isLastconfigure(b,k,n);
	while(stop==0)
	{
		Nextconfigure(b,k,n);
		Out(b,k);
		stop= isLastconfigure(b,k,n);
	}
	}while(tieptuc());
}
