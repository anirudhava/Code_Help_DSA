#include<stdio.h>
#include<stdlib.h>

int max(int x,int y)
{
    return x>y?x:y;
}

int max3(int x,int y,int z)
{
    return max(x,max(y,z));
}

int goldmine(int** a,int n,int m)
{
    int dp[n][m];
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            dp[i][j]=a[i][j];
        }
    }
    
    int max_v=a[0][0];
    
    for(int i=1;i<n;i++)
    {
        if(max_v < a[i][0])
        {
            max_v=a[i][0];
        }
    }
    
    for(int j=1;j<m;j++)
    {
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                if(n==1)
                {
                    dp[i][j]+=dp[i][j-1];
                }
                else
                    dp[i][j]+=max(dp[i][j-1],dp[i+1][j-1]);
            }
            else if(i==n-1)
            {
                dp[i][j]+=max(dp[i][j-1],dp[i-1][j-1]);
            }
            else
            {
                dp[i][j]+=max3(dp[i][j-1],dp[i-1][j-1],dp[i+1][j-1]);
            }
            
            if(max_v < dp[i][j])
            {
                max_v=dp[i][j];
            }
        }
    }
    
    return max_v;
    
}

int main() {
	
	int t;
	scanf("%d",&t);
	
	while(t--)
	{
	    int n;
	    int m;
	    
	    scanf("%d",&n);
	    scanf("%d",&m);
	    
	    int** a;
	    a=(int**)malloc(sizeof(int*)*n);
	    
	    for(int i=0;i<n;i++)
	    {
	        a[i]=(int*)malloc(sizeof(int)*m);
	    }
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            scanf("%d",&a[i][j]);
	        }
	    }
	    
	    printf("%d\n",goldmine(a,n,m));
	}
	return 0;
}
