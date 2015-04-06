
/***********************************************\
 |Author: YMC
 |Created Time: 2015-4-6 13:48:29
 |File Name: aa.cpp
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
#define srep(i,n) for(int int i = 1;i <= n;i ++)
#define MP make_pair
const int inf=0x3f3f3f3f ;
const double eps=1e-8 ;
const double pi=acos (-1.0);
typedef long long ll;

using namespace std;
int n,m;
int tot1,tot2,tot3,tot4;
map<int,int> mq;    //que
map<string,int> team;
map<string,double> pe;
map<int,double> ti;
int tp;
string ss,ss2;
double score;
int aa,bb;
double sco[1005];
struct Peo{
    string s;
    double score;
}peo[505];
bool cmp(Peo a,Peo b) {
    if(a.score != b.score) return a.score > b.score;
    else return a.s < b.s;
}
bool isprime(int t) {
    for(int i=2;i*i<=t;++i) {
        if(t % i == 0) return false;
    }
    return true;
}
bool cmp2(double a,double b) {
    return a > b;
}
int main() {
	//freopen("input.txt","r",stdin); 
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    ti.clear();
    ti[1] = 36;
    ti[2] = 27;
    ti[3] = 18;
    while(T--) {
        mq.clear();
        team.clear();
        pe.clear();
        cin>>n>>m;
        cin>>tot1;
        rep(i,tot1) {
            cin>>tp;
            mq[tp] = 1;
        }
        cin>>tot2;
        rep(i,tot2) {
            cin>>tp;
            mq[tp] = 2;
        }
        cin>>tot3;
        rep(i,tot3) {
            cin>>ss;
            cin>>tp;
            team[ss] = tp;
        }
        rep(i,n) {
            score = 0;
            cin>>ss;
            cin>>ss2;
            score += ti[team[ss2]];
            cin>>ss2;
            if(ss2[0] == 'F') score += 33;
            cin>>aa>>bb;
            rep(i,aa) {
                cin>>tp;
                if(mq[tp] == 1) score += 2.5;
                else if(mq[tp] == 2) score += 1.5;
                else if(isprime(tp)) score += 1;
                else score += 0.3; 
            }
            rep(i,bb) {
                cin>>sco[i];
            }
            sort(sco,sco + bb,cmp2);
            if(bb >= 3) score += max(0.0,(sco[2]-1200)/100.0)*1.5;
            pe[ss] = score;
        }
        map<string,double>::iterator it = pe.begin();
        tot4 = 0;
        while(it!=pe.end()) {
            peo[tot4].s = it->first;
            peo[tot4 ++].score = it->second;
            it ++;
        }
        sort(peo,peo+tot4,cmp);
        cout.precision(3);
        for(int i=0;i<m;++i) {
            cout<<peo[i].s<<" "<<fixed<<peo[i].score<<endl;
        }
    }
	return 0;
}
