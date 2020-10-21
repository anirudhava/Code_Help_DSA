/*
Input : arr[] = {1, 2, 3, 4}
Output: 15
There are total increasing subsequences
{1}, {2}, {3}, {4}, {1,2}, {1,3}, {1,4}, 
{2,3}, {2,4}, {3,4}, {1,2,3}, {1,2,4}, 
{1,3,4}, {2,3,4}, {1,2,3,4}

Input : arr[] = {4, 3, 6, 5}
Output: 8
Sub-sequences are {4}, {3}, {6}, {5}, 
{4,6}, {4,5}, {3,6}, {3,5}

Input : arr[] = {3, 2, 4, 5, 4}
Output : 14
Sub-sequences are {3}, {2}, {4}, {3,4},
{2,4}, {5}, {3,5}, {2,5}, {4,5}, {3,2,5}
{3,4,5}, {4}, {3,4}, {2,4}
*/

//https://www.youtube.com/watch?v=CE2b_-XfVDk

#include <stdio.h>
#include <stdlib.h>

int Longest_common_subsequence(int* arr,int n)
{
    int dp[n];
    
    for(int i=0;i<n;i++)
    {
        dp[i]=1;
    }
    
    int max=1;
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j] && dp[i]<dp[j]+1)
            {
                dp[i]=dp[j]+1;
                
                if(max<dp[i])
                {
                    max=dp[i];
                }
            }
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
	    
	    printf("%d\n",Longest_common_subsequence(arr,n));
	}
	return 0;
}