/***********************************************\
 |Author: YMC
 |Created Time: 2014/9/26 23:27:07
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
int a[15];
int b[15];
int main() {
	//freopen("input.txt","r",stdin); 
    rep(i,6) {
        cin>>a[i];
        b[a[i]] ++;
    }
    bool fg = false;
    int ans;
    rep(i,6){
        if(b[a[i]] >= 4){ 
            fg = true;
            ans = a[i];
        }
    }
    if(!fg){
        cout<<"Alien"<<endl;
        return 0;
    }
    if(b[ans] == 6){
        cout<<"Elephant"<<endl;
        return 0;
    }
    if(b[ans] == 5){
        cout<<"Bear"<<endl;
        return 0;
    }
    fg = false;
    rep(i,6){
        if(b[a[i]] == 2){
            fg = true;
        }
    }
    if(fg){
        cout<<"Elephant"<<endl;
    }else {
        cout<<"Bear"<<endl;
    }

	return 0;
}

