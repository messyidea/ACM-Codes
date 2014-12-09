/***********************************************\
 |Author: YMC
 |Created Time: 2014/11/22 19:13:58
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
#define srep(i,n) for(int i = 1;i <= n;i ++)
#define MP make_pair
const int inf=0x3f3f3f3f ;
const double eps=1e-8 ;
const double pi=acos (-1.0);
typedef long long ll;

using namespace std;
int a,b;
int len;
ll k;
char s[100];
char t[100];
int ss;
bool fg;
bool judge(ll n) {
    if(!fg) {
    while(n >= ss) {
        ll t = n % k;
        if(t == ss) return true;
        n /= 10;
    }
    return false; 
    }
    else {
        while(n >= k) {
        ll t = n % k;
        if(t == ss) return true;
        n /= 10;
        }
        return false; 
    }
    /*int tot = 0;
    while(n > 0) {
        t[tot ++] = (n % 10) + '0';
        n /= 10;
    }
    t[tot] = 0;
    for(int i=0;i+len<=tot;++i) {
        int tt = i;
        for(int j=0;j<len;++j) {
            if(t[tt] != s[j]) break;
            if(j == len-1) return true;
            tt++;
        }
    }
    return false;*/
}
ll solve(int a) {
    ll p = ss / a;
    while(true) {
        if(judge(p*a)) {
            return p;
        }
        p++;
    }
}
int main() {
	//freopen("input.txt","r",stdin);
    while(~scanf("%d %s",&a,s)) {
        len = strlen(s);
        if(s[0] == '0') fg = true;
        else fg =false;
        ss = 0;
        for(int i=0;i<len;++i) {
            ss *= 10;
            ss += s[i] - '0';
        }
        k = 1;
        int tp = len;
        while(tp --) k *= 10;
        //cout<<"k == "<<k<<endl;
        //cout<<"ss == "<<ss<<endl;
        //reverse(s,s+len);
        printf("%I64d\n",solve(a));
    }
	return 0;
}

