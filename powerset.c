#include<stdio.h>
#include<math.h>

int main()
{
  char set[3]={'a','b','c'};

  int size=3;

  int p=pow(2,size);

  for(int i=0;i<p;i++)
  {
	for(int j=0;j<size;j++)
	{
		if(i & 1<<j)
		{
			printf("%c",set[j]);
		}
	}
	printf("\n");
  }
  
}
