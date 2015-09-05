/***********************************************\
 |Author: YMC
 |Created Time: 2015/9/5 19:00:05
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
int n,t;
map<ll,int> ma;
bool check(int t) {
    int tt = sqrt(t + 0.1) + 1;
    for(int i=2;i < tt; ++i) {
        if(t % i == 0) return false;
    }
    return true;
}
void ca(int t) {
    if(t == 1) return ;
    int tt = sqrt(t + 0.1) + 1;
    int count = 0;
    for(ll i = 2; i <= tt ; ++i) {
        while(t % i == 0) {
            ma[i] ++;
            count ++;
            if(count >= 2) return ;
        }
    }
    if(t != 1)
        ma[t] ++;
}
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--) {
        ma.clear();
        scanf("%d",&n);
        if(n == 1) {
            scanf("%d",&t);
            if(check(t)) {
                puts("-1");
            } else {
                ll k = 1;
                int count = 0;
                for(ll i = 2;i*i < t; ++i) {
                    while(t % i == 0) {
                        t /= i;
                        k *= i;
                        count ++;
                        if(count >= 2) {
                            break;
                        }
                    }
                    if(count >= 2) break;
                }
                printf("%I64d\n", k);
            }
        }
        rep(i,n) {
            scanf("%d",&t);
            ca(t);
        }
        int all = 0;
        map<ll,int>::iterator it = ma.begin();
        while(it != ma.end()) {
            all += it->second;
            it ++;
        }
        if(all == 1) {
            puts("-1");
            continue;
        }
        it = ma.begin();
        if(it->second >= 2) {
            printf("%I64d\n", it->first*it->first);
        } else {
            ll k = it->first;
            it ++;
            printf("%I64d\n", it->first * k);
        }
    }
	return 0;
}

