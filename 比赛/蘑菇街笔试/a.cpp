/***********************************************\
 |Author: YMC
 |Created Time: 2015/9/19 19:01:00
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
double r;
double a,b,a1,b1;
double len, len2;
long long ans;
int main() {
	//freopen("input.txt","r",stdin); 
    while(~scanf("%lf %lf %lf %lf %lf", &r, &a, &b, &a1, &b1)) {
        if(fabs(a1 - a) < eps && fabs(b1 - b) < eps) {
            puts("0");
            continue;
        }
        len = (a1 - a)*(a1 - a) + (b1 - b)*(b1 - b);
        len = sqrt(len);
        ans = len / (r * 2) + 0.99;
        if(ans == 0) ans ++;
        printf("%I64d\n", ans);
    }
	return 0;
}

