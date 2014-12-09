/***********************************************\
 |Author: YMC
 |Created Time: 2014/9/19 22:07:03
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
#define N 100005
string s;
map<string,vector<string> > ma;
map<string,bool> vis;
map<string,pair<int,int> > mb;
int n,m,len;
string ss[N];
string s1,s2;
inline void get(string& s){
    int len = s.length();
    rep(i,len){
        if(s[i] >= 'A' && s[i] <= 'Z') s[i] -= 'A' - 'a';
    }
} 
inline pair<int,int> minn(pair<int,int> a,pair<int,int> b){
    if(a.first < b.first) return a;
    else if(a.first > b.first) return b;
    else {
        if(a.second <= b.second) return a;
        else return b;
    } 
}
pair<int,int> dfs(string s){
    if(vis[s] == true && mb.count(s) != 0) return mb[s];    //定下来了
    int a = 0,b;
    b = s.length();
    rep(i,b) if(s[i] == 'r') a++;
    pair<int,int> now = make_pair(a,b);
    if(vis[s] == true || ma.count(s) == 0) {
        return now;
    }
    vis[s] = true;
    int size = ma[s].size();
    for(int i=0;i<size;++i){
        now = minn(now,dfs(ma[s][i]));
    }
    mb[s] = now;
    return now;
}
int main() {
	//freopen("input.txt","r",stdin); 
    //ios::sync_with_stdio(false);
    cin>>n;
    rep(i,n){
        cin>>ss[i];
        get(ss[i]);
    }
    cin>>m;
    rep(i,m) {
        cin>>s1>>s2;
        get(s1);get(s2);
        ma[s1].push_back(s2);
    }
    map<string,vector<string> >::iterator it = ma.begin();
    while(it != ma.end()){
        if(vis[it->first] != true){
            dfs(it->first);
        }
        it++;
    }
    ll ans1 = 0,ans2 = 0;
    rep(i,n){
        if(mb.count(ss[i]) == 0){
            int a = 0,b;
            b = ss[i].length();
            rep(j,b) if(ss[i][j] == 'r') a++;
            ans1 += a;
            ans2 += b;
        } else {
            ans1 += mb[ss[i]].first;
            ans2 += mb[ss[i]].second;
        }
    }
    cout<<ans1<<" "<<ans2<<endl;
	return 0;
}

