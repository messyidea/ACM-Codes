
/***********************************************\
 |Author: YMC
 |Created Time: 2014-8-12 13:31:15
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
int an[11] = {
    0,0,0,-1,-1,-1,-1,0,0,0,0
};
ll num;
int n,ans;
int tp = 1;
bool check2(ll u,ll i){
    if((u >= 3  &&  u <= 6) && i>u) return true;
    while(u){
        ll t = u % i;
        if(t < 3 || t > 6) return false;
        u /= i;
        if((u >= 3 && u <= 6) && i>u) return true;
    }
    return true;
}
void check(ll u,ll tt){
    //for(int i=1;i<=1000000&&i*i<=u;++i){
    for(ll i=1;i<=10000&&i*i<=u;++i){
        if(u % i == 0){
            if(i > tt)
                if(check2(u/i,i)) {
                    ans ++;
                }
            if(u/i > tt && i!=u/i)
                if(check2(i,u/i)) {
                    ans++;
                }
        }
    }
}
void solve(ll u){
    check(u-3,3ll);
    check(u-4,4ll);
    check(u-5,5ll);
    check(u-6,6ll);
}
int main() {
    //freopen("input.txt","r",stdin); 
    //freopen("out.txt","w",stdout);
    int T;
    cin>>T;
    int cas = 1;
    while(T--){
        //scanf("%I64d",&num);
        cin>>num;
        if(num <= 10){
            printf("Case #%d: %d\n",cas ++,an[num]);
            continue;
        }
        ans = 0;
        solve(num);
        printf("Case #%d: %d\n",cas ++,ans);
    }
    return 0;
}
