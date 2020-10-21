//O(n*m)->normal search
//O(n*log(m))->binary search on each row
//O(n+m)->this algo

#include<stdio.h>
#include<stdlib.h>

int is_present(int** a,int n,int m,int k)
{
    int pos_x=0;
    int pos_y=m-1;
    
    while(pos_x>=0 && pos_x<n && pos_y>=0 && pos_y<m)
    {
        if(a[pos_x][pos_y]==k)
        {
            return 1;   
        }
        else if(a[pos_x][pos_y] > k)
        {
            pos_y--;
        }
        else
        {
            pos_x++;
        }
    }
    
    return 0;
}

int main() {
	
	int t;
	scanf("%d",&t);
	
	while(t--)
	{
	    int n;
	    int m;
	    
	    scanf("%d",&n);
	    scanf("%d",&m);
	    
	    int**a;
	    a=(int**)malloc(sizeof(int*)*n);
	    
	    for(int i=0;i<n;i++)
	    {
	        a[i]=(int*)malloc(sizeof(int)*m);
	    }
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            scanf("%d",&a[i][j]);
	        }
	    }
	    
	    int k;
	    scanf("%d",&k);
	    
	    printf("%d\n",is_present(a,n,m,k));
	}
	return 0;
}
