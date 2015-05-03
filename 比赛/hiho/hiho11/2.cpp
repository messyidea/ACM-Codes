/***********************************************\
 |Author: YMC
 |Created Time: 2015/5/3 19:34:30
 |File Name: 2.cpp
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
int da[100005];
int dc[100005][100];
int db[100005];
int dt[105];
int cal(int t) {
    int sum = 0;
    int i;
    int tot = 0;
    for(i=1;i*i<=t;++i) {
        if(t % i == 0) {
            sum += 2;
            dc[t][tot ++] = i;
            dc[t][tot ++] = t / i;
        }
    }
    if((i-1) * (i-1) == t) sum --;
    return sum;
}
void init() {
    for(int i=1;i<=100000;++i) da[i] = cal(i);
}
int n;
bool cmp(int a,int b) {
    return da[a] > da[b];
}
int ca(int a,int b) {
    /*int tot = 0;
    for(int i=0;i<da[a];++i) {
        dt[tot ++] = dc[a][i];
    }
    for(int i=0;i<da[b];++i) {
        dt[tot ++] = dc[b][i];
    }
    sort(dt,dt + tot);
    int len = unique(dt,dt+tot) - dt;
    //rep(i,len) cout<<dt[i]<<" ";cout<<endl;
    ll tt = ll(a) * ll(b);
    int rt = 0;
    int i;
    for(i=0;i<len;++i) {
        if((ll)dt[i] * (ll)dt[i] > tt) break;
        rt += 2;
    }
    if((ll)dt[i]*(ll)dt[i] == tt || (ll)dt[i-1]*(ll)dt[i-1] == tt) rt --;*/
    ll t = (ll)a * (ll)b;
    ll i;
    int sum = 0;
     for(i=1;i*i<=t;++i) {
        if(t % i == 0) {
            sum += 2;
        }
    }
     if((i-1)*(i-1) == t) sum --;
    return sum;
    
}
int main() {
	//freopen("input.txt","r",stdin); 
    
    init();
    //cout<<ca(8,16)<<endl;
    //cout<<da[128]<<endl;
    //cout<<da[12]<<endl;
    
    while(scanf("%d",&n) != EOF) {
        int maxn = 0;
        int ans = 0;
        rep(i,n){
           scanf("%d",&db[i]);
           if(da[db[i]] > maxn) {
               maxn = da[db[i]];
               ans = db[i];
           }
        }
        sort(db,db+n,cmp);
        //cout<<"ans = "<<ans<<endl;
        int an = 0;
        n = min(n,20);
       
        /*rep(i,n) {
            //cout<<i<<endl;
            an = max(an,ca(ans,db[i]));
        }*/
        for(int i=0;i<n;++i) {
            for(int j=i+1;j<n;++j) {
                an = max(an,ca(db[i],db[j]));
            }
        }
        printf("%d\n",an);
        //sort(db,db + n,cmp);
        
    }
	return 0;
}

