/***********************************************\
 |Author: YMC
 |Created Time: 2014/11/22 18:56:11
 |File Name: a.cpp
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
#define srep(i,n) for(int i = 1;i <= n;i ++)
#define MP make_pair
const int inf=0x3f3f3f3f ;
const double eps=1e-8 ;
const double pi=acos (-1.0);
typedef long long ll;

using namespace std;
int n;
int ans[100000];
int tot;
bool judge(int n) {
    if(n == 1) return false;
    for(int i=2;i*i<=n;++i) {
        if(n % i == 0) return false;
    }
    return true;
}
int solve(int n) {
    tot = 0;
    for(int i=1;i*i <= n;++i) {
        if(n % i == 0) {
            if(judge(n/i)) return i;
            int t = n / i;
            if(judge(i)) ans[tot ++] = t;
        }
    }
    if(tot == 0) return 0;
    sort(ans,ans+tot);
    return ans[0];
}
int main() {
	//freopen("input.txt","r",stdin); 
    while(~scanf("%d",&n)) {
        printf("%d\n",solve(n));
    }
	return 0;
}

