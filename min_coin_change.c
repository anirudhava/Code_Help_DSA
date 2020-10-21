/*#include <iostream>
using namespace std;
#include <bits/stdc++.h>*/ 

#include<stdio.h>
#include<stdlib.h>

int min_coins(int* a,int n,int v)
{
    int dp[v+1];
    dp[0]=0;
    
   // sort(a,a+n);
    
    for(int i=1;i<=v;i++)
        dp[i]=v+1;
        
    for(int i=1;i<=v;i++)
    {
        int min=v+1;
        
        for(int j=0;j<n;j++)
        {
            if(i-a[j]>=0)
            {
                int x=dp[i-a[j]]+1;
                
                if(min > x)
                {
                    min=x;
                }
            }
        }
        
        dp[i]=min;
    }
    
    /*for(int i=0;i<=v;i++)
        printf("%d ",dp[i]);
    printf("\n");*/
    if(dp[v]>=v+1)
        return -1;
    return dp[v];
}

int main() {
	
	int t;
	scanf("%d",&t);
	
	while(t--)
	{
	    int v;
	    scanf("%d",&v);
	    
	    int n;
	    scanf("%d",&n);
	    
	    int*a;
	    a=(int*)malloc(sizeof(int)*n);
	    
	    for(int i=0;i<n;i++)
	        scanf("%d",&a[i]);
	        
	  printf("%d\n",min_coins(a,n,v));
	}
	return 0;
}
