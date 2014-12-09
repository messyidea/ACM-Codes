/***********************************************\
 |Author: YMC
 |Created Time: 2014/9/20 21:44:24
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
int da[100005];
map <int,int> ma;
map <int,int> mb;
int n,a,b;
int main() {
	//freopen("input.txt","r",stdin); 
    scanf("%d%d%d",&n,&a,&b);
    rep(i,n){
        scanf("%d",&da[i]);
        ma[da[i]] = 1;
    }
    bool fg = true;
    rep(i,n){
        int t = da[i];
        if(a - t > 0 && ma[a - t] == 1) {
            mb[t] = 1;
            mb[a - t] = 1;
            continue;
        }
        if(b - t > 0 && ma[b-t] ==1) {
            mb[t] = 2;
            mb[b-t] = 2;
            continue;
        }
        fg = false;
        break;
    }
    if(!fg) puts("NO");
    else {
        puts("YES");
        rep(i,n){
            printf("%d ",mb[da[i]] - 1);
        }
        puts("");
    }
	return 0;
}

