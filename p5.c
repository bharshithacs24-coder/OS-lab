#include<stdio.h>
int main()
{
    int n,i,pos;
    printf("enter the arr size");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("enter the position ");
    scanf("%d",&pos);
    for(i=pos-1;i<n-1;i++)
    {
        arr[i]=arr[i+1];
    }
    for(i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
    return 0;
}