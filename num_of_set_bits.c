#include <stdio.h>

int set_bits(int n)
{
    int c=0;
    
    while(n)
    {
        if(n%2==1)
            c++;
        n=n/2;
    }
    
    return c;

}

int main() {
	
	int t;
	scanf("%d",&t);
	
	while(t--)
	{
	    int n;
	    scanf("%d",&n);
	    
	    printf("%d\n",set_bits(n));
	}
	return 0;
}
