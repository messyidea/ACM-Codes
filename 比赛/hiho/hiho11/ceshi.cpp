/***********************************************\
 |Author: YMC
 |Created Time: 2015/5/3 19:19:28
 |File Name: ceshi.cpp
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
int da[100];
int coun;
int sum;
void dfs(int t) {
    //cout<<"t == "<<t<<endl;
    if(t == 10) {
        sum += da[t-1];
        //cout<<"dat-1 == "<<da[t-1]<<endl;
        coun ++;
        return ;
    }
    for(int i=1;i<t;++i) {
        for(int j=1;j<t;++j) {
            da[t] = da[i] + da[j];
            dfs(t+1);
        }
    }
}
int main() {
	//freopen("input.txt","r",stdin); 
    da[1] = 1;
    da[2] = 2;
    coun = 0;
    sum = 0;
    dfs(3);
    printf("%lf\n",sum * 1.0 / coun);
	return 0;
}

