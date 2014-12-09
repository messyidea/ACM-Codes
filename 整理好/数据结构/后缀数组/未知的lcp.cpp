
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <math.h>
 
using namespace std;
 

#define INF 5005

void reset(int LCP[INF][INF])
{
  for(int i = 0; i < INF; i++)
    for(int j = 0; j < INF; j++)
      LCP[i][j] = 0;
}

void computeLCP(string A, string B, int LCP[INF][INF])
{
  reset(LCP);
  for(int i = A.size() - 1; i >= 0; i--)
    for(int j = B.size() - 1; j >= 0; j--)
      LCP[i][j] = (A[i] == B[j]) ? LCP[i+1][j+1] + 1 : 0;
}

int lcp[INF][INF];

int main()
{
	freopen("1.txt","r",stdin);
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    string S1, S2;
    cin >> S1 >> S2;
    
    int UP1[INF];
    computeLCP(S1, S1, lcp);
    
    for(int i = 0; i < S1.size(); i++)
    {
      int maxLCP = 0;
      
      for(int j = 0; j < S1.size(); j++)
      {
        if(i == j)
          continue;
        
        maxLCP = max(maxLCP, lcp[i][j]);
      }
      
      UP1[i] = maxLCP + 1;
    }
    for(int i=0;i<S1.size();++i){
    	cout<<UP1[i]<<" ";
    }
    cout<<endl;
    
    int UP2[INF];
    computeLCP(S2, S2, lcp);
    
    for(int i = 0; i < S2.size(); i++)
    {
      int maxLCP = 0;
      
      for(int j = 0; j < S2.size(); j++)
      {
        if(i == j)
          continue;
        
        maxLCP = max(maxLCP, lcp[i][j]);
      }
    
      UP2[i] = maxLCP + 1;
    }
    for(int i=0;i<S1.size();++i){
    	cout<<UP2[i]<<" ";
    }
    cout<<endl;
        
    computeLCP(S1, S2, lcp);
    int ans = INF;
    
    for(int i = 0; i < S1.size(); i++)
    {
        for(int j = 0; j < S2.size(); j++)
        {
          if(lcp[i][j] >= max(UP1[i], UP2[j]))
            ans = min(ans, max(UP1[i], UP2[j]));
        }
    }
    
    if(ans == INF)
      cout << -1;
    else
      cout << ans;
    
    return 0;
}
