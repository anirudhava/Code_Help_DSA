int find_right_most(int* arr,int x,int ind,int n)
{
    for(int i=n-1;i>=ind;i--)
    {
        if(arr[i]==x)
        {
            return i;
        }
    }
}

int maxDistance(int arr[], int n)
{
    int visited[10001]={0};
   
    int max_dist=-1;
   
    for(int i=0;i<n;i++)
    {
        if(visited[arr[i]]==0){
            int pos=find_right_most(arr,arr[i],i,n);
            visited[arr[i]]=1;  
           
            if(max_dist < pos-i)
            {
                max_dist=pos-i;
            }
        }
    }
   
    return max_dist;
}


