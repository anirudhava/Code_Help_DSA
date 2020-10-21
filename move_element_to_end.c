#include <stdio.h>

void shift(int* arr,int x,int n)
{
    int t=arr[x];
    
    for(int i=x;i<n-1;i++)
    {
        arr[i]=arr[i+1];
    }
    
    arr[n-1]=t;
}

int count_negative(int* arr,int n)
{
    int c=0;
    
    for(int i=0;i<n;i++)
    {
        if(arr[i]<0)
            c++;
    }
    
    return c;
}

void rearrange(int* arr,int n)
{
    int cn=count_negative(arr,n);
    
    //printf("..%d..\n",cn);
    
    int x=0;
    
    for(int i=0;i<n;i++)
    {
        if(arr[i]<0)
        {
            shift(arr,i,n);
            //disp(arr,n);
            x++;
            i--;
        }
        
        if(x==cn)
            break;
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
	    
	    int arr[n];
	    
	    for(int i=0;i<n;i++)
	    {
	        scanf("%d",&arr[i]);
	    }
	    
	    rearrange(arr,n);
	    
	    disp(arr,n);
	}
	return 0;
}
