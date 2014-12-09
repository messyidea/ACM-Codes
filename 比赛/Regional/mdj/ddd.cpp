
#include <set>
#include <map>
#include <queue>
#include <math.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

#define eps 1e-9
#define pi acos(-1.0)
#define inf 107374182
#define inf64 1152921504606846976
#define lc l,m,tr<<1
#define rc m + 1,r,tr<<1|1
#define iabs(x)  ((x) > 0 ? (x) : -(x))
#define clear1(A, X, SIZE) memset(A, X, sizeof(A[0]) * (SIZE))
#define clearall(A, X) memset(A, X, sizeof(A))
#define memcopy1(A , X, SIZE) memcpy(A , X ,sizeof(X[0])*(SIZE))
#define memcopyall(A, X) memcpy(A , X ,sizeof(X))
#define max( x, y )  ( ((x) > (y)) ? (x) : (y) )
#define min( x, y )  ( ((x) < (y)) ? (x) : (y) )

using namespace std;

const int maxn = 55;

double dp[maxn][maxn][maxn*maxn];
int n, m;
int N;
double dfs(int x, int y, int z)
{
  if(dp[x][y][z] != -1.0) return dp[x][y][z];
  if(x == n && y == m)
  {
    dp[x][y][z] = 0.0;
    return dp[x][y][z];
  }
  double p1 = 0.0, p2 = 0.0, p3 = 0.0, p4 = 0.0;
  dp[x][y][z] = 1.0;
  if(x+1 <= n)
  {
    p1 = ((n-x)*y*1.0)/z*1.0;
    dp[x][y][z] += p1*dfs(x+1, y, z-1);
  }
  if(y+1 <= m)
  {
    p2 = ((m-y)*x*1.0)/z*1.0;
    dp[x][y][z] += p2*dfs(x, y+1, z-1);
  }
  if(x+1 <= n && y+1 <= m)
  {
    p3 = ((n-x)*(m-y))*1.0/z*1.0;
    dp[x][y][z] += p3*dfs(x+1, y+1, z-1);
  }
  p4 = 1.0-p1-p2-p3;
  if(p4 >= 0) dp[x][y][z] += p4*dfs(x, y, z-1);
  return dp[x][y][z];
}
int main()
{
  int T;
  scanf("%d",&T);
  while(T--)
  {
    scanf("%d %d",&n, &m);
    N = n*m;
    if(n == 1 || m == 1)
    {
      printf("%.10lf\n",(double)max(n, m));
      continue;
    }
    for(int i = 0; i <= n; i++)
      for(int j = 0; j <= m; j++)
        for(int k = 0; k <= n*m; k++) dp[i][j][k] = -1.0;
    printf("%.10lf\n",dfs(1, 1, N-1)+1);
  }
  return 0;
}
