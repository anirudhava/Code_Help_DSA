/*Consider a big party where a log register for guest’s entry and exit times is maintained. Find the time at which there are maximum guests in the party. Note that entries in register are not in any order.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer n denoting the size of the entry and exit array. Then the next two line contains the entry and exit array respectively.

Output:
Print the maximum no of guests and the time at which there are maximum guests in the party.

Constraints:
1<=T<=10^5
1<=N<=10^5
1<=entry[i],exit[i]<=10^5

Example:
Input:
2
5
1 2 10 5 5
4 5 12 9 12
7
13 28 29 14 40 17 3 
107 95 111 105 70 127 74 

Output:
3 5
7 40*/

#include<stdio.h>
#include<stdlib.h>

struct Data
{
    int entry;
    int exit;
};

int compare(const void* a,const void* b)
{
    struct Data* x;
    struct Data* y;
    
    x=(struct Data*)a;
    y=(struct Data*)b;
    
    return x->entry-y->entry;
}

void find_max_ppl_time(struct Data* arr,int n)
{
    qsort(arr,n,sizeof(arr[0]),compare);
    
    /*for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i].entry);
    }
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i].exit);
    }
    printf("\n");*/
    
    int l=0;
    int h=0;
    
    int ppl=0;
    int max=0;
    int time=0;
    
    while(l<n)
    {
        if(arr[l].entry<=arr[h].exit)
        {
            ppl++;
            
            if(max<ppl)
            {
                max=ppl;
                time=arr[l].entry;
            }
            l++;
        }
        else
        {
            h++;
            ppl--;
        }
    }
    
    printf("%d %d\n",max,time);
}

int main() {
	
	int t;
	scanf("%d",&t);
	
	while(t--)
	{
        int n;
        scanf("%d",&n);
            
        struct Data* arr;
        arr=(struct Data*)malloc(sizeof(struct Data)*n);
        
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i].entry);
        }
        
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i].exit);
        }
        
        find_max_ppl_time(arr,n);
	}
	return 0;
}
