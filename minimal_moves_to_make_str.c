/*Given a string S, we need to write a program to check if it is possible to construct the given string S by performing any of the below operations any number of times. In each step, we can:

Add any character at the end of the string.
or, append the string to the string itself.
The above steps can be applied any number of times. We need to print the minimum steps required to form the string.

Input:
The first line contains an integer T, the number of test cases. For each test case, there is a string s which we need to form. 
Output:
For each test case, the output is an integer displaying the minimum number of steps required to form that string.

Constraints:
1<=T<=100
1<=s.length()<=10^5

Example:
Input
3
aaaaaaaa
aaaaaa
abcabca
Output
4
4
5

Explanation:
1.  move 1: add 'a' to form "a"
     move 2: add 'a' to form "aa"
     move 3: append "aa" to form "aaaa"
     move 4: append "aaaa" to form "aaaaaaaa"
2.  move 1: add 'a' to form "a"
     move 2: add 'a' to form "aa"
     move 3: add 'a' to form "aaa"
     move 4: append "aaa" to form "aaaaaa"
3.  move 1: add 'a' to form "a"
     move 2: add 'b' to form "ab"
     move 3: add 'c' to form "abc"
     move 4: append "abc" to form "abcabc"
     move 5: add 'a' to form "abcabca"*/
#include<stdio.h>
#include<string.h>

int str_match(char* str,int m)
{
    int t=m/2;
    
    while(t>=0)
    {
        if(str[t]!=str[m])
            return 0;
        t--;
        m--;
    }

    return 1;
}

int min_moves(char* str,int n)
{
    int dp[n+1];
    
    dp[0]=0;
    dp[1]=1;
    
    for(int i=2;i<=n;i++)
    {
        if(i%2)//odd
        {
            dp[i]=dp[i-1]+1;
        }
        else//even
        {
            if(str_match(str,i-1))
            {
                dp[i]=dp[i/2]+1;
            }
            else
            {
                dp[i]=dp[i-1]+1;
            }
        }
    }
    
    return dp[n];
}

int main() {
	
	int t;
	scanf("%d",&t);
	
	while(t--)
	{
	    char str[100001];
	    scanf("%s",str);
	    
	    int n;
	    n=strlen(str);
	    
	    printf("%d\n",min_moves(str,n));
	}
	
	return 0;
}
