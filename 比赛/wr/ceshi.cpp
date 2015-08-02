/***********************************************\
 |Author: YMC
 |Created Time: 2015/8/2 19:39:45
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
list<int> a;
void show() {
    list<int>::iterator it = a.begin();
    while(it != a.end()) {
        printf("%d\n",*it);
        it ++;
    }
}
int main() {
	//freopen("input.txt","r",stdin);
    a.push_back(1);
    a.push_back(2);
    a.insert(++a.begin(),3);

    show();
	return 0;
}

