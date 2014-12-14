/***********************************************\
 |Author: YMC
 |Created Time: 2014/12/14 16:53:53
 |File Name: ccc.cpp
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
char ss[10005];
int pp[10005];
int tot;
int main() {
	freopen("input.txt","r",stdin); 
    int n;
    scanf("%d",&n);
    rep(i,n){
        scanf("%s",ss);
        int len = strlen(ss);
        int ans = 0;
        tot = 0;
        rep(j,len) {
            if(ss[j] == 'o') {
                pp[tot ++] = j;
            }
        }
        for(int i=0;i + 1<tot;++i) {
            ans ^= (pp[i+1] - pp[i] - 1);
        }
        if(ans != 0) {
            puts("Mzhq Orz");
        } else {
            puts("Fry Orz");
        }
    }
	return 0;
}

