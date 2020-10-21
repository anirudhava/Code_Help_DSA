/*Given an array A and an integer K. Find the maximum for each and every contiguous subarray of size K.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case contains a single integer N denoting the size of array and the size of subarray K. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print the maximum for every subarray of size k.

Constraints:
1 ≤ T ≤ 200
1 ≤ N ≤ 107
1 ≤ K ≤ N
0 ≤ A[i] <= 107

Example:
Input:
2
9 3
1 2 3 1 4 5 2 3 6
10 4
8 5 10 7 9 4 15 12 90 13

Output:
3 3 4 5 5 5 6
10 10 10 15 15 90 90*/

#include<stdio.h>
#include<stdlib.h>

int max_sliding(int* arr,int l,int h)
{
    int max=arr[l];
    
    for(int i=l+1;i<=h;i++)
    {
        if(max < arr[i])
            max=arr[i];
    }
    
    return max;
}

void max_window(int* arr,int n,int k)
{
    int max=max_sliding(arr,0,k-1);
    printf("%d ",max);
    
    for(int i=1;i<n-k+1;i++)
    {
        //printf("%d ",max_sliding(arr,i,i+k-1));--O(n*k)
        
        if(arr[i-1]==max)
        {
            max=max_sliding(arr,i,i+k-1);
        }
        else
        {
            if(arr[i+k-1]>max)
            {
                max=arr[i+k-1];
            }
        }
        printf("%d ",max);
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
        
        int k;
        scanf("%d",&k);
        
        int* arr;
        arr=(int*)malloc(sizeof(int)*n);
        
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        
        max_window(arr,n,k);
    }
	return 0;
}
