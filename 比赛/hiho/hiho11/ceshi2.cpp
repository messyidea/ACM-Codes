/***********************************************\
 |Author: YMC
 |Created Time: 2015/5/3 20:16:43
 |File Name: ceshi2.cpp
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
ll da[1000];
int  cal(ll t) {
    ll i;
    int tot = 0;
    int sum = 0;
    for(i=1;i*i <= t;++i) {
        if(t % i == 0) {
            sum += 2;
            da[tot ++] = i;
            da[tot ++] = t/i;
        }
    }
    if((i-1)*(i-1) == t) sum --;
    sort(da,da+sum);
    rep(i,sum) cout<<da[i]<<" ";cout<<endl;
    return sum;
}
int main() {
	//freopen("input.txt","r",stdin); 
    cout<<cal(10000000000ll)<<endl;
	return 0;
}

