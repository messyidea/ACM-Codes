
/***********************************************\
 |Author: YMC
 |Created Time: 2015-4-6 12:36:49
 |File Name: b.cpp
 |Description: 
\***********************************************/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#define L(rt) (rt<<1)
#define R(rt) (rt<<1|1)
#define mset(l,n) memset(l,n,sizeof(l))
#define rep(i,n) for(int i=0;i<n;++i)
#define maxx(a) memset(a, 0x3f, sizeof(a))
#define zero(a) memset(a, 0, sizeof(a))
#define srep(i,n) for(int int i = 1;i <= n;i ++)
#define MP make_pair
const int inf=0x3f3f3f3f ;
const double eps=1e-8 ;
const double pi=acos (-1.0);
typedef long long ll;

using namespace std;
int a,b;
int d[3];
int aa[14];
set<int> se;
int solve(int a,int b,int c) {
    
    se.clear();
    aa[0] = abs(a);
    aa[1] = abs(b);
    aa[2] = abs(c);
    aa[3] = abs(a-b);
    aa[4] = abs(a-c);
    aa[5] = abs(b-c);
    aa[6] = abs(a+b);
    aa[7] = abs(a+c);
    aa[8] = abs(b+c);
    aa[9] = abs(a+b+c);
    aa[10] = abs(a+b-c);
    aa[11] = abs(a+c-b);
    aa[12] = abs(b+c-a);
    rep(i,13) {
        if(aa[i] != 0) se.insert(aa[i]);
    }
    return se.size();
}
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    int ans;
    while(T--) {
        scanf("%d %d",&a,&b);
        ans = 0;
        for(int i=1;i<=a/2;++i){
            ans = max(ans,solve(i,a-i,b));
        }
        for(int i=1;i<=b/2;++i) {
            ans = max(ans,solve(a,i,b-i));
        }
        printf("%d\n",ans);
    }
	return 0;
}
