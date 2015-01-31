/***********************************************\
 |Author: YMC
 |Created Time: 2015-1-30 12:18:31
 |File Name: 777.cpp
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
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    int n;
    while(T--) {
        scanf("%d",&n);
        if(n >= 1000) {
            puts("NO");
            continue;
        }
        n = 1000 - n;
        n = n % 7;
        if(n == 0) {
            puts("YES");
        } else puts("NO");
    }
	return 0;
}

