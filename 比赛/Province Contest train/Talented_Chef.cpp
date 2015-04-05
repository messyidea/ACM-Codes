/***********************************************\
 |Author: YMC
 |Created Time: 2015/4/5 15:59:06
 |File Name: Talented_Chef.cpp
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
int n,m;
int da[40005];
int maxx = 0;
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d",&n,&m);
        int sum = 0;
        maxx = 0;
        rep(i,n) {
            scanf("%d",&da[i]);
            sum += da[i];
            maxx = max(maxx,da[i]);
        }
        int ans = sum / m;
        if(ans * m != sum) ans ++;
        ans = max(ans, maxx);
        printf("%d\n",ans);

    }
	return 0;
}

