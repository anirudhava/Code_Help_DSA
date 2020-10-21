/*
Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1′ into ‘str2′.

    Insert
    Remove
    Replace

All of the above operations are of cost=1.
Both the strings are of lowercase.
*/

#include<stdio.h>
#include<stdlib.h>

int min(int x,int y)
{
    return (x<y)?x:y;
}

int min3(int x,int y,int z)
{
    return min(min(x,y),z);
}

int min_change(char* str1,int n1,char* str2,int n2)
{
    int dp[n1+1][n2+1];
    
    for(int i=0;i<=n1;i++)
    {
        dp[i][0]=i;
    }
    
    for(int i=0;i<=n2;i++)
    {
        dp[0][i]=i;
    }
    
    for(int i=1;i<=n1;i++)
    {
        for(int j=1;j<=n2;j++)
        {
            if(str1[i-1]==str2[j-1])
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=min3(dp[i-1][j-1],dp[i-1][j],dp[i][j-1])+1;
            }
        }
    }
    
    return dp[n1][n2];
}
int main() {
	
	int t;
	scanf("%d",&t);
	
	while(t--)
	{
	    int n1;
	    int n2;
	    
	    scanf("%d",&n1);
	    scanf("%d",&n2);
	    
	    char str1[100];
	    char str2[100];
	    
	    scanf("%s",str1);
	    scanf("%s",str2);
	    
	    printf("%d\n",min_change(str1,n1,str2,n2));
	}
	return 0;
}
