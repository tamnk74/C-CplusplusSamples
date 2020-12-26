#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>
//Nhap mang	he so
void Input(int a[], int n)
	{
		for(int i =0 ; i<=n; i++)
		{
			printf("a[%d] = ",i);
			scanf("%d",&a[i]);
		}
	}
void Finput(int heso[], int &n)
{
	FILE*f;
    f=fopen("dulieu.txt","r");
	fscanf(f,"%d",&n);
	for(int i =0 ; i<=n; i++)	fscanf(f,"%d",&heso[i]);
}
void Nhap(int heso[], int &n)
{
	FILE*f;
    f=fopen("dulieu.txt","w");
    printf("\nNhap n = ");	scanf("%d",&n);
    fprintf(f,"%d \n",n);
    for(int i = 0 ; i<=n ; i++)	
    {
    	printf("a[%d]=",i);
    	scanf("%d",&heso[i]);
    	fprintf(f,"%d ",heso[i]);
    }
    
}
// Xuat da thuc
void Output(int a[], int n)
	{
		for(int i =0 ; i< n-1 ; i++)	
		if( a[i]!=0 )printf("%dx^%d+ ",a[i],n-i);
		if(a[n-1]==1) printf("x");
		else if(a[n-1]== -1) printf("-x");
		else if(a[n-1] != 0 ) printf( "%d x", a[n-1] );
		if(a[n]!=0) printf("+ %d",a[n]);
	}
// Tinh f(x)
float fx(int heso[], int n, float x)
	{
		float p = heso[0];
		for(int i = 1; i<=n; i++) p = p*x+ heso[i];
		return p;
	}
float gx(int heso[], int n, float x)
	{
		float p = heso[1];
		for(int i = 2; i<=n; i++) p = p*x+ heso[i];
		return powf(-p/heso[0],1.0/n);
	}
// Tinh dao ham f'(x)
	float fxdh(int heso[],int n,float x)
	{
		float p = n*heso[0];
		for(int i = 1; i<n; i++) p = p*x+ (n-i)*heso[i];
		return p;
	}
	
// Tim nghiem da thuc bang phuong phap chia doi
float nghiemdt(int heso[],int n, float a,float b)
	{
		float c;
		if(fx(heso,n,a)<0 && fx(heso,n,b)>0 )
		{
		while(fabs(fx(heso,n,c))>0.00001)
		{
			c = (a+b)/2;
			if(fx(heso,n,c)>0) b=c; else a=c;
		//	printf("%f    \n",c);
		}
		return c;
		}
		else 
		{
			printf(" ( %f, %f ) khong co nghiem!\nRETURN",a,b);
			return -1.0;
		}
		
	}

float nghiemdt1(int heso[],int n, float a,float b)
	{
		float c;
		if( fx(heso,n,a)*fx(heso,n,b) <= 0 )
		{
			while(fabs(fx(heso,n,a))>0.000001)	
				{
					if( fx(heso,n,a)*fx(heso,n,(a+b)/2) > 0 ) a = (a+b)/2; else b = (a+b)/2;
					printf("\n%f",a);
				}
			return a;
		}
		else 
		{
			printf(" ( %f, %f ) khong co nghiem!\nRETURN",a,b);
			return -1.0;
		}
		
	}



// Tim nghiem phuong trinh bang phuong phap tiep tuyen
float nghiemtt(int heso[],int n, float x)
	{
	
		 if(fx(heso,n,x)*fxdh(heso,n,x) >0) 
		 {
		 	float y;
		 	do{
		 		y=x;
		 		x = y - fx(heso,n,y)/fxdh(heso,n,y);
		 		printf("\n%.3f	%.3f",x,y, fx(heso,n,y)/fxdh(heso,n,y));
		 	}while(fabs(x-y)>0.000001);
		 	return x;
		 }
		 else 
		 {
		 	 printf("\n%.3f khong dung",x);
		 	 return -1.0;
		 }
		 
	}
// Tim nghiem bang phuong phap lap
float nghiemlap(int heso[],int n, float x)
	{
		 	float y;
		 	do{
		 		y=x;
		 		x = gx(heso,n,x);
		 		printf("\n%.3f	%.3f	%.3f",x,y, gx(heso,n,y));
		 	}while(fabs(x-y)>0.000001);
		 	return x;
	}

int main()
{
	int n, heso[20],cc,ch;
	float x, a=1, b=2;
	// mo file de doc  
     
	Finput(heso,n);

	while(1)
	{
	system("cls");
	printf("f(x)= ");	Output(heso,n);
	printf("\nNhap\t F(x)\t F'(x)\t Nghiem\n");
	printf("  1 \t  2  \t   3  \t 4\nTuychon:");
	scanf("%d",&cc);
	system("cls");
	printf("f(x)= ");	Output(heso,n);
	switch(cc)
		{
		case 1:
			Nhap(heso,n);
			getch();
			break;
		case 2:
			printf("\nx=");	scanf("%f",&x);
			printf("\nf(%f) = %f",x,fx(heso,n,x));
			getch();break;
		case 3:
			printf("\nx=");	scanf("%f",&x);
			printf("\nf'(%f) = %f",x,fxdh(heso,n,x));
			getch();break;
		case 4:
			printf("\nchia doi\t lap \t tiep tuyen\n");
			printf("    1   \t  2  \t     3 \nTuychon:");
			scanf("%d",&ch);
			system("cls");
			printf("f(x)= ");	Output(heso,n);
			switch(ch)
				{
				case 1:
					printf("\na= ");	scanf("%f", &b);
					printf("\nb= ");	scanf("%f", &b);
					printf("\nNghiem cua phuong trinh xo = %f",nghiemdt1(heso,n,a,b));
					break;
				case 2:
					printf("\nx=");	scanf("%f",&x);
					printf("\nNghiem cua phuong trinh xo = %f",nghiemlap(heso,n,x));
					break;
				case 3:
					printf("\nx=");	scanf("%f",&x);
					printf("\nNghiem cua phuong trinh xo = %f",nghiemtt(heso,n,x));
			//	default: break;
				}
			getch();
		}
	}
	getch();
}



