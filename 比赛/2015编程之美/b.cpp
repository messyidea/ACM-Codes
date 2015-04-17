/***********************************************\
 |Author: YMC
 |Created Time: 2015/4/17 20:56:58
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
char s[100];
int len;
ll hash[100][100];
int mod1 = 256;
int mod2 = 999997;
int main() {
	freopen("input.txt","r",stdin); 
    int T;
    int cas = 1;
    scanf("%d",&T);
    while(T--) {
        scanf("%s",s);
        len = strlen(s);
        rep(i,len) {
            for(int j=i+1;j<len;++j) {
                hash[i][j] = ((hash[i][j-1]*mod1)+s[j])%mod2;
            }
        }
        for(int i=len-1;i>=0;--i) {
            for(int j=i-1;j>=0;--j) {
                hash[i][j] = ((hash[i][j+1]*mod1) + s[j])%mod2;
            }
        }
        int count = 0;
        rep(i,len) {
            for(int j=i+1;j<len;++j) {
                if(hash[i][j] == hash[j][i])  {
                    count ++;
                    cout<<i<<"  "<<j<<endl;
                }
            }
        }
        count += len;
        printf("Case #%d: %d\n",cas ++,count);
    }
	return 0;
}

