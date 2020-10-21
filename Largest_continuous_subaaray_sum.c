#include<stdio.h>
#include<stdlib.h>

int kadane(int* arr,int n)
{
  int max_so_far;
  int max_end_here=0;
  int strt=0;
  int end=0;
  int s=0;

  max_so_far=arr[0];

  for(int i=0;i<n;i++)
  {
	max_end_here= max_end_here + arr[i];

	if(max_so_far < max_end_here)
	{
		max_so_far=max_end_here;
		strt=s;
		end=i;
	}
	if(max_end_here<0)
	{
		max_end_here=0;
		s=i+1;
	}
  }

  printf("strt: %d   end: %d\n",strt,end);
  
  return max_so_far;
}

int main() {

    int t;
    scanf("%d",&t);
    
    while(t--)
    {
        int n;
        scanf("%d",&n);
        
        int*arr;
        arr=(int*)malloc(sizeof(int)*n);
        
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        
        printf("%d\n",kadane(arr,n));
    }
	return 0;
}
