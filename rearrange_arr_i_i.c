/*Given an array of size N that has elements ranging from 0 to N-1. All elements may not be present in the array. If element is not present then there will be -1 present

in the array. Rearrange the array such that A[i] = i, and if i is not present, display -1 at that place.
2
10
-1 -1 6 1 9 3 2 -1 4 -1
20
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19

Output:
-1 1 2 3 4 -1 6 -1 -1 9
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19*/


//hashing---O(n) O(n)
//brute force---O(n^2) O(1)

#include<stdio.h>
#include<stdlib.h>

void rearrange(int* arr,int n)
{
    int freq[n];
    
    for(int i=0;i<n;i++)
        freq[i]=0;
    
    for(int i=0;i<n;i++)
    {
        if(arr[i]>-1)
            freq[arr[i]]+=1;
    }
    
    for(int i=0;i<n;i++)
    {
        if(freq[i]==0)
        {
            printf("%d ",-1);
        }
        else
        {
            printf("%d ",i);
        }
    }
    
    printf("\n");
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
	    
	    rearrange(arr,n);
	}
	return 0;
}
