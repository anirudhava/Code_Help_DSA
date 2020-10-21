/*Given a string, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. For example, “aba|b|bbabb|a|b|aba” is a palindrome partitioning of “ababbbabbababa”. Determine the fewest cuts needed for palindrome partitioning of a given string. For example, minimum 3 cuts are needed for “ababbbabbababa”. The three cuts are “a|babbbab|b|ababa”.

Input:
The first line of input contains an integer T, denoting the number of test cases. Then T test cases follow. The first line of every Test Case consists of S, denoting a String.

Output:
For each test case in a new line print an integer, denoting the number cuts in the String to make it palindromic.

Constraints:
1<=T<=100
1<=|Length of String|<=1000

Example:
Input:
2
ababbbabbababa
aaabba

Output:
3
1*/

#include <stdio.h>
#include <string.h>

int min_palin_cut(char* str,int n)
{
    int dp[n][n];
    
    for(int i=0;i<n;i++)
    {
        dp[i][i]=1;
    }
    
    for(int i=0;i<n-1;i++)
    {
        if(str[i]==str[i+1])
        {
            dp[i][i+1]=1;
        }
        else
        {
            dp[i][i+1]=0;
        }
    }
    
    for(int d=2;d<n;d++)
    {
        for(int i=0;i<n-d;i++)
        {
            int j=i+d;
            
            if(str[i]==str[j] && dp[i+1][j-1]==1)
            {
                dp[i][j]=1;
            }
            else
            {
                dp[i][j]=0;
            }
        }
    }
    
    int arr[n];
    
    int max=999999;
    
    for(int i=0;i<n;i++)
    {
        if(dp[0][i]==1)
        {
            arr[i]=0;
        }
        else
        {
            arr[i]=max;
            
            for(int j=0;j<i;j++)
            {
                if(dp[j+1][i]==1 && arr[j]+1 < arr[i])
                {
                    arr[i]=arr[j]+1;   
                }
            }
        }
    }
    
    return arr[n-1];
}

int main() {
	
	int t;
	scanf("%d",&t);
	
	while(t--)
	{
	    char str[10001];
	    scanf("%s",str);
	    
	    int n=strlen(str);
	    
	    printf("%d\n",min_palin_cut(str,n));
	}
	return 0;
}
