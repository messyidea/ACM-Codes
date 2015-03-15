/***********************************************\
 |Author: YMC
 |Created Time: 2015/3/15 14:10:55
 |File Name: f.cpp
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
long long n,m;
long long A[15];
ll C(int n,int m) {
    int t = m;
    long long a = 1;
    int tt = n;
    while(m --) {
        a = a * tt;
        tt -- ;
    }
    a /= A[t];
    return a;
}
void solve(long long  nn) {
    ll t = sqrt(nn+1);
    t += 2;
    int count = 0;
    for(int i=2;i<=t;i ++) {
        if(nn % i == 0) {
            count ++;
            while(nn % i == 0) nn /= i;
        }
        if(nn == 1) break;
    }
    if(nn != 1) count ++;
    long long ans = 0;
    /*if(count >= 2) {
        for(int i=1;i<=count/2;++i) {
            if(i == count - i)
                ans += C(count,i)/2;
            else 
                ans += C(count,i);
        }
    }*/
    if(count >= 2) {
        int t = count;
        ans = 1;
        while(t --) ans *= 2;
        ans -= 2;
        ans /= 2;
    }
    ans ++;
    cout<<ans<<endl;

}
int main() {
	//freopen("input.txt","r",stdin); 
    A[1] = 1;
    for(int i=2;i<=11;++i) {
        A[i] = A[i-1]*i;
    }
    int T;
    cin>>T;
    while(T--) {
        cin>>n>>m;
        if(m % n != 0) {
            puts("0");
            continue;
        }
        long long nn = m / n;
        solve(nn);
    }
	return 0;
}

