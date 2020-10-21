#include<stdio.h>
#include<stdlib.h>

int max;
int c;

int dfs(int** a,int x,int y,int n,int m)
{
    if(x<0 || y<0 || x>=n || y>=m || a[x][y]==0)
        return 0;
    
    a[x][y]=0;
    c++;
    
    dfs(a,x+1,y,n,m);
    dfs(a,x-1,y,n,m);
    dfs(a,x,y+1,n,m);
    dfs(a,x,y-1,n,m);
    
    dfs(a,x+1,y+1,n,m);
    dfs(a,x+1,y-1,n,m);
    dfs(a,x-1,y-1,n,m);
    dfs(a,x-1,y+1,n,m);
    
    return c;
}

int largest_area(int** a,int n,int m)
{
    max=-1;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]==1)
            {
                c=dfs(a,i,j,n,m);
                
                if(max < c)
                    max=c;
                c=0;
            }
        }
    }
    
    return max;
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
        
        printf("%d\n",largest_area(a,n,m));
	}
	return 0;
}
