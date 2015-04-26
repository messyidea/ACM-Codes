/***********************************************\
 |Author: YMC
 |Created Time: 2015/4/26 15:13:44
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
bool vis[16];
int n;
int ma[10];
int now[10];
int tot;
char s[3];
map<char,int> mm;
string ss = "23456789TJQKA";
void init() {
    for(int i=0;i<ss.length();++i) {
        mm[ss[i]] = i;
    }
}
long long int ans;
void dfs(int d) {
    if(d == 0) {
        ans ++;
        return ;
    }
    for(int i=0;i<tot;++i) {
        if(!vis[i] && ma[i] != now[d+1]) {
            vis[i] = true;
            now[d] = ma[i];
            dfs(d-1);
            vis[i] = false;
        }
    }
}
int main() {
	//freopen("input.txt","r",stdin); 
    init();
    int T;
    int cas = 1;
    scanf("%d",&T);
    while(T--) {
        ans = 0;
        tot = 0;
        scanf("%d",&n);
        rep(i,n) {
            scanf("%s",&s);
            ma[tot ++] = mm[s[0]];
        }
        memset(vis,false,sizeof(vis));
        for(int i=0;i<tot;++i) {
            vis[i] = true;
            now[tot] = ma[i];
            dfs(tot-1);
            vis[i] = false;
        }
        printf("Case #%d: %lld\n",cas ++,ans);
    }
	return 0;
}

