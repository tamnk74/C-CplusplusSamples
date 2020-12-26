#include<stdio.h>
#include<conio.h>
#include<math.h>
#define nMax 20
 
int x[nMax];
 
void print(int n, int stt,int x[nMax])
 
{ int i;
 
  printf("\n\nNghiem thu %d cua phuong trinh la: \n",stt); 
 
  for(i=1;i<=n;i++) printf("\tx%d = %d",i,x[i]);
 
}
 
int main()
 
{
      int i,j,t=0,stt=0,k,n,tong=0,m ;
      printf("giai phuong trinh n nghiem ko am co tong bang so duong k !!!\n");
      do{
           printf("Nhap n = "); scanf("%d",&n);
        } while( n < 0 );
   	  do{
           printf("Nhap k = "); scanf("%d",&k);
        } while( k < 0 );
      for(i=1; i<=n; i++) x[i]=0;
 
      while(t < pow( (float)k+1,n)){
 
            i=n;
			tong=0;
            while(x[i]==k) i--;
 
            x[i]++;
 
            for(j=i+1;j<=n;j++) x[j]=0;
 
            for(m = 1;m <= n;m ++) tong = tong + x[m];
 
            if (tong==k)
                {   
                    stt++;
                    print(n,stt,x);
				}
            
            t++;
 
      }
 
      printf("\n\nTong so nghiem cua phuong trinh la: %d",stt);
 
      getch();
 
}