/***********************************************\
 |Author: YMC
 |Created Time: 2015/3/14 13:23:46
 |File Name: d.cpp
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
int t;
int da[1000];
void solve(int n){
    int tot = 0;
    n --;
    if(n == 0) da[tot ++] = 0;
    if(n > 0) da[tot ++] = n % 26;
    n /= 26;
    if(n > 0) da[tot ++] = n % 27;
    n /= 27;
    if(n > 0) da[tot ++] = n % 27;
    n /= 27;
    if(tot == 2) da[1] -- ; 
    if(tot == 3) da[2] -- ;
    for(int i=tot-1;i>=0;--i) {
       if(da[i] < 0) continue;
       printf("%c",'A' + da[i]);
    }
    puts("");
}
int main() {
	//freopen("input.txt","r",stdin);
    //freopen("out1","w",stdout);
    /*for(int i=1;i<=1000;++i) {
        solve(i);
    }*/
    int T,n;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        solve(n);
    }
	return 0;
}

