/***********************************************\
 |Author: YMC
 |Created Time: 2014/11/6 9:00:38
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
ll da[100];
int aa[100];
int ab[100];
int ac[100];
int t1,t2;
void solve(ll l,ll r) {
    t1 = 0;t2 = 0;
    ll l1 = l,r1 = r;
    while(l1) {
        aa[t1 ++] = l1 % 2;
        l1 /= 2;
    }
    while(r1) {
        ab[t2 ++] = r1 % 2;
        r1 /= 2;
    }
    //cout<<"t1 == "<<t1<<"  t2 == "<<t2<<endl;
    int tt1 = t1-1,tt2 = t2-1;
    //while(aa[tt1] == ab[tt2]) tt1--,tt2--;
    if(tt2 > tt1) {
        bool fg = true;
        for(int i = 0;i<=tt2;++i) {
            if(ab[i] == 0) {
                fg = false;
            }
        }
        ll an = 0;
        ll t = 1;
        //cout<<"fg == "<<fg<<endl;
        if(fg) {
            for(int i=1;i<=tt2+1;++i) {
                an += t;
                t *= 2;
            }
            printf("%I64d\n",an);
            return ;
        } else {
            for(int i=1;i<=tt2;++i) {
                an += t;
                t *= 2;
            }
            printf("%I64d\n",an);
            return ;
        }
    }
    while(aa[tt1] == ab[tt2]) {
        ac[tt1] = aa[tt1];
        tt1 --;tt2 --;
    }
    int p1 = 0,p2 = 0;
    while(ab[p2] == 1) p2 ++;
    //cout<<p2<<"  "<<tt2<<endl;
    if(p2 > tt2) {
        printf("%I64d\n",r);
        return ;
    }
    ac[tt2--] = 0;
    while(tt2 >= 0) {
        ac[tt2--] = 1; 
    }
    ll ans = 0;
    ll ttt = 1;
    //rep(i,t2) cout<<ac[i]<<" ";cout<<endl;
    for(int i=0;i < t2;++i) {
        ans += ttt * (ac[i]);
        ttt *= 2;
    }
    printf("%I64d\n",ans);
    return ;



    

}
int main() {
	//freopen("input.txt","r",stdin); 
    //freopen("out","w",stdout);
    ll t = 1;
    da[0] = 0;
    for(int i=1;i<= 63;++i) {
        da[i] = da[i-1] + t;
        t *= 2;
    }
    int T;
    scanf("%d",&T);
    ll l,r;
    while(T--) {
        scanf("%I64d %I64d",&l, &r);
        //cout<<l<<" "<<r<<endl;
        if(l == r) {
            printf("%I64d\n",l);
            continue;
        }
        solve(l,r);
    }
	return 0;
}

