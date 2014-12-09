/***********************************************\
 |Author: YMC
 |Created Time: 2014/12/9 19:26:12
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
int n1,n2;
int a[200005];
int b[200005];
int main() {
	//freopen("input.txt","r",stdin); 
    scanf("%d",&n1);
    rep(i,n1) {
        scanf("%d",&a[i]);
    }
    scanf("%d",&n2);
    rep(i,n2) {
        scanf("%d",&b[i]);
    }
    sort(a,a+n1);
    sort(b,b+n2);
    int tt = 0;
    ll p = -inf;
    ll tp;
    int an1,an2;
    ll ta,tb;
    for(int i=1;i<n1;++i) {
        if(a[i] == a[i-1]) continue;
        while(tt < n2 && a[i] > b[tt]) {
            tt ++;
        }
        ta = i*2 + (n1-i)*3;
        tb = tt * 2 + (n2 - tt) * 3;
        tp = ta - tb;
        if(tp > p || (tp == p && ta > an1) ) {
            p = tp;
            an1 = i*2 + (n1-i)*3;
            an2 = tt * 2 + (n2 - tt) * 3;
        }
    }
    tt = 0;
    while(tt < n2 && a[0] > b[tt]) {
        tt ++;
    }
    //cout<<tt<<endl;
    tp = (n1 * 3) - (tt * 2 + (n2 - tt) * 3);
    //cout<<tp<<endl;
    if(tp > p || (tp == p && n1 * 3 > an1)) {
         p = tp;
         an1 = n1 * 3;
         an2 = tt * 2 + (n2 - tt) * 3;
    }
    //cout<<an1<<" "<<an2<<endl;
    tp = (n1 * 2) - (n2 * 2);
    //cout<<tp<<endl;
    if(tp > p || (tp == p && n1 * 2 > an1)) {
         p = tp;
         an1 = n1 * 2;
         an2 = n2 * 2;
    }
    tp = (n1 * 3) - (n2 * 3);
    //cout<<tp<<endl;
    if(tp > p || (tp == p && n1 * 3 > an1)) {
         p = tp;
         an1 = n1 * 3;
         an2 = n2 * 3;
    }
    cout<<an1<<":"<<an2<<endl;
	return 0;
}

