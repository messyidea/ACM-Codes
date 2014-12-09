/***********************************************\
 |Author: YMC
 |Created Time: 2014/10/9 20:21:39
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
char s[100005];
int len;
int vis[30];
bool can[100005];
inline int id(char a) {
    return a - 'a';
}
int main() {
	//freopen("input.txt","r",stdin); 
    while(~scanf("%d %d",&n,&m)) {
        scanf("%s",s+1);
        len = strlen(s+1);
        //cout<<len<<endl;
        memset(vis,0,sizeof(vis));
        memset(can,0,sizeof(can));
        int has = 0;
        //for(int i=1;i<=len;++i) putchar(s[i]); puts("");
        for(int i=1;i<=len;++i) {
            if(has < n){
                if(vis[id(s[i])] == 0 || abs(vis[id(s[i])] - i) > has) {
                    has ++;
                    vis[id(s[i])] = i;
                    if(has == n) {
                        can[i] = true;
                    }
                } else {
                    has = i - vis[id(s[i])];
                    vis[id(s[i])] = i;
                }
            } else if(has == n) {
                vis[id(s[i-has])] = 0;
                if(vis[id(s[i])] == 0 || abs(vis[id(s[i])]) - i > n) {
                    vis[id(s[i])] = i;
                    can[i] = true;
                } else {
                    has = i - vis[id(s[i])];
                    vis[id(s[i])] = i;
                }
            }
        }
        //for(int i=1;i<=len;++i) if(can[i]) cout<<i<<" ";puts("");
        int ans = 0;
        for(int i=1;i<=len;++i) {
            if(can[i]) {
                int j = i;
                for(;can[j]; j += n);
                int num = (j - i) / n;
                if(num <= m) ans += 0;
                else ans += num - m + 1;
                j = i;
                for(;can[j];j += n) can[j] = false;
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}

