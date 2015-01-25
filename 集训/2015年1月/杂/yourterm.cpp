/***********************************************\
 |Author: YMC
 |Created Time: 2015-1-25 13:09:08
 |File Name: yourterm.cpp
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
#define srep(i,n) for(i = 1;i <= n;i ++)
#define MP make_pair
const int inf=0x3f3f3f3f ;
const double eps=1e-8 ;
const double pi=acos (-1.0);
typedef long long ll;

using namespace std;
string s;
int st[303];
int tot;
int pre[303];
int pr[303];
bool vis[303];
pair<int,int> pp[303];
int tot2;
int main() {
	//freopen("input.txt","r",stdin); 
    ios::sync_with_stdio(false);
    int T;
    //scanf("%d",&T);
    cin>>T;
    getline(cin,s);
    while(T--) {
        getline(cin,s);
        memset(vis,false,sizeof(vis));
        tot = 0;
        tot2 = 0;
        for(int i=0;i<s.length();++i) {
            if(s[i] == '(') {
                st[tot ++] = i;
                continue;
            }
            if(s[i] == ')') {
                pre[i] = st[tot - 1];
                tot --;
                pp[tot2 ++] = MP(tot,i);
            }
        }
        sort(pp,pp + tot2);
        //rep(i,tot2) cout<<pp[i].second<<"  "<<s[pp[i].second]<<"  "<<s[pre[pp[i].second]]<<endl;
        for(int i=0;i<tot2;++i) {
            int u = pp[i].second;
            int uu = pre[u];
            int p = uu - 1;
            while(p >= 0 && s[p] == ' ') {
                p --;
            }
            if(p < 0) {
                vis[u] = true;
                vis[uu] = true;
                continue;
            } 
            if(s[p] != '-') {
                vis[u] = true;
                vis[uu] = true;
            }
        }
        for(int i=1;i<tot2;++i) {
            int u = pp[i].second;
            if(!vis[u]) {
                int uu = pre[u];
                bool fg = false;
                for(int j = uu;j < u;++j) {
                    if(s[j] == '+' || s[j] == '-') {
                        fg = true;
                        break;
                    }
                }
                if(!fg) {
                    vis[u] = true;
                    vis[uu] = true;
                } 
            }
        }
        for(int i=0;i<s.length();++i) {
            if(s[i] == ' ' || vis[i]) continue;
            cout<<s[i];
        }
        cout<<"\n";
        
    }
	return 0;
}

