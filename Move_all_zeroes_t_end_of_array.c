#include<stdio.h>
#include<stdlib.h>

int count_zero(int* arr,int n)
{
    int c=0;
    
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        {
            c++;
        }
    }
    
    return c;
}

void shift(int* arr,int n,int x)
{
    int e=arr[x];
    
    for(int i=x+1;i<n;i++)
    {
        arr[i-1]=arr[i];
    }
    
    arr[n-1]=e;
}

void last_zeros(int* arr,int n)
{
    int c=count_zero(arr,n);
    
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        {
            shift(arr,n,i);
            c--;
            i--;//******************************remember**************************************
        }
        if(c==0)
            return;
    }
}

void disp(int* arr,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    
    printf("\n");
}

int main() {

    int t;
    scanf("%d",&t);

    while(t--)
    {
        int n;
        scanf("%d",&n);
        
        int*arr;
        arr=(int*)malloc(sizeof(int)*n);
        
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        
        last_zeros(arr,n);
        
        disp(arr,n);
        
    }
	return 0;
}
