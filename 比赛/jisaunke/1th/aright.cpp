/***********************************************\
 |Author: YMC
 |Created Time: 2015/7/18 14:00:59
 |File Name: a2.cpp
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
char ss[1000006];
char ts[1000006];
int tt;
int len;
int start(int p) {
    tt = 0;
    bool ff = false;
    int i;
    for(i=p;i<len;++i) {
        if((ss[i] >= '0' && ss[i] <= '9') || (ss[i] >= 'A' && ss[i] <= 'E')) {
            ts[tt ++] = ss[i];
            if(ss[i] != '0') ff = true;
        } else {
            if(ff) {
                ts[tt ++] = '\0';
                printf("0k%s\n",ts);
                return i;
            } 
            return i-1;
        }
    }
    if(ff) {
        ts[tt ++] = '\0';
        printf("0k%s\n",ts);
        return i;
    }
    return i-1;
}
void solve() {
    //printf("%s\n",ss);
    len = strlen(ss);
    for(int i = 0 ; i < len-1 ; ++ i) {
        if(ss[i] == '0' && ss[i+1] == 'k') {
            if(i+2 == len) return ;
            if(ss[i + 2] == '0') {
                puts("0k0");
                i = i + 2;
                continue;
            }
            int t = start(i+2);
            i = t - 1;
        }
    }
}
int main() {
	//freopen("input.txt","r",stdin); 
    while(~scanf("%s",ss)) {
        solve();
    }

	return 0;
}

