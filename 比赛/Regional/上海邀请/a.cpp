/***********************************************\
  |Author: YMC
  |Created Time: 2014/11/2 11:58:18
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
int da[105];
int dd[105];
int ma[105][105];
int n,k;
int main() {
    //freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d",&n,&k);
        memset(ma,0,sizeof(ma));
        srep(i,n) scanf("%d",&da[i]);
        int t1,t2;
        srep(i,n) {
            t1 = da[i] / k;
            t2 = da[i] % k;
            ma[t1][t2] ++;
        }
        int t = n/k;
        bool fg = true;
        for(int i=0;i<t;++i) {
            for(int j=(i == 0?1:0);j<k;++j){
                if(ma[i][j] == 0) {
                    fg = false;
                    break;
                } else {
                    ma[i][j] --;
                    ma[i + 1][j] += ma[i][j];
                }
            }
            if(fg == false) break;
        }
        if(fg == true) {
            t = n % k;
            int tt = n/k;
            for(int i=(n/k == 0? 1:0);i<=t;++i) {
                if(ma[tt][i] == 1) continue;
                else {
                    fg = false;
                    break;
                }
            }
        }
        if(fg) puts("Jerry");
        else puts("Tom");
    }
    return 0;
}

