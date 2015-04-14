/***********************************************\
 |Author: YMC
 |Created Time: 2015/4/12 23:18:40
 |File Name: e.cpp
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
double r, h, d;
double s, v;

int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%lf %lf %lf",&r,&h,&d);
        s = 2*r*d*pi*pi + 2*(r*r+r*h+d*h+d*d*2)*pi;
        v = ((6*d*(d*d + r*r)-2*d*d*d)*pi + 3*r*d*d*pi*pi)/3 + (r+d)*(r+d)*h*pi;
        printf("%.9lf %.9lf\n",v,s);

    }
	return 0;
}

