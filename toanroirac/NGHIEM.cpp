#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
int count=0;

void Init(int b[], int k,int n)
{
	for(int i = 1; i<k; i++ ) b[i]=0;
	b[k] = n;
}
void Out(int b[], int k)
{
	count++;
	printf("\n%5d.    ",count);
	for(int i = 1; i<=k; i++ ) printf("%3d",b[i]);
}
int sum(int b[], int k)
{
    int sum = 0;
    for(int i = 1; i<=k; i++ ) sum+= b[i];
    return sum;
}
int C(int a,int b)
{
    if( a < b ) return 0;
    if( b == 0 || b == a) return 1;
    else return C( a - 1, b ) + C( a - 1, b - 1) ;
}
int isLastconfigure(int b[], int k, int n)
{
		if( b[1] == n ) return 1;
	return 0;
}
void Nextconfigure(int b[], int k, int n)
{
	int i = k;
	while(b[i] == n && i>0) i--;
	b[i]++;
	for(int j = i+1; j<=k; j++ ) b[j]=0;
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
int main()
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
    	}
    while(k>n);
	Init(b,k,n);
	Out(b,k);
	stop= isLastconfigure(b,k,n);
	while(stop==0)
    	{
    		Nextconfigure(b,k,n);
    		if(sum(b,k) == n) Out(b,k);
    		stop= isLastconfigure(b,k,n);
    	}
	printf("\n%d\n",C(n,k));
	}while(tieptuc());
	getch();
	return 1;
}
