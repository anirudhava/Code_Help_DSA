/*
Given a number N, let the reverse of the number be R. The task is to print the output of the Expression pow(N,R), where pow function represents N raised to power R.
Note: As answers can be very large, print the result modulo 1000000007.
*/


#include <stdio.h>

/*long int Modular_exponentiation(long int x,long int y,int p)//(x^y)%p
{
     long int res=1;
    
    x=x % p;

    while(y>0)
    {
        if(y&1)//y is odd
        {
            res=(res*x)%p;
        }
        
        y=y/2;
        x=(x*x)%p;
    }
    
    return res;
}*/

long int power(long int x,long int y)
{
     long int res=1;
    
    while(y>0)
    {
        if(y&1)//y is odd
        {
            res=(res*x)%1000000007;
        }
        
        y=y/2;
        x=(x*x)%1000000007;
    }
    
    return res;
}

long int reverse_num(long int n)
{
    long int rev=0;
    int dig;
    
    while(n!=0)
    {
        dig=n%10;
        rev=(rev*10)+dig;
        n=n/10;
    }
    
    return rev;
}

int main() {
	
	int t;
	scanf("%d",&t);
	
	while(t--)
	{
	    long int n;
	    scanf("%ld",&n);
	    
	    long int rev;
	    rev=reverse_num(n);
	   
	    printf("%ld\n",power(n,rev));
	}
	return 0;
}
