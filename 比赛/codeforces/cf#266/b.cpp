/***********************************************\
 |Author: YMC
 |Created Time: 2014/9/12 23:39:15
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
int main() {
	//freopen("input.txt","r",stdin); 
    ll a,b,n;
    ll a1,a2,p;
    cin>>n>>a>>b;
    ll ts = 922337203685477580ll;
    //cout<<ts<<endl;
    bool fg = false;
    if(n * 6ll <= a * b){
        cout<<a*b<<endl;
        cout<<a<<" "<<b<<endl;
    } else {
        ll tt = n * 6ll;
        a1 = a;a2 = b;
        ll ta,tb;
        if(a1 > a2){
            swap(a1,a2);
            fg = true;
        }
        //cout<<a1<<" "<<a2<<endl;
        ll tf = sqrt(tt);
        tf ++;
        //cout<<tt<<endl;
        //cout<<tf<<endl;
        ll tttt = max(a,b);
        for(ll i=a1;i<= tf;++i){
            ta = i;tb = tt / ta;
            //cout<<ta<<" "<<tb<<" "<<tt<<endl;
            if(ta * tb != tt) tb ++;
            //cout<<ta<<" "<<tb<<endl;
            if(tb < tttt) tb = tttt;
            if(ta * tb < ts){
                ts = ta * tb;
                a1 = ta,a2 = tb;
            }
        }
        if(a1 > a2) swap(a1,a2);
        cout<<ts<<endl;
        if(!fg)
        cout<<a1<<" "<<a2<<endl;
        else cout<<a2<<" "<<a1<<endl;
    }
	return 0;
}

