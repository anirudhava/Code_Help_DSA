#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int triplets(int* arr,int n,int x)
{
    int c=0;
    
    sort(arr,arr+n);
    
    for(int i=0;i<n-2;i++)
    {
        int l=i+1;
            
        int h=n-1;
        
        while(l<h)
        {
            int s=arr[i]+arr[l]+arr[h];
            
            if(s==x)
            {
                c++;
                
                l++;
            }
            else if(s<x)
            {
                l++;
            }
            else
            {
                h--;
            }
        }
    }
    
    return c;
}

int main() {
	
	int t;
	scanf("%d",&t);
	
	while(t--)
	{
	    int n;
	    scanf("%d",&n);
	    
	    int x;
	    scanf("%d",&x);
	    
	    int* arr;
	    arr=(int*)malloc(sizeof(int)*n);
	    
	    for(int i=0;i<n;i++)
	        scanf("%d",&arr[i]);
	        
	    printf("%d\n",triplets(arr,n,x));
	    
	}
	return 0;
}

