/*

10
100 56 5 6 102 58 101 57 7 103 

{5, 6, 7}, { 56, 57, 58, 59}, {100, 101, 102, 103} are 3 subset in which numbers are consecutive.
*/
#include<stdio.h>
#include<stdlib.h>

void merge(int* arr,int l,int m,int h)
{
	int i=l;
	int j=m+1;
	int k=0;
	int b[h-l+1];

	while(i<=m && j<=h)
	{
		if(arr[i]<arr[j])
		{
			b[k++]=arr[i++];
		}
		else
		{
			b[k++]=arr[j++];
		}
	}

	for(;i<=m;i++)
	{
		b[k++]=arr[i];
	}

	for(;j<=h;j++)
	{
		b[k++]=arr[j];
	}

	int x=0;

	for(;x<k;x++)
	{
		arr[l++]=b[x];
	}
}

void sort(int* arr,int l,int h)
{
	if(l<h)
	{
		int m=(l+h)/2;
	
		sort(arr,l,m);

		sort(arr,m+1,h);

		merge(arr,l,m,h);	
	}
}

int min_subsets_consec_elem(int*arr,int n)
{
    sort(arr,0,n-1);
    
    int c=0;
    
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]+1==arr[i+1])
        {
            ;
        }
        else
        {
            c++;
        }
    }
    
    return c+1;
}

int main() 
{
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
        
        printf("%d\n",min_subsets_consec_elem(arr,n));
    }
	return 0;
}
