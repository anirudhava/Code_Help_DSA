/*Given two sorted arrays. There is only 1 difference between the arrays. First array has one element extra added in between. 
Find the index of the extra element.Input:

2
7
2 4 6 8 9 10 12
2 4 6 8 10 12
6
3 5 7 9 11 13
3 5 7 11 13
Output:
4
3*/
int Binary(int* a,int* b,int l,int h)
{
    
    while(l<h){
        
        int m=(l+h)/2;
        
        if(a[m-1]==b[m-1] && a[m]!=b[m])
        {
            return m;
        }
        
        else if(a[m]==b[m])
        {
            l=m+1;
        }
        
        else
        {
            h=m-1;
        }
    }
}

int findExtra(int a[],int b[],int n)
{
    return Binary(a,b,0,n-1);
}
