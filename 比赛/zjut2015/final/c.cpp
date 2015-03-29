
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <cmath>
typedef long long ll;
#define inf 0x3f3f3f3f
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
ll a,b,c;
void solve(ll a) {
    if(a % 2 == 1) {
        ll t = (a*a-1)/2;
        printf("%lld %lld\n",t,t+1);
        return ;
    } else {
        ll t = (a*a / 4) - 1;
        printf("%lld %lld\n",t,t+2);
        return ;
    }
 
}
int main() {
    //freopen("input.txt","r",stdin);
    while(scanf("%lld",&a) != EOF) {
        solve(a);
    }
    return 0;
}
 
/**************************************************************
    Problem: 1551
    User: 2015AK01
    Language: C++
    Result: Accepted
    Time:12 ms
    Memory:1672 kb
****************************************************************/
