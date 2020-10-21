int dfs(vector<int> a[],int x,int y,int n,int m)//c++
{
    if(x<0 || y<0 || x>=n || y>=m || a[x][y]==0)
        return 0;
    
    a[x][y]=0;
    
    dfs(a,x+1,y,n,m);
    dfs(a,x-1,y,n,m);
    dfs(a,x,y-1,n,m);
    dfs(a,x,y+1,n,m);
    
    dfs(a,x+1,y+1,n,m);
    dfs(a,x-1,y-1,n,m);
    dfs(a,x+1,y-1,n,m);
    dfs(a,x-1,y+1,n,m);
    
    return 1;
}

int findIslands(vector<int> a[], int n, int m)
{
    int ans=0;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]==1)
            {
                ans+=dfs(a,i,j,n,m);
            }
        }
    }
    
    return ans;
}

