/*Given an array of integers and a sum, the task is to count all subsets of given array with sum equal to given sum.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an nteger n denoting the size of the array. The next line contains n space separated integers forming the array. The last line contains the sum.

Output:
Count all the subsets of given array with sum equal to given sum.

Constraints:
1<=T<=10^5
1<=n<=10^5
1<=a[i]<=10^5
1<=sum<=10^5

Example:
Input:
2
6
2 3 5 6 8 10
10
5
1 2 3 4 5
10

Output:
3
3*/
#include<stdio.h>
#include<stdlib.h>

int perfect_sum(int* set,int n,int sum)
{
    int dp[n][sum+1];
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            dp[i][j]=0;
        }
    }

    dp[0][set[0]]=1;
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(j<set[i])
            {
                dp[i][j]=dp[i-1][j];
            }
            else if(j==set[i])
            {
                dp[i][j]=dp[i-1][j]+1;
            }
            else//j>set[i]
            {
                dp[i][j]=dp[i-1][j]+dp[i-1][j-set[i]];
            }
        }
    }
    
    return dp[n-1][sum];
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
	    
	    int k;
	    scanf("%d",&k);
	    
	    printf("%d\n",perfect_sum(arr,n,k));
	}
	return 0;
}
