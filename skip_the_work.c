/*Given an array A[ ] denoting the time taken to complete N tasks, determine the minimum amount of time required to finish the tasks considering that you can skip any task, but skipping two consecutive tasks is forbidden.
 

For example 
For the array arr [] = {10, 5, 2, 4, 8, 6, 7, 10}
the output will be  22  (Skip the tasks taking more time ,avoiding consective skipping(10,8,10). Tasks done in: 5+2+4+6+7)
 

Input
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
The first line of each test case contains a positve integer N, denoting the length of the array A[ ].
The second line of each test case contains a N space seprated positve integers, denoting the elements of the array A[ ].


Output
Print out the minimum time taken to complete the tasks.
 

Constraints
1 <= T <= 100
0 <   N <= 30
0 <= A[ ] <= 1000
 

Examples 

Input
4
4
10 5 7 10
6
5 6 7 8 9 10
2
10 20
5
22 10 15 3 5

Output
12
21
10
13


Expected Complexity
Time: O(N)
Space: O(1)*/

#include<stdio.h>
#include<stdlib.h>

int min(int x,int y)
{
    return x<y?x:y;
}

int skip_work(int* arr,int n)
{
    if(n==1)
        return 0;
        
    int dp[n];
    
    dp[0]=arr[0];
    dp[1]=min(arr[0],arr[1]);
    
    int t;
    t=arr[1];
    
    for(int i=2;i<n;i++)
    {
        if(t<dp[i-1]+arr[i])
        {
            dp[i]=t;
            t=dp[i-1]+arr[i];
        }
        else
        {
            dp[i]=dp[i-1]+arr[i];
            t=dp[i];
        }
    }
    
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
	    {
	        scanf("%d",&arr[i]);
	    }
	    
	    printf("%d\n",skip_work(arr,n));
	}
	return 0;
}
