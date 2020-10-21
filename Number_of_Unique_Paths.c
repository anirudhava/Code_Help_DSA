/*Given a M X N matrix with your initial position at top-left cell, find the number of possible unique paths to reach the bottom right cell of the matrix from the initial position.
Possible moves can be either down or right at any point in time*/

#include <stdio.h>

int ways(int n,int m)
{
    int dp[n][m];
    
    for(int i=0;i<n;i++)
        dp[i][0]=1;
    
    for(int i=0;i<m;i++)
        dp[0][i]=1;
    
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    
    return dp[n-1][m-1];
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
	    
	    printf("%d\n",ways(n,m));
	}
	return 0;
}
