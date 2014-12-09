/***********************************************\
 |Author: YMC
 |Created Time: 2014/11/22 15:48:00
 |File Name: a (2).cpp
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
#include <sstream>
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
ll abss(ll t) {
    if(t >= 0) return t;
    else return -t;
}
int main() {
	//freopen("input.txt","r",stdin); 
    string a,b;
    ll c,d,e;
    ll ans1,ans2;
    while(cin>>a) {
        b = a;
        int len = b.length();
        for(int i=len;i >= len/2; --i) {
            b[i] = b[len-i-1];
        }
        stringstream ss1,ss2;
        ss1<<a;
        ss1>>c;
        ss2<<b;
        ss2>>d;
        ans1 = abss(c-d);
        if(len % 2 == 0) {
            string t = b.substr(0,len/2);
            string t2;
            stringstream ss3;
            ss3 << t;
            ss3 >> e;
            e ++;
            stringstream ss4;
            ss4<<e;
            ss4>>t2;
            reverse(t2.begin(),t2.end());
            stringstream ss6;
            ss6<<e;
            ss6>>t;
            t += t2;
            stringstream ss5;
            ss5<<t;
            ss5>>e;
            ans2 = abss(e-c);
        } else {
            string t = b.substr(0,len/2 + 1);
            string t2;
            stringstream ss3;
            ss3 << t;
            ss3 >> e;
            e ++;
            stringstream ss4;
            ss4<<e;
            ss4>>t2;
            reverse(t2.begin(),t2.end());
            t2 = t2.substr(1);
            stringstream ss6;
            ss6<<e;
            ss6>>t;
            t += t2;
            stringstream ss5;
            ss5<<t;
            ss5>>e;
            ans2 = abss(e-c);
        }
        cout<<min(ans1,ans2)<<endl;
    }
	return 0;
}

