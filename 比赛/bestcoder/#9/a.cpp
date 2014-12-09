/***********************************************\
 |Author: YMC
 |Created Time: 2014/9/12 19:00:01
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
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    cin>>T;
    int a,b,c;
    while(T--){
        cin>>a>>b>>c;
        int sum = 0;
        int t = 1;
        while(t*a < c){
            int tt = (c - a*t)/b;
            if(t*a + tt*b == c) sum++;
            t++;
        }
        cout<<sum<<endl;
    }
	return 0;
}

