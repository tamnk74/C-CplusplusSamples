#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>

int count=0;
int max;
void Init(int a[], int k,int n)
{
	for(int i = 1; i<k; i++ ) a[i]=0;
	a[k] = n;
}
void Out(int a[], int k)
{
	count++;
	printf("\n%3d.    ",count);
	for(int i = 1; i<=k; i++ ) printf("%3d",a[i]);
}
int sum(int a[], int k)
{
    int sum = 0;
    for(int i = 1; i<=k; i++ ) sum+= a[i];
    return sum;
}
int C(int a,int b)
{
    if( a < b ) return 0;
    if( b == 0 || b == a) return 1;
    else return C( a - 1, b ) + C( a - 1, b - 1) ;
}
int isLastconfigure(int a[], int k, int n)
{
		if( a[1] == n ) return 1;
	return 0;
}
void Nextconfigure(int a[], int k, int n)
{
	int i = k;
	while(a[i] == n && i>0) i--;
	if(i>1) a[i-1]++;
	a[i]++;
	for(int j = i+1; j<=k; j++ ) a[j]=0;
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
	int n,k,stop,a[20];
	do
	{
		// ham nhap
    printf("Nhap n = ");
    scanf("%d",&n);
    printf("Nhap k = ");
    scanf("%d",&k);
		// liet ke
	Init(a,k,n);
	Out(a,k);
	stop= isLastconfigure(a,k,n);
	while(stop==0)
    	{
    		Nextconfigure(a,k,n);
    		if(sum(a,k) == n) Out(a,k);
    		stop= isLastconfigure(a,k,n);
    	}
		//kiem tra so ket qua
	printf("\nCo %d ket qua !!!\n",C( n-1+k, n ));
	}while(tieptuc());
}
