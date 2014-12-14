/***********************************************\
 |Author: YMC
 |Created Time: 2014/12/14 12:00:36
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
char ss[1000005];
void solve() {
    int len = strlen(ss);
    int t = 0;
    for(int i=0;i<len;++i) {
        t = t * 10;
        t += ss[i] - '0';
        t %= 4;
    }
    //cout<<t<<endl;
    int an1=1,an2=1,an3=1,an4=1;
    int tt = t;
    while(tt --) {
        an1 *= 1;
    }
    tt = t;
    while(tt --){
        an2 *= 2;
    }
    tt = t;
    while(tt --){
        an3 *= 3;
    }
    tt = t;
    while(tt --){
        an4 *= 4;
    }
    int ans = an1 + an2 + an3 + an4;
    ans %= 5;
    printf("%d\n",ans);
}
int main() {
	//freopen("input.txt","r",stdin); 
    while(scanf("%s",ss)!=EOF) {
        solve();
    }
	return 0;
}

