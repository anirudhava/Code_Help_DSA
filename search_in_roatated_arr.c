/*Given a sorted and rotated array A of N distinct elements which is rotated at some point, and given an element K. The task is to find the index of the given element K in the array A.

Input:
The first line of the input contains an integer T, denoting the total number of test cases. Then T test cases follow. Each test case consists of three lines. First line of each test case contains an integer N denoting the size of the given array. Second line of each test case contains N space separated integers denoting the elements of the array A. Third line of each test case contains an integer K denoting the element to be searched in the array.

Output:
Corresponding to each test case, output the index of the element found in the array.  If element is not present, then output -1.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 107
0 ≤ Ai ≤ 108
1 ≤ K ≤ 108

Example:
Input:
3
9
5 6 7 8 9 10 1 2 3
10
3
3 1 2
1
4
3 5 1 2
6

Output:
5
1
-1

Explanation:
Testcase 1: 10 is found at index 5.*/

#include <stdio.h>
#include <stdlib.h>

int get_pivot(int* arr,int l,int h)
{
    // solve
    
    int m;
    m=(l+h)/2;
    
    if(arr[m]>arr[m+1])
    {
        return m;
    }
    
    if(arr[m-1]>arr[m])
    {
        return m-1;
    }
    
    if(arr[h]<arr[m])
    {
        return get_pivot(arr,m+1,h); 
    }
    
    if(arr[l]>arr[m])
    {
        return get_pivot(arr,l,m-1); 
    }
}

int binary_search(int* arr,int l,int h,int k)
{
    if(l>h)
        return -1;
   
    int m=(l+h)/2;
   
    if(arr[m]==k)
    {
        return m;
    }
   
    else if(arr[m]>k)
    {
        return binary_search(arr,l,m-1,k);
    }
   
    else
    {
        return binary_search(arr,m+1,h,k);
    }
}

int get_ind(int* arr,int n,int k)
{
    int x=get_pivot(arr,0,n-1);
   
    if(x==-1)//there is no pivot => arr is sorted
    {
        return binary_search(arr,0,n-1,k);// logn
    }
   
    if(arr[x]==k)
    {
        return x;
    }
    
    // solve  
    
    if(k>=arr[0] && k<arr[x])
    {
        return binary_search(arr,0,x-1,k);
    }
    else
    {
        return binary_search(arr,x+1,n-1,k);
    }
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
       
       int k;
       scanf("%d",&k);
       
       printf("%d\n",get_ind(arr,n,k));
    }
    return 0;
}
