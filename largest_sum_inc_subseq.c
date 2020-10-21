#include<stdio.h>
#include<stdlib.h>

int max_sum_inc_sub(int* arr,int n)
{
    int dp[n];
    
    for(int i=0;i<n;i++)
    {
        dp[i]=arr[i];
    }
    
    int max_sum=arr[0];
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j] && dp[i]<dp[j]+arr[i])
            {
                dp[i]=dp[j]+arr[i];
                
                if(max_sum < dp[i])
                {
                    max_sum=dp[i];
                }
            }
        }
    }
    
    return max_sum;
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
	    
	    printf("%d\n",max_sum_inc_sub(arr,n));
	}
	return 0;
}
