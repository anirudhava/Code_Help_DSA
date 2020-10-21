/*
Given an array A of size n of integers in the range from 1 to n, we need to find the inverse permutation of that array.
Inverse Permutation is a permutation which you will get by inserting position of an element at the position specified by the element value in the array. 
For better understanding, consider the following example:
Suppose we found element 4 at position 3 in an array, then in reverse permutation, we insert 3 (position of element 4 in the array) in position 4
(element value).

ex:
2 3 4 5 1
ans:5 1 2 3 4
*/
#include<stdio.h>
#include<stdlib.h>

void inv_permute(int* arr,int n)
{
    int b[n];
    
    for(int i=0;i<n;i++)
    {
        b[arr[i]-1]=i+1;
    }
    
    for(int i=0;i<n;i++)
    {
        arr[i]=b[i];
    }
}

void disp(int* arr,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
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
        
        int*arr;
        arr=(int*)malloc(sizeof(int)*n);
        
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        
        inv_permute(arr,n);
        
        disp(arr,n);
    }
	return 0;
}
