/*Given a number N. You need to write a program to print the minimum number of squares of this number that sums to N. For Example: If N = 100 , N can be expressed as (10*10) and also as (5*5 + 5*5 + 5*5 + 5*5) but the output will be 1 as minimum number of square is 1 , i.e (10*10).*/

#include <stdio.h>

int min(int x,int y)
{
    return x<y?x:y;
}

int min_sum_sq(int n)
{
    int dp[n+1];
    
    dp[0]=0;
    dp[1]=1;
    
    for(int i=2;i<=n;i++)
    {
        //int x=(int)floor(sqrt(i));
        
        //dp[i]=dp[i-x*x]+1;//doesnt work for 75
        
        dp[i]=i;//1*1 i times to form i
        
        for(int j=1;j*j<=i;j++)//checking for others smaller numbers also
        {
            dp[i]=min(dp[i],dp[i-j*j]+1);
        }
    }
    
    return dp[n];
}

int main() {
	
	int t;
	scanf("%d",&t);
	
	while(t--)
	{
	    int n;
	    scanf("%d",&n);
	    
	    printf("%d\n",min_sum_sq(n));
	}
	return 0;
}
