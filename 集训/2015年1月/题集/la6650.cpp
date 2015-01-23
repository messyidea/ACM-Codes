
/***********************************************\
 |Author: YMC
 |Created Time: 2015-1-23 12:20:49
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
#define srep(i,n) for(i = 1;i <= n;i ++)
#define MP make_pair
const int inf=0x3f3f3f3f ;
const double eps=1e-8 ;
const double pi=acos (-1.0);
typedef long long ll;

using namespace std;
int n;
struct Ant{
    int x,y,z;
}ant[105];
bool cmp(Ant a,Ant b) {
    if(a.z != b.z) return a.z > b.z;
    int aa = a.x * a.y * a.z;
    int bb = b.x * b.y * b.z;
    return aa > bb;
}
int main() {
	//freopen("input.txt","r",stdin); 
    while(scanf("%d",&n) && n) {
        rep(i,n) {
            scanf("%d %d %d",&ant[i].x,&ant[i].y,&ant[i].z);
        }
        sort(ant,ant+n,cmp);
        printf("%d\n",ant[0].x * ant[0].y * ant[0].z);
    }
	return 0;
}
