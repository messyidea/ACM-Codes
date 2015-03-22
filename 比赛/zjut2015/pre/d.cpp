/***********************************************\
 |Author: YMC
 |Created Time: 2015/3/22 12:43:39
 |File Name: d.cpp
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
#define N 400005
int n;
int pp[200005];
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        rep(i,n) {
            scanf("%d",&pp[i]);
        }
        int now = 0;
        int sum = 0;
        for(int i=n-1;i>=0;--i) {
            if(pp[i] > now) {
                now = pp[i];
                sum ++;
            }
        }
        printf("%d\n",sum);
    }
	return 0;
}

