#include<stdio.h>
#include<stdlib.h>

int max(int x,int y)
{
    return x>y?x:y;
}

int max_money(int* arr,int n)
{
   /* int sum_odd=0;
    int sum_even=0;
    
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            sum_even+=arr[i];
        }
        else
        {
            sum_odd+=arr[i];
        }
    }
    
    return (sum_odd>sum_even)?sum_odd:sum_even;
    
    gives wrongg answer for some test cases*/
    
    int dp[n];
    
    dp[0]=arr[0];
    
    dp[1]=max(arr[0],arr[1]);
    
    for(int i=2;i<n;i++)
    {
        int x=arr[i]+dp[i-2];
        int y=dp[i-1];
        
        dp[i]=max(x,y);
    }
    
    return dp[n-1];
    
}

//#include<stdlib.h>
int main() {

    int t;
    scanf("%d",&t);
    
    while(t--)
    {
        int n;
        scanf("%d",&n);
        
        int*arr;
        arr=(int*)malloc(sizeof(int)*n);
        
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        
        printf("%d\n",max_money(arr,n));
    }
	return 0;
}
