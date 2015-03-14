/***********************************************\
 |Author: YMC
 |Created Time: 2015/3/14 13:06:26
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
int n;
int da[1000005];
int front,rear;
int tp,a,b,c;
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        front = 0;
        rear = 0;
        while(n --) {
            scanf("%d",&tp);
            if(tp == 1) {
                scanf("%d",&a);
                da[rear ++] = a;
            } else if(tp == 2) {
                if(front == rear) continue;
                front ++;
            } else {
                scanf("%d",&a);
                if(rear - front < a) {
                    puts("na li you zhe me duo ren");
                } else {
                    printf("%d\n",da[front + a - 1]);
                }
            }
        }
    }
	return 0;
}

