#include<stdio.h>
#include<stdlib.h>

int Longest_bitonic(int* arr,int n)
{
    int lis[n];
    
    for(int i=0;i<n;i++)
    {
        lis[i]=1;
    }
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j] && lis[i] < lis[j]+1)
            {
                lis[i]=lis[j]+1;
            }
        }
    }
    
    int lds[n];
    
    for(int i=0;i<n;i++)
    {
        lds[i]=1;
    }
    
    for(int i=n-2;i>=0;i--)
    {
        for(int j=n-1;j>i;j--)
        {
            if(arr[i]>arr[j] && lds[i] < lds[j]+1)
            {
                lds[i]=lds[j]+1;
            }
        }
    }
    
    int max=lis[0]+lds[0]-1;
    
    for(int i=1;i<n;i++)
    {
        if(max < lis[i]+lds[i]-1)
        {
            max=lis[i]+lds[i]-1;
        }
    }
    
    return max;
}

int main() {
	
	int t;
	scanf("%d",&t);
	
	while(t--)
	{
	    int n;
	    scanf("%d",&n);
	    
	    int* arr;
	    arr=(int*)malloc(sizeof(int)*n);
	    
	    for(int i=0;i<n;i++)
	    {
	        scanf("%d",&arr[i]);
	    }
	    
	    printf("%d\n",Longest_bitonic(arr,n));
	}
	return 0;
}
