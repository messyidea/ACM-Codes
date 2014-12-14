
/***********************************************\
 |Author: YMC
 |Created Time: 2014/12/14 12:24:09
 |File Name: c.cpp
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
int a,b,c;
int aa[1005];
int bb[1005];
int cc[1005];
map<int,int> mc;
int main() {
    ios::sync_with_stdio(false);
    while(cin>>a>>b>>c) {
        mc.clear();
        rep(i,a) {
            cin>>aa[i];
        }
        rep(i,b) {
            cin>>bb[i];
        }
        rep(i,c) {
            cin>>cc[i];
            mc[cc[i]] ++;
        }
        int ans = 0;
        rep(i,a) {
            rep(j,b) {
                ans += mc[aa[i] + bb[j]];
            }
        }

        cout<<ans<<endl;
    }
	return 0;
}

