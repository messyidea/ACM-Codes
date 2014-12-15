
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
int n;
int a[25];
int main()
{
    int i,j;
 
    a[1]=4; a[2]=12; a[3]=22; 
     
    for(i=4;i<=20;i++) a[i]=a[i-3]*3+22;
    while(scanf("%d",&n)!=EOF){
      printf("%d\n",a[n]);  
    }
     
    return 0;
}
/**************************************************************
    Problem: 1315
    User: 2014CH145
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:1672 kb
****************************************************************/
