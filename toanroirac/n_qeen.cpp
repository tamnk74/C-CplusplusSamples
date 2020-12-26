#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <ctype.h>
#define max 10
float a[max][max];
int n;
float x[max];
FILE* f;
FILE* f1;

void nhap(float a[][max])
{
 	 fscanf( f, "%d", &n );
   	 for(int i = 1; i<=n; i++) 
     for(int j = 1; j<=n+1  ; j++) 
	     {
	             fscanf(f,"%f",&a[i][j]);
	     }
   
}
void xuat(float a[][max], int n)
{
     for(int i = 1; i<= n; i++) 
     {
             printf("\n");
             for(int j = 1; j<= n+1; j++) 
             {
                     printf("%10.2f",a[i][j]);
             }
     }
}
void xuatnghiem(float x[],int n)
{
 	 for(int i = 1; i<= n; i++) 
 	 {
   		 printf("%10.5f",x[i]);
   		 fprintf(f1,"%10.5f",x[i]);
		 }
	 fprintf(f1,"\n");
	// fclose(f1);
	 
 }
bool cont()
 {
  	  char ch;
  	  fflush(stdin);
  	  printf("\nTiep tuc khong?y/n");
  	  scanf("%c",&ch);
  	  if(toupper(ch)=='N' || toupper(ch) == 'K') return false;
  	  return true;
 }
void nghiem(float a[][max], float x[], int n)
{
 	 int i,j,t,dem=0;
 	 float y[max];
 	 float s;
 	 do
	 {
  	   	   t = 0;
		   xuatnghiem( x, n);
   	 	   printf("\n");
		   for(i = 1; i<= n; i++)
		 	 {
			  	 s = 0;
	 	  	 	 y[i] = x[i];  
				 for( j =1; j<=n; j++)
 	   			 if( j != i )	s += a[i][j]*x[j];
		   	   	 if(a[i][i] != 0) x[i] =(a[i][n+1] - s)/a[i][i];
		   		 if( fabs( x[i]-y[i] ) >0.0001) t = 1; 
		   	 }
		   	 dem++;
	 } while( t == 1 && dem<30);
}
int main()
{
	 	f = fopen("data1.txt","r");
		f1 = fopen("nghiem.txt","w");
		if( f == NULL ) printf("\nKhong mo duoc tep data1.txt ");
		if( f1 == NULL ) printf("\nKhong mo duoc tep nghiem.txt ");
      nhap(a);
      printf("\nHe phuong trinh %d an so",n);
      printf("\nMa tran he so:");
	  xuat(a,n);
      do
	  {
	  fflush(f1);
      printf("\n Nhap xap xi nghiem ban dau: ");
      for(int i = 1; i<=n; i++) scanf("%f",&x[i]); 
      nghiem(a,x,n);
      printf("\nNghiem cua he phuong trinh");
      xuatnghiem(x,n);
      fprintf(f1,"\nNghiem cua he phuong trinh");
      for(int i = 1; i<= n; i++) 
 	  {
   		 fprintf(f1,"%10.5f",x[i]);
	  }
	  fprintf(f1,"\n");
      }while(cont());
      fclose(f1);
      fclose(f);
      getch();
      return 1;
}