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


void disp(int* arr,int n)
{
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}

int abs(int x)
{
	if(x<0)
		return -x;
	else
		return x;
}

int min_diff(int* arr1,int n1,int* arr2,int n2)
{
	sort(arr1,0,n1-1);
	
	//disp(arr1,n1);

	sort(arr2,0,n2-1);
	
	//disp(arr2,n2);

	int i=0;
	int j=0;
	
	int min=9999999;

	while(i<=n1 && j<=n2)
	{
		if(min > abs(arr1[i]-arr2[j]))
		{
			min=abs(arr1[i]-arr2[j]);
		}

		if(arr1[i]>arr2[j])
		{
			j++;
		}
		else
		{
			i++;
		}		
	}

	return min;
}

int main() {
	
	int t;
	scanf("%d",&t);
	
	while(t--)
	{
	    int n1;
	    scanf("%d",&n1);

	    int n2;
	    scanf("%d",&n2);
	    
	    int* arr1;
	    arr1=(int*)malloc(sizeof(int)*n1);
	    
	    int* arr2;
	    arr2=(int*)malloc(sizeof(int)*n2);
	    
	    for(int i=0;i<n1;i++)
	        scanf("%d",&arr1[i]);
	    
	    for(int i=0;i<n2;i++)
	        scanf("%d",&arr2[i]);
	        
	    printf("%d\n",min_diff(arr1,n1,arr2,n2));
	    
	}
	return 0;
}

