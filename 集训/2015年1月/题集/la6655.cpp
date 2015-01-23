
/***********************************************\
 |Author: YMC
 |Created Time: 2015-1-23 12:40:26
 |File Name: b.cpp
 |Description: 
\***********************************************/
#include <iostream>
#include <cstdio>
//#include <cmath>
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
#define srep(i,n) for(i = 1;i <= n;i ++)
#define MP make_pair
const int inf=0x3f3f3f3f ;
const double eps=1e-8 ;
//const double pi=acos (-1.0);
typedef long long ll;

using namespace std;
int gcd(int a,int b) {
    return b == 0 ? a : gcd(b,a % b);
}
int n;
int x1,x2,y1,y2;
int a1,b1,a2,b2;
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    int S;
    int a,b,c,d,e;
    while(~scanf("%d",&T)) {
        int cas = 1;
        while(T--) {
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            S = max(x1,y1);
            S = max(S,max(x2,y2));
            a = x2 - x1;
            b = y2 - y1;
            c = -b; d = a;
            e = gcd(abs(c),abs(d));
            c /= e; d /= e;
            a1 = 0 + c;
            b1 = 0 + d;
            if(a1 <= S && b1 <= S && a1 >= 0 && b1 >= 0) {
                printf("Case %d: %d %d %d %d\n",cas ++,a1,b1,0,0);
                continue;
            } 
            a1 = 0 - c;
            b1 = 0 - d;
            if(a1 <= S && b1 <= S && a1 >= 0 && b1 >= 0) {
                printf("Case %d: %d %d %d %d\n",cas ++,a1,b1,0,0);
                continue;
            } 
            a1 = S + c;
            b1 = 0 + d;
            if(a1 <= S && b1 <= S && a1 >= 0 && b1 >= 0) {
                printf("Case %d: %d %d %d %d\n",cas ++,a1,b1,S,0);
                continue;
            } 
            a1 = S - c;
            b1 = 0 - d;
            if(a1 <= S && b1 <= S && a1 >= 0 && b1 >= 0) {
                printf("Case %d: %d %d %d %d\n",cas ++,a1,b1,S,0);
                continue;
            } 


        }

    }
	return 0;
}
