/***********************************************\
 |Author: YMC
 |Created Time: 2014/9/29 14:04:30
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
pair<int,pair<string,string> > pa[100005];
int n;
string s1,s2;
int da[100005];
int main() {
	//freopen("input.txt","r",stdin); 
    cin>>n;
    srep(i,n){
        cin>>s1>>s2;
        if(s1 > s2) swap(s1,s2);
        pa[i] = make_pair(i,make_pair(s1,s2));
    }
    srep(i,n){
        scanf("%d",&da[i]);
    }
    string now = pa[da[1]].second.first;
    bool fg = true;
    for(int i=2;i<=n;++i){
        int t = da[i];
        if(pa[t].second.first > now){
            now = pa[t].second.first;
            continue;
        }
        if(pa[t].second.second > now){
            now = pa[t].second.second;
            continue;
        }
        fg = false;
        break;
    }
    if(fg) puts("YES");
    else puts("NO");
	return 0;
}

