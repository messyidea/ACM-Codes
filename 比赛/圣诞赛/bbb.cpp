
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<string>
#include<cstring>
#include<algorithm>
#include<fstream>
#include<queue>
#include<stack> 
#include<vector>
#include<cmath>
#include<iomanip>
#define rep(i,n) for(i=1;i<=n;i++)
#define MM(a,t) memset(a,t,sizeof(a))
#define INF 1e9
typedef long long ll;
#define mod 1000000007
using namespace std;
char st[10200];
int l,ans;
int main()
{
    int i,j,T;
     
    scanf("%d",&T);
    while(T--){
      scanf("%s",st);   
      l=strlen(st);
      ans=0;
      for(i=0;i<l;i++)
      if(st[i]=='o') ans+=l-i-1;
      if(ans%2) printf("Mzhq Orz\n");
      else      printf("Fry Orz\n");
    }
 
     
    return 0;
}
/**************************************************************
    Problem: 1314
    User: 2014CH145
    Language: C++
    Result: Accepted
    Time:8 ms
    Memory:1688 kb
****************************************************************/
