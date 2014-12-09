/***********************************************\
 |Author: YMC
 |Created Time: 2014/11/15 18:57:30
 |File Name: a.cpp
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
#define maxn 10000
bool valid[maxn];
int tot = 0;
void getprime(int n) {
    tot = 0;
    int i,j;
    for(i=2;i<=n;++i) valid[i] = true;
    for(i=2;i<=n;++i) {
        if(valid[i]) {
            if(n / i < i) break;
            for(j = i*i;j <=n;j+=i) valid[j] = false;
        }
    }
    for(i=2;i<=n;++i) {
        if(valid[i]) ans[++tot] = i;
    }
 }
int main() {
	//freopen("input.txt","r",stdin); 
    getprime(10000);
    int n;
    while(cin>>n) {
        for(int )
    }
	return 0;
}

