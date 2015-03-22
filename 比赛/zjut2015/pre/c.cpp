/***********************************************\
 |Author: YMC
 |Created Time: 2015/3/22 12:28:48
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
char s[1000005];
int l,r;
int da[1000005];
int main() {
	//freopen("input.txt","r",stdin); 
    while(scanf("%s",s) != EOF) {
        int len = strlen(s);
        l = 0; r = len-1;
        //cout<<"len == "<<len<<endl;
        for(int i = 0;i<len;++i) {
            if(s[i] == 'l') {
                da[r --] = i;
            } else {
                da[l ++] = i;
            }
        }
        printf("%d",da[0] + 1);
        for(int i = 1;i < len; ++i) {
            printf(" %d",da[i] + 1);
        }
        puts("");

    }
	return 0;
}

