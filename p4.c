#include<stdio.h>
int main()
{
   int i,j,n,count=0;
   printf("enter n");
   scanf("%d",&n);
   int arr[n];
   for(i=0;i<n;i++)
   {
    scanf("%d",&arr[i]);
   }
   for(i=0;i<n;i++)
   {
    for(j=i+1;j<n;j++)
    {
        if(arr[i]==arr[j])
        {
           count+=1;
           break;
        }
          
    }
   } 
    printf("no. of duplicate number is %d",count); 
    
    return 0;
}