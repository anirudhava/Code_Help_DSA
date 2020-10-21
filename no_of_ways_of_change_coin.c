#include<stdio.h>
#include<stdlib.h>

int all_possible_ways(int* a,int n,int x)
{
    int dp[x+1];
    dp[0]=1;
    
    for(int i=1;i<=x;i++)
        dp[i]=0;
    
    for(int i=0;i<n;i++)
    {
        for(int j=a[i];j<=x;j++)
        {
            dp[j]+=dp[j-a[i]];   
        }
    }
    
    return dp[x];
}

int main() {
	
	int t;
	scanf("%d",&t);
	
	while(t--)
	{
	    int n;
	    scanf("%d",&n);
	    
	    int*a;
	    a=(int*)malloc(sizeof(int)*n);
	    
	    for(int i=0;i<n;i++)
	        scanf("%d",&a[i]);
	   
	    int x;
	    scanf("%d",&x);
	    
	    printf("%d\n",all_possible_ways(a,n,x));
	}
	return 0;
}
