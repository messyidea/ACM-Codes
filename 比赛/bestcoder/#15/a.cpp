/***********************************************\
 |Author: YMC
 |Created Time: 2014/10/25 19:00:37
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
string a,b;
int main() {
	//freopen("input.txt","r",stdin); 
    while(cin>>a>>b) {
        int p1,p2;
        for(int i=0;i<a.length();++i) {
            if(a[i] == '_')  {
                p1 = i;
                break;
            }
        }
        for(int i=0;i<b.length();++i) {
            if(b[i] == '_') {
                p2 = i;
                break;
            }
        }
        string c = a.substr(p1+1);
        string c2 = b.substr(p2+1);
        cout<<c<<"_small_"<<c2<<endl;
    }
	return 0;
}

