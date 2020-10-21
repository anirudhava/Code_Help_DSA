#include<stdio.h>
#include<stdlib.h>

/*Given an array of integers where each element represents the max number of steps that can be made forward from that element. The task is to find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then cannot move through that element.

Input: 
The first line contains an integer T, depicting total number of test cases.  Then following T lines contains a number n denoting the size of the array. Next line contains the sequence of integers a1, a2, ..., an.

Output:
For each testcase, in a new line, print the minimum number of jumps. If answer is not possible print "-1"(without quotes).

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 107
0 <= ai <= 107

Example:
Input:
2
11
1 3 5 8 9 2 6 7 6 8 9
6
1 4 3 2 6 7
Output:
3
2

Explanation:
Testcase 1: First jump from 1st element, and we jump to 2nd element with value 3. Now, from here we jump to 5h element with value 9. and from here we will jump to last.*/

int min_jumps_to_end(int* arr,int n)
{
    int dp[n+1];
    
    dp[0]=0;
    
    int flag=0;
    
    for(int i=1;i<n;i++)
    {
        dp[i]=-1;
        flag=0;
        
        for(int j=0;j<i;j++)
        {
            if(j+arr[j]>=i)
            {
                dp[i]=dp[j]+1;
                flag=1;
                break;
            }
        }
        
        if(flag==0)
            return -1;
    }
    
    /*for(int i=0;i<n;i++)
        printf("%d ",dp[i]);
    printf("\n");*/
    return dp[n-1];
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
	        scanf("%d",&arr[i]);
	        
	    printf("%d\n",min_jumps_to_end(arr,n));
	}
	return 0;
}
