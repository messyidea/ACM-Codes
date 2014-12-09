/***********************************************\
 |Author: YMC
 |Created Time: 2014/10/25 20:12:21
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
ll ma[1005][1005];
ll mb[1005][1005];
ll da[1005];
int n,m,mm;
int a,b;
template <class T>
inline bool scan_d(T &ret) {
   char c; int sgn;
   if(c=getchar(),c==EOF) return 0; //EOF
   while(c!='-'&&(c<'0'||c>'9')) c=getchar();
   sgn=(c=='-')?-1:1;
   ret=(c=='-')?0:(c-'0');
   while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
   ret*=sgn;
   return 1;
}
 
inline void out(long long x) {
   if(x>9) out(x/10);
   putchar(x%10+'0');
}

void getmb(int n) {
    for(int i=0;i<n;++i) {
        for(int j=0;j<n;++j) {
            mb[i][j] = 0;
            for(int k=0;k<n;++k) {
                mb[i][j] += ma[i][k] * ma[k][j];
            }
        }
    }
}
int main() {
	//freopen("input.txt","r",stdin); 
    
    while(~scanf("%d",&n)) {
        m = 2 * n - 1;
        rep(i,m) {
            //scanf("%I64d",&da[i]);
            scan_d(da[i]);
        }
        for(int i=0;i<n;++i) {
            for(int j=n-1;j>=0;--j) {
                ma[j][i] = da[i + n-1 - j];
            }
        }
        getmb(n);
        ll ans = 0;
        //scanf("%I64d",&mm);
        scan_d(mm);
        int pre = 1;
        while(mm --) {
            scanf("%d %d",&a,&b);
            a = (a + pre) % n;
            b = (b + pre) % n;
            pre = mb[a][b];
            ans += pre;
        }
        //printf("%I64d\n",ans);
        out(ans);puts("");

    }
	return 0;
}

