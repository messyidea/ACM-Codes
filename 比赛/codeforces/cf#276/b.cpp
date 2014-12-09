/***********************************************\
 |Author: YMC
 |Created Time: 2014/11/6 20:33:29
 |File Name: b.cpp
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
int da[200005];
bool cmp(int a,int b) {
    return a > b;
}
int main() {
	//freopen("input.txt","r",stdin); 
    int n;
    scanf("%d",&n);
    rep(i,n) {
        scanf("%d",&da[i]);
    }
    sort(da,da+n,cmp);
    int nn = unique(da,da+n) - da;
    int mma = 0;
    for(int i=0;i<nn && da[i] > mma;++i) {
        int ma = 0;
        for(int j=i+1;j < n && da[j] > ma; ++j) {
            int t = da[i] % da[j];
            if(t > ma) {
                ma = t;
            }
        }
        if(ma > mma) mma = ma;
    }
    printf("%d\n",mma);
	return 0;
}

