/*Given a collection of Intervals,merge all the overlapping Intervals.
For example:

Given [1,3], [2,6], [8,10], [15,18],

return [1,6], [8,10], [15,18].

Make sure the returned intervals are sorted.
Input
2
4
1 3 2 4 6 8 9 10
4
6 8 1 9 2 4 4 7

Output
1 4 6 8 9 10
1 9*/

#include<stdio.h>
#include<stdlib.h>

struct Data
{
    int f;
    int s;
};

int compare (const void *a, const void * b) 
{  
    struct Data* p;
    struct Data* q;
    
    p=(struct Data*)a;
    q=(struct Data*)b;
    
    return p->f - q->f;
}

void merge_print(struct Data* d,int n)
{
    qsort(d,n,sizeof(d[0]),compare);
    
    /*for(int i=0;i<n;i++)
    {
        printf("%d %d ",d[i].f,d[i].s);
    }
    printf("\n");*/
    int f_t=d[0].f;
    int s_t=d[0].s;
    
    for(int i=1;i<n;i++)
    {
        if(s_t > d[i].s)
        {
            ;
        }
        
        else if(s_t >= d[i].f)
        {
            s_t=d[i].s;
        }
        else
        {
            //print
            printf("%d %d ",f_t,s_t);
            //change ptr
            f_t=d[i].f;
            s_t=d[i].s;
        }
    }
    
    printf("%d %d\n",f_t,s_t);
}

int main() {
    
    int t;
    scanf("%d",&t);
    
    while(t--)
    {
        int n;
        scanf("%d",&n);
        
        struct Data* d;
        d=(struct Data*)malloc(sizeof(struct Data)*n);
        
        for(int i=0;i<n;i++)
        {
            scanf("%d",&(d[i].f));
            scanf("%d",&(d[i].s));
        }
        
        merge_print(d,n);
    }
	return 0;
}
