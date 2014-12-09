/***********************************************\
 |Author: YMC
 |Created Time: 2014/9/12 23:29:49
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
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    int ans = 0;
    if(b*1.0/m > a){
        cout<<a*n<<endl;
        return 0;
    }
    int t = n % m;
    int tt = (n-t)/m;
    if(b > a*t){
        cout<<tt*b + a*t<<endl;
        return 0;
    } else {
        cout<<tt*b + b<<endl;
        return 0;
    }
	return 0;
}

