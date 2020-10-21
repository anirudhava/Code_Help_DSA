/*You are given N pairs of numbers. In every pair, the first number is always smaller than the second number. A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion. Your task is to complete the function maxChainLen which returns an integer denoting the longest chain which can be formed from a given set of pairs. 

Input:
The first line of input contains an integer T denoting the no of test cases then T test cases follow .Then T test cases follow . The first line of input contains an integer N denoting the no of pairs . In the next line are 2*N space separated values denoting N pairs.

Output:
For each test case output will be the length of the longest chain formed.

Constraints:
1<=T<=100
1<=N<=100

Example(To be used only for expected output):
Input
2
5
5  24 39 60 15 28 27 40 50 90
2
5 10 1 11 

Output
3
1
Explanation
(i) the given pairs are {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} },the longest chain that can be formed is of length 3, and the chain is {{5, 24}, {27, 40}, {50, 90}}
(ii) The max length chain possible is only of length one.*/

void merge(struct val* arr,int l,int m,int h)
{
	int i=l;
	int j=m+1;
	int k=0;
	struct val b[h-l+1];

	while(i<=m && j<=h)
	{
		if(arr[i].first<arr[j].first)
		{
			b[k++]=arr[i++];
		}
		else
		{
			b[k++]=arr[j++];
		}
	}

	for(;i<=m;i++)
	{
		b[k++]=arr[i];
	}

	for(;j<=h;j++)
	{
		b[k++]=arr[j];
	}

	int x=0;

	for(;x<k;x++)
	{
		arr[l++]=b[x];
	}
}

void sort(struct val* arr,int l,int h)
{
	if(l<h)
	{
		int m=(l+h)/2;
	
		sort(arr,l,m);

		sort(arr,m+1,h);

		merge(arr,l,m,h);	
	}
}

int maxChainLen(struct val p[],int n)
{
    sort(p,0,n-1);
    int dp[n];
    
    for(int i=0;i<n;i++)
    {
        dp[i]=1;
    }
    
    int max=1;
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(p[j].second < p[i].first && dp[i]<dp[j]+1)
            {
                dp[i]=dp[j]+1;
                
                if(max < dp[i])
                {
                    max=dp[i];
                }
            }
        }
    }

    return max;
}
