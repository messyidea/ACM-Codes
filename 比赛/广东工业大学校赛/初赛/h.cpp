/***********************************************\
 |Author: YMC
 |Created Time: 2015/3/14 15:08:43
 |File Name: haha.cpp
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
char ss[1005];
int k;
int l1,r1,l2,r2,len;
bool vis[1005];
int tt[1005];
int tot;
void solve(int i) {
    if(!vis[i]) {
        vis[i] = true;
        tt[tot ++] = ss[i];
        int l = l2 + i;
        if(!vis[l]) {
            if(l < k) {
                solve(l);
            } else {
                vis[l] = true;
                tt[tot ++] = ss[l];
            }
        }
    }
}
int main() {
    //freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%s",ss);
        scanf("%d",&k);
        len = strlen(ss);
        memset(vis,false,sizeof(vis));
        l1 = 0,r1 = k-1;
        l2 = len - k,r2 = len - 1;
        int sum = 0;
        for(int i=0;i<k;++i) {
            tot = 0;
            solve(i);
            if(tot == 0) continue;
            sort(tt,tt + tot);
            int n1 = 1,n2 = 0;
            //rep(i,tot) cout<<tt[i]<<" ";cout<<endl;
            for(int i=1;i<tot;++i) {
                if(tt[i] == tt[i-1]) {
                    n1 ++;
                } else {
                    if(n1 > n2) n2 = n1;
                    n1 = 1;
                }
            }
            if(n1 > n2) n2 = n1;
            //cout<<tot<<"    "<<n2<<endl; 
            sum += tot - n2;
        }
        printf("%d\n",sum);
    }
	return 0;
}

