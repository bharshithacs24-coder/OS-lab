#include<stdio.h>
int main()
{
    int i,j,r,c,sum=0;
    printf("enter the row and column size");
    scanf("%d %d",&r,&c);
    int arr[r][c];
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    
    for(i=0;i<r;i++)
    {
        sum=0;
        for(j=0;j<c;j++)
        {
            sum+=arr[i][j];
        }
        printf("row sum=%d",sum);
    }
    
    for(j=0;j<c;j++)
    {
        sum=0;
        for(i=0;i<r;i++)
        {
            sum+=arr[i][j];
        }
        printf("column sum=%d",sum);
    }
    return 0;

}