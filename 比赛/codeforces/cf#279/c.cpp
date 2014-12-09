/***********************************************\
 |Author: YMC
 |Created Time: 2014/11/23 17:47:41
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
char s[1000006];
bool m1[1000006];
ll m2[1000006];
int pp[1000006];
ll a,b;
ll ppow(ll x,ll n,ll mod){
    ll res = 1;
    while(n > 0){
        if(n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}
int main() {
    //freopen("input.txt","r",stdin); 
    scanf("%s",&s);
    scanf("%I64d %I64d",&a,&b);
    int len = strlen(s);
    ll now = 0;
    int tot = 0;
    rep(i,len) {
        now = now * 10 + s[i] - '0';
        if(now % a == 0 && s[i+1] != '0') {
            m1[i] = true;
            //cout<<i<<endl;
            pp[tot ++] = i;
        }
        now = now % a;
    }
    if(pp[tot - 1] == len - 1) tot --;
    int ans = -1;
    for(int i = tot - 1;i >= 0;--i) {
        int p = pp[i];
        now = 0;
        for(int j = p+1;j < len;++j) {
            if(m2[j] == 0){
                now = now * 10 + s[j] - '0';
                now = now % b;
            } else {
                now = now*ppow(10,len-j,b) + m2[j];
                now = now % b;
                break;
            }
        }
        if(now == 0) {
            ans = p;
            break;
        } else {
            m2[p+1] = now;
            //cout<<"now == "<<now<<endl;
        }
    }
    if(ans == -1) {
        puts("NO");
    } else {
        puts("YES");
        for(int i=0;i<=ans;++i) {
            putchar(s[i]);
        }
        puts("");
        for(int i=ans+1;i<len;++i) {
            putchar(s[i]);
        }
        puts("");
    }

	return 0;
}

