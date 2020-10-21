int *mergeKArrays(int arr[][N], int k)
{
    int a[k]={0};//ind
    
    //int res[k*k];
    
    int*res;
    res=(int*)malloc(sizeof(int)*(k*k));
    
    int ind=0;
    
    int pos_x;
    int pos_y;
    
    for(int iter=0;iter<k*k;iter++)
    {
        int min=INT_MAX;
        
        for(int i=0;i<k;i++)//check for smallest
        {
            if(a[i]<k && min > arr[i][a[i]])
            {
                min=arr[i][a[i]];
                pos_x=i;
                pos_y=a[i];
            }
        }
        
        res[ind++]=arr[pos_x][pos_y];
        a[pos_x]+=1;
    }
    
    return res;
}
