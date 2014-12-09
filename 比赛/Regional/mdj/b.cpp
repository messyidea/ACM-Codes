/***********************************************\
 |Author: YMC
 |Created Time: 2014/10/12 12:55:19
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
ll ma[100];
int n,m;
ll aa,bb;
ll vis[100];
int cas = 0;
int gcd(int a,int b) {
    return b == 0?a : gcd(b,a%b);
}
void solve(int b) {
    if(b == m){
        memset(vis,0,sizeof(vis));
        int has = 0;
        for(int i=0;i<m;++i) {
            ll t = ma[i];
            for(int j = 0;j<n;++j) {
                if(t & (1 << j)) {
                    vis[j] ++;
                    has ++;
                }
            }
        }
        for(int i=0;i < n;++i){
            if(vis[i] == 0ll) return ;
        }
        for(int i=0;i< m;++i) if(ma[i] == 0) return ;
        bool fg = false;
        for(int i=0;i<n;++i){
            if(vis[i] == 1ll) fg = true;
        }
        for(int i=0;i<m;++i) {
            int cou = 0;
            ll tt = ma[i];
            for(int i = 0;i<n;++i) {
                if(tt & (1<<i)) cou ++;
            }
            if(cou == 1) fg = true;
        }
        if(fg == false) return ;
        bb ++;
        aa += has;
        cas ++;

        /*for(int i=0;i<m;++i){
            ll tt = ma[i];
            for(int j=0;j<n;++j) {
                if(tt & (j << i)) {
                    cout<<"1";
                } else {
                    cout<<"0";
                }
            }
            puts("");
        }
        puts("");*/
        //puts("");
        return ;
    }
    for(int i=1;i < (1<<n);++i) {
        ma[b] = i;
        solve(b + 1);
    }
}
int main() {
	//freopen("input.txt","r",stdin); 
    //freopen("")
    /*for(int ii=1;ii<=4;++ii){
        for(int jj=1;jj<=4;++jj){
            n = ii;m = jj;
            aa = 0;bb = 0;
        cas = 0;
        solve(0);
        int tt = gcd(aa,bb);
        //cout<<aa/tt<<"  "<<bb/tt<<"   ";
        cout<<aa * 1.0 / bb * 1.0<<"     ";
        }
        cout<<endl;
    }*/


    while(cin>>n>>m) {
        aa = 0;bb = 0;
        cas = 0;
        solve(0);
        int tt = gcd(aa,bb);
        //cout<<aa/tt<<"  "<<bb/tt<<"   ";
        cout<<aa<<"   "<<bb<<endl;
        cout<<aa * 1.0 / bb * 1.0<<"   "<<endl;
    }
	return 0;
}

