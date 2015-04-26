/***********************************************\
 |Author: YMC
 |Created Time: 2015/4/26 15:13:44
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
bool vis[16];
int n;
char s[3];
map<char,int> mm;
int ma[54];
int cou[15];
string ss = "23456789TJQKA";
void init() {
    for(int i=0;i<ss.length();++i) {
        mm[ss[i]] = i;
    }
}
unsigned long long int ans;
unsigned long long get(int count ) {
    unsigned long long int ans = 1;
    for(int i=1;i<=count;++i) ans *= i;
    return ans;
}
int main() {
	//freopen("input.txt","r",stdin); 
    init();
    int T;
    int cas = 1;
    scanf("%d",&T);
    while(T--) {
        ans = 0;
        scanf("%d",&n);
        int count = 0;
        memset(ma,0,sizeof(ma));
        memset(cou,0,sizeof(cou));
        rep(i,n) {
            scanf("%s",&s);
            ma[mm[s[0]]] ++;
        }

        for(int i=0;i<13;++i) {
            if(ma[i] != 0) {
                count ++;
                ma[i] --;
                cou[i] ++;
            }
        }
        ans = get(count);
        bool fg = true;
        while(fg) {
            fg = false;
            for(int i=0;i<13;++i) {
                if(ma[i] != 0) {
                    count ++;
                    fg = true;
                    ans *= count - 2*(cou[i]) + 1;
                    cou[i] ++;
                }
            }
        }
        //printf("Case #%d: %lld\n",cas ++,ans);
    }
	return 0;
}

