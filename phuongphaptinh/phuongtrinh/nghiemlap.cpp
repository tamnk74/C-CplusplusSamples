#include<stdio.h>
#include<conio.h>
#include<math.h>
#define eps 1e-5
double gk( float x )
{
	return pow( (double)(x+1), 1.0/3 );
}
int main()
{
	double x,y;
	printf(" Nhap gia tri xap xi: " );
	scanf( "%f", &x );
	do
	{
		y = x;
		x = gk(y);
	}
	while( fabs(x-y) > eps );
	printf("Nghiem cua phuong trinh la %.3f",y);
	getch();
}