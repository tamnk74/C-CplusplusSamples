?#?include?<conio.h>
#include<stdio.h>
#include<string.h>
int count=1,n;
void nhap(int *a)
{
int i;
for(i=1;i<=n;i++) a[i]=i;
}
void xuat(int a[])
{
int i;
printf("\n %2d \t",count);
count++;
for(i=1;i<=n;i++)
printf("%d",a[i]);
}
int kt(int a[])
{
int i;
for(i=1;i<=n-1;i++) if(a[i]>a[i+1]) return 0;
return 1;
}
void next(int a[])
{
int i,j,l,k,t;
i=n-1;
j=n;
while(i>=1&&(a[i]>a[i+1]))i--;
while(a[j]<a[i])j--;
t=a[i];
a[i]=a[j];
a[j]=t;
l=i+1;
k=n;
while(l<k)
{
t=a[l];
a[l]=a[k];
a[n]=t;
l++;k--;
}
}
int main ()
{
int a[20],c;
printf("nhap n:");
scanf("%d",&n);
nhap(a);
printf("hoan vi la:");
xuat(a);
c=kt(a);
while(c==1)
{
next(a);
xuat(a);
c=kt(a);
}
getch();
return 1;
}