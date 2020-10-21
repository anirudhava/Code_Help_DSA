/*Given an array and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.*/
#include<stdio.h>
#include<stdlib.h>

int first_negative(int* arr,int l,int h)
{
    for(int i=l;i<=h;i++)
    {
        if(arr[i]<0)
        {
            return arr[i];
        }
    }
    
    return 0;
}

int func(int* arr,int n,int k)
{
    int l=0;
    int h=k-1;
    
    while(h<n)
    {
        printf("%d ",first_negative(arr,l,h));
        l++;
        h++;
    }
}

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
	    
	    int k;
	    scanf("%d",&k);
	    
	    func(arr,n,k);
	    
	    printf("\n");
	}
	return 0;
}
