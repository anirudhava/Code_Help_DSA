/*Sorting Elements of an Array by Frequency
Given an array A[] of integers, sort the array according to frequency of elements. That is elements that have higher frequency come first. If frequencies of two elements are same, then smaller number comes first.
*/
 
int get_next_max(int* arr)
{
    int max=INT_MIN;
    int pos=-1;
    
    for(int i=0;i<61;i++)
    {
        if(max < arr[i])
        {
            max=arr[i];
            pos=i;
        }
    }

    return pos;
}

void sortByFreq(int arr[],int n)
{
    int freq[61]={0};
    
    for(int i=0;i<n;i++)
    {
        freq[arr[i]]+=1;
    }
    
    int b[n];
    
    int k=0;
    
    for(int i=0;i<n;i++)
    {
        int x=get_next_max(freq);
        
        while(freq[x]!=0)
        {
            b[k++]=x;
            freq[x]--;
        }
    }
    
    for(int i=0;i<n;i++)
    {
        arr[i]=b[i];
    }
    
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
