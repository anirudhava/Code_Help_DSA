#include<stdio.h>
#include<stdlib.h>

void transpose(int** a,int n)
{
    for(int i=0;i<n-1;i++)//row
    {
        for(int j=i+1;j<n;j++)
        {
            int t;
            
            t=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=t;
        }
    }
}

void rotate_90(int** a,int n)
{
    transpose(a,n);
    
    int l=0;
    int h=n-1;
    
    while(l<h)
    {
        for(int i=0;i<n;i++)
        {
            int t;
            
            t=a[i][l];
            a[i][l]=a[i][h];
            a[i][h]=t;
        }
        
        l++;
        h--;
    }

}

void disp(int** a,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
    }
}

int main() {
	
    int t;
    scanf("%d",&t);
    
    while(t--)
    {
        int n;
        scanf("%d",&n);
        
        int**a;
        a=(int**)malloc(sizeof(int*)*n);
        
        for(int i=0;i<n;i++)
        {
            a[i]=(int*)malloc(sizeof(int)*n);
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        
        rotate_90(a,n);
        
        disp(a,n);
    }
	return 0;
}
