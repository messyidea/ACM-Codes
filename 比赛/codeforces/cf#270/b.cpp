/***********************************************\
 |Author: YMC
 |Created Time: 2014/9/29 13:45:34
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
int n,m;
int da[2005];
int main() {
	//freopen("input.txt","r",stdin); 
    scanf("%d %d",&n,&m);
    int mm = 0;
    rep(i,n) {
        scanf("%d",&da[i]);
        if(da[i] > mm){
            mm = da[i];
        }
    }
    sort(da,da+n);
    int p = 1;
    int ans = 0;
    for(int i=0;i<n;){
        if(da[i] == p){
            ++i;
            continue;
        }
        p++;
        int tp = (n-i)/m;
        if(tp * m != n - i){
            tp ++;
        }
        ans += 2 * tp - 1;
    }
    cout<<ans + mm - 1<<endl;
	return 0;
}

