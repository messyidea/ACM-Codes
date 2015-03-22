/***********************************************\
 |Author: YMC
 |Created Time: 2015/3/22 12:52:16
 |File Name: e.cpp
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
int p,g,m,gg,pp;
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d %d",&p,&g,&m);
        int sum = 0;
        if(g >= 20) {
            sum += 80*20;
        } else {
            sum += g * 80;
        }
        if(g >= 50) {
            sum += 132 * 30;
        } else if(g >= 20){
            sum += 132 * (g - 20);
        }
        if(g >= 100) {
            sum += 186 * 50;
            sum += (g - 100) * 240;
        } else if(g >= 50){
            sum += 186 *(g - 50);
        }
        
        if(p + g >= 20) {
            if(g < 20) {
                sum += (20 - g) * 200;
            }
        } else {
            sum += p * 200;
        }

        if(p + g >= 50) {
            if(g < 50) {
                sum += (50 - max(g,20)) * 332;
            }
        } else if(p + g >= 20) {
            if(g > 20) {
                sum += p * 332;
            } else {
                sum += (p+g-20)*332;
            }
        }

        if(p + g >= 100) {
            if(g <= 100) {
                sum += (100 - max(g,50)) * 466;
                sum += (p + g - 100) * 600;
            } else {
                sum += (p) * 600;
            }
        } else if(p + g >= 50) {
            if(g > 50) {
                sum += p * 466;
            } else {
                sum += (p + g - 50) * 466;
            }
        }
        printf("%d\n",sum);


    }
	return 0;
}

