/***********************************************\
 |Author: YMC
 |Created Time: 2014/10/14 9:03:51
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
int main() {
	//freopen("input.txt","r",stdin); 
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d\n",((a-1) * (6) + 5)*b);
    rep(i,a) {
        printf("%d %d %d %d\n",(6*i+1)*b,(6*i+2)*b,(6*i+3)*b,(6*i+5)*b);
    }
	return 0;
}

