/***********************************************\
 |Author: YMC
 |Created Time: 2014/11/11 21:30:09
 |File Name: he.cpp
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
int a[100000];
int l[100000];
int r[100000];
int main() {
	//freopen("input.txt","r",stdin); 
    a[0] = 0;
    a[1] = 1;
    a[2] = 3;
    a[3] = 8;
    l[3] = 3;
    r[3] = 5;
    for(int i=4;i<=10005;++i) {
        a[i] = 2 * l[i-1] + 3 * r[i-1];
        a[i] %= 10000;
        l[i] = l[i-1] + r[i-1];
        l[i] = (l[i] % 10000 + 10000) % 10000;
        r[i] = a[i] - l[i];
        r[i] = (r[i] % 10000 + 10000) % 10000;
    }
    int n;
    while(~scanf("%d",&n)) {
        if(n == 0) break;
        printf("%d\n",a[n] % 10000);
    }
	return 0;
}

