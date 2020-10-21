#include<stdio.h>
#include<stdlib.h>

void print_arr(int* arr,int h)
{
	
	for(int i=0;i<=h;i++)
	{	
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void swap(int* arr,int x,int y)
{
	int t;
	
	t=arr[x];
	arr[x]=arr[y];
	arr[y]=t;
}

void permutations(int* arr,int l,int h)
{
	int i;
	for(i=l;i<=h;i++)
	{
		swap(arr,l,i);
		permutations(arr,l+1,h);
		swap(arr,l,i);
	}
	if(l==h+1)
	{
		print_arr(arr,h);
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
        
        permutations(arr,0,n-1);
    }
	return 0;
}
