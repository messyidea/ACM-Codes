/***********************************************\
 |Author: YMC
 |Created Time: 2014/12/9 19:07:12
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
int a[200005];
int b[200005];
int t1,t2;
int main() {
	//freopen("input.txt","r",stdin); 
    int n;
    scanf("%d",&n);
    int fin;
    ll aa = 0,bb = 0;
    t1 = 0;
    t2 = 0;
    int t;
    rep(i,n) {
        scanf("%d",&t);
        if(t > 0) {
            fin = 1;
            a[t1 ++] = t;
            aa += t; 
        } else {
            fin = 2;
            b[t2 ++] = -t; 
            bb -= t;
        }
    }
    if(aa > bb) {
        cout<<"first\n";
    } else if(bb > aa) {
        cout<<"second\n";
    } else {
        //cout<<"hehe";
        int tt = min(t1,t2);
        int fg = 0;
        for(int i=0;i<tt;++i) {
            if(a[i] == b[i]) continue;
            if(a[i] > b[i]) {
                //cout<<a[i]<<" "<<b[i]<<endl;
                //cout<<i<<endl;
                fg = 1;
                break;
            } else if(a[i] < b[i]) {
                fg = 2;
                break;
            }
        }
        if(fg == 2) {
            //cout<<"hehe";
            cout<<"second\n";
        } else if(fg == 1){
            cout<<"first\n";
        } else {
            if(t1 < tt) {
                cout<<"first\n";
            } else if(t2 < tt) {
                cout<<"second\n";
            } else if(fin == 1) {
                cout<<"first\n";
            } else cout<<"second\n";
        }
    }
	return 0;
}

