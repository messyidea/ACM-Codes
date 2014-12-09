/***********************************************\
 |Author: YMC
 |Created Time: 2014/12/3 12:24:12
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
int n;
string s;
int t;
struct p {
    string name;
    int n;
}pe[205];
bool cmp(p a,p b) {
    if(a.n != b.n) return a.n > b.n;
    else return a.name < b.name;
}
map<string,pair<int,int> > ma;
int main() {
    //freopen("input.txt","r",stdin); 
    ios::sync_with_stdio(false);
    while(cin>>n && n) {
        ma.clear();
        int tot = 0;
        for(int i=0;i<n;++i){
            cin>>pe[i].name;
            cin>>pe[i].n;
        }
        sort(pe,pe + n,cmp);
        ma[pe[0].name] = make_pair(1,1);
        for(int i=1;i<n;++i) {
            if(pe[i].n == pe[i-1].n) {
                pair<int,int> tp = ma[pe[i-1].name];
                ma[pe[i].name] = make_pair(tp.first,tp.second + 1);
            } else {
                pair<int,int> tp = ma[pe[i-1].name];
                ma[pe[i].name] = make_pair(tp.first+tp.second,1);
            }
        }
        rep(i,n) {
            cout<<pe[i].name<<" "<<pe[i].n<<"\n";
        }
        cin>>n;
        while(n --) {
            cin>>s;
            pair<int,int> tp = ma[s];
            if(tp.second == 1) {
                cout<<tp.first<<"\n";
            } else {
                cout<<tp.first<<" "<<tp.second<<"\n";
            }
        }
    }
    return 0;
}

