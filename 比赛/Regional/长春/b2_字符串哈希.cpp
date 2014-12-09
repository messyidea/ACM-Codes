/***********************************************\
  |Author: YMC
  |Created Time: 2014/10/9 21:03:14
  |File Name: b2.cpp
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
unsigned long long k = 999999997;
unsigned long long tp;
char s[100005];
unsigned long long hash[100005];
int n,m;
map<unsigned long long,int> ma;
int main() {
    //freopen("input.txt","r",stdin); 
    while(~scanf("%d %d",&n,&m)) {
        swap(n,m);
        scanf("%s",s + 1);
        int len = strlen(s + 1);
        memset(hash,0,sizeof(hash));
        for(int i=1;i<=n;++i) {
            hash[i] = hash[i-1] * k + s[i];
        }
        int t = n - 1;
        tp = 1;
        while(t-- > 0) tp *= k;
        for(int i=n + 1;i<=len;++i) {
            hash[i] = (hash[i - 1] - s[i - n] * tp) * k + s[i];
        }
        //for(int i=n;i<=len;++i) cout<<hash[i]<<endl; puts("");
        int ans = 0;
        for(int i=n;i<2*n && i<=len;++i) {
            ma.clear();
            int j = i;
            for(;j <= i + n*(m-1);j += n) {
                ma[hash[j]] ++;
            }
            if(ma.size() == m) ans ++;
            for(;j<=len;j += n) {
                ma[hash[j - m*n]] --;
                if(ma[hash[j-m*n]] == 0) ma.erase(hash[j-m*n]);
                ma[hash[j]] ++;
                if(ma.size() == m) ans ++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

