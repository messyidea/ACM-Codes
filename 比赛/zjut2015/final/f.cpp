
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define srep(i,n) for(int i=1;i<=n;++i)
#define inf 0x3f3f3f3f
typedef long long ll;
using namespace std;
map<ll,int> ma;
ll a;
int n,m,b;
int main() {
    //freopen("input.txt","r",stdin);
    while(scanf("%d",&n) != EOF) {
        ma.clear();
        rep(i,n) {
            scanf("%lld",&a);
            ma[a] ++;
        }
        scanf("%d",&m);
        rep(i,m) {
            scanf("%lld",&a);
            printf("%d\n",ma[a]);
        }
    }
    return 0;
}
 
/**************************************************************
    Problem: 1550
    User: 2015AK01
    Language: C++
    Result: Accepted
    Time:832 ms
    Memory:3664 kb
****************************************************************/
