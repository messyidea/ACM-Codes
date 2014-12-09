/***********************************************\
 |Author: YMC
 |Created Time: 2014/11/23 17:20:40
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
int m1[1000002];
int m2[1000002];
int m3[1000002];
bool mm[1000002];
int num[1000002];
int a,b;
int tt;
int main() {
	//freopen("input.txt","r",stdin); 
    scanf("%d",&n);
    memset(mm,false,sizeof(mm));
    tt = 0;
    rep(i,n) {
        scanf("%d %d",&a,&b);
        m1[a] = b;
        m2[b] = a;
        mm[b] = true;
        num[tt ++] = a;
    }
    int ff;
    rep(i,tt) {
        if(num[i] != 0 && !mm[num[i]]) {
            ff = num[i];
            break;
        }
    }
    int tot = 2;
    int p = 0;
    while(tot <= n) {
        m3[tot] = m1[p];
        p = m1[p];
        tot += 2;
    }
    //srep(i,n) printf("%d ",m3[i]);
    tot = 3;
    m3[1] = ff;
    p = ff;
    //cout<<m2[0]<<endl;
    while(tot <= n) {
        m3[tot] = m1[p];
        p = m1[p];
        tot += 2;
    }
    srep(i,n) printf("%d ",m3[i]);
    puts("");
	return 0;
}

