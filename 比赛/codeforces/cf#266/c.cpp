/***********************************************\
 |Author: YMC
 |Created Time: 2014/9/13 0:15:56
 |File Name: c.cpp
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
ll da[500005];
int n;
ll sum;
int main() {
	//freopen("input.txt","r",stdin); 
    scanf("%d",&n);
    sum = 0;
    rep(i,n){
        scanf("%I64d",&da[i]);
        sum += da[i];
    }
    if(sum == 0){
        ll ss = 0;
        ll ss1 = 0;
        for(int i=0;i<n;++i){
            ss += da[i];
            if(ss == 0) ss1 ++;
        }
        if(ss1 == 1 || ss1 == 2) {
            cout<<0<<endl;
            return 0;
        } else {
            cout<<(1+ss1-2)*(ss1-2)/2<<endl;
            return 0;
        }
    } 
    ll tt = sum / 3;
    if(tt * 3 != sum){
        puts("0");
        return 0;
    }
    ll t1 = tt;ll t2 = tt*2;
    ll tt1 = 0,tt2 = 0;
    ll su = 0;
    ll cc = 0;
    ll ans = 0;
    rep(i,n){
        su += da[i];
        if(su == t2) ans += cc;
        if(su == t1) cc ++;
        //if(su == t2) tt2 ++; 
    }
    cout<<ans<<endl;
	return 0;
}

