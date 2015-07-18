/***********************************************\
 |Author: YMC
 |Created Time: 2015/7/18 23:05:02
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
ll ans, l, r, ca, cou;
ll a1,a2,a3,a4,b1,b2,b3,b4;
int main() {
//	freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    ans = 0;
    while(T--) {
        scanf("%lld %lld %lld %lld %lld %lld %lld %lld",&a1,&a2,&a3,&a4,&b1,&b2,&b3,&b4);
        l = a1 * b1;
        r = a2 * b2;
        if(l > r) swap(l,r);
        ca = r - l;
        if(a3 < a4) {
            swap(a3,a4); swap(b3,b4);
        }
        cou = ca / a3;
        if(cou >= b3) {
            l += a3 * b3;
            //cou -= b3;
            b3 = 0;
            ca = r - l;
            cou = ca / a4;
            //r 大
            if(cou > b4) {
                printf("%lld\n",r);
                continue;
            } else {
                l += cou * a4;
                b4 -= cou;
            }
        } else {
            l += a3 * cou;
            b3 -= cou;
        }
        ll cc = b3 / 2;
        l += cc * a3;
        r += cc * a3;
        b3 -= b3 / 2 * 2;
        cc = b4 / 2;
        l += cc * b4;
        r += cc * b4;
        b4 -= b4 / 2 * 2;
        if(l > r) swap(l,r);
       while(b3 > 0) {
            b3 --;
            if(l > r) swap(l,r);
            l += a3;
        }
        while(b4 > 0) {
            b4 --;
            if(l > r) swap(l,r);
            l += a4;
        }

         
        if(l > r) swap(l,r);
        printf("%lld\n",r);


    }
	return 0;
}

