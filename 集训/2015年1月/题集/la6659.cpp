
/***********************************************\
 |Author: YMC
 |Created Time: 2015-1-23 12:59:50
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
#define srep(i,n) for(i = 1;i <= n;i ++)
#define MP make_pair
const int inf=0x3f3f3f3f ;
const double eps=1e-8 ;
const double pi=acos (-1.0);
typedef long long ll;

using namespace std;
char s[1005];
map<char,int> ma;
int len = 0;
int cnt,sum;
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    int ha = 1;
    while(T--) {
        scanf("%s",s);
        len = strlen(s);
        sum = 0;
        for(int i=0;i<len;++i) {
            cnt = 0;
            ma.clear();
            for(int j=i;j<len;++j) {
                ma[s[j]] ++;
                if(ma[s[j]] % 2 == 1) cnt++;
                else cnt --;
                if(cnt == 1 || cnt == 0) sum++;
            }
        }
        printf("Case %d: %d\n",ha ++,sum);
    }
	return 0;
}
