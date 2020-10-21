/*Consider a rat placed at (0, 0) in a square matrix m[][] of order n and has to reach the destination at (n-1, n-1). Your task is to complete the function printPath() which returns a sorted array of strings denoting all the possible directions which the rat can take to reach the destination at (n-1, n-1). The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right).

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines. The first line contains an integer n denoting the size of the square matrix. The next line contains n*n space separated values of the matrix m where 0's represents blocked paths and 1 represent valid paths.

Output:
For each test case output will be space separated sorted strings denoting all directions, which the rat could take to reach the destination.

User Task:
Since this is functional problem you don't have to worry about input, you just have to complete the function printPath()

Constraints:
1 <= T <= 10
2 <= n <= 10
0 <= m[][] <= 1

Example
Input:
2
4
1 0 0 0 1 1 0 1 0 1 0 0 0 1 1 1
4
1 0 0 0 1 1 0 1 1 1 0 0 0 1 1 1

Output:
DRDDRR
DDRDRR DRDDRR*/

void get_all_path(int m[MAX][MAX],int x,int y,int n,string str,vector<string>&res)
{
    if(x<0 || x>=n || y<0 || y>=n)
        return;
        
    if(m[x][y]==0)
        return;
    
    if(x==n-1 && y==n-1)
    {
        res.push_back(str);
        return;
    }
    
    m[x][y]=0;
    
    get_all_path(m,x+1,y,n,str+'D',res);
    get_all_path(m,x-1,y,n,str+'U',res);
    get_all_path(m,x,y-1,n,str+'L',res);
    get_all_path(m,x,y+1,n,str+'R',res);
    
    m[x][y]=1;
}

vector<string> printPath(int m[MAX][MAX], int n)
{  
   string str="";
   vector<string> res;
   
   get_all_path(m,0,0,n,str,res); 
   
   sort(res.begin(),res.end());
   
   return res;
}
