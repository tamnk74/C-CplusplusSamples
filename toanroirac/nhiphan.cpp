#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
int count=0;
void Init(int b[], int n)
{
	for(int i = 0; i<n; i++ ) b[i]=0;
}
void Out(int b[], int n)
{
	count++;
	printf("\n%5d.    ",count);
	for(int i = 0; i<n; i++ ) printf("%d",b[i]);
}
bool isLastconfigure(int b[], int n)
{
	for(int i = 0; i<n; i++ ) 
		if(b[i]==0) return 0;
	return 1;
}
void Nextconfigure(int b[], int n)
{
	int i = n-1;
	while(b[i] != 0 && i>=0) i--;
	b[i]=1;
	for(int j = i+1; j<n; j++ ) b[j]=0;
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
		if(n>15) printf(" %d too large !!!",n);
		if(n<1 ) printf(" %d too small !!!",n);
	}while(n<0||n>15);
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
