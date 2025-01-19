#include<stdio.h>
#include<conio.h>
 
 void main ()    
{
    int a[100],i,j,k,n,temp;
    clrscr();  
    printf("Enter size of on array\n");
    scanf("%d",&n);
    printf("Enter any %d integer elements of an array\n",n);
    for(i = 0; i < n; i++)
    {
	scanf("%d",&a[i]);
    }

   for(k=1;k<n;k++)
      {
       temp=a[k];
       j=k-1;
       while((temp<a[j])&&(j>=0))
            {
		a[j+1]=a[j];
		j=j-1;
            } 
	a[j+1]=temp;
      }
    printf("Array Element after sorting\n");
    for(i = 0; i < n; i++)
    {    
	printf("%d  ",a[i]);
    }      
getch();
}
