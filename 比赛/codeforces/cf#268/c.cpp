/***********************************************\
 |Author: YMC
 |Created Time: 2014/9/20 21:29:29
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
int main() {
	//freopen("input.txt","r",stdin); 
    int n;
    scanf("%d",&n);
    if(n <= 3){
        puts("NO");
        return 0;
    } else {
        puts("YES");
        if(n % 2 == 0){
            puts("4 * 3 = 12");
            puts("12 * 2 = 24");
            puts("24 * 1 = 24");
            bool fg = false;
            for(int i=n;i>=6;i-=2){
                fg = true;
                printf("%d - %d = 1\n",i,i-1);
            }
            int t = (n - 4) / 2 - 1;
            for(int i=0;i<t;++i){
                puts("1 * 1 = 1");
            }
            if(fg)
            puts("1 * 24 = 24");
        } else {
            puts("5 * 4 = 20");
            puts("20 + 3 = 23");
            puts("2 - 1 = 1");
            puts("23 + 1 = 24");
            bool fg = false;
            for(int i=n;i>=7;i-=2){
                fg = true;
                printf("%d - %d = 1\n",i,i-1);
            }
            int t = (n - 5) / 2 - 1;
            for(int i=0;i<t;++i){
                puts("1 * 1 = 1");
            }
            if(fg)
            puts("1 * 24 = 24"); 
        }
    }

	return 0;
}

