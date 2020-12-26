#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
int count=0;
int x[3] = {3,2,3};
char b[20];
void Init(char b[])
{
	 b[4] = {'a','d','m'};
}
void Out(char b[], int k)
{
	//
	count++;
//	printf("\n%5d.    ",count);
	printf("%c.",'b');
	//for(int i = 0; i<k; i++ ) printf("%c.",b[i]);
}
int isLastconfigure(char b[])
{
		if( b[0] >= 'a' + x[0] - 1 ) return 1;
	return 0;
}
void Nextconfigure(char b[])
{
	int i =3;
	
}

int main()
{
	int n,k,stop;
	
	Out(b,3);
	getch();
	stop= isLastconfigure(b);
	while(stop==0)
    	{
    		Nextconfigure(b);
    		Out(b,k);
    		stop= isLastconfigure(b);
    		getch();
    	}
	getch();
	return 1;
}
