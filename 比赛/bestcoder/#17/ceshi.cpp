/***********************************************\
 |Author: YMC
 |Created Time: 2014/11/8 23:06:10
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
#include <ctime>
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
    freopen("input.txt","w",stdout); 
    srand(time(0));
    int t = 25;
    cout<<t<<endl;
    while(t --) {
        int n = rand()%100;
        int k = rand()%100;
        cout<<n<<" "<<k<<endl;
        while(n --) {
            int tt = rand()%100;
            cout<<tt<<" ";
            while(tt --) {
                cout<<rand() % 100<<"  ";
            }
            cout<<endl;
        }

    }
	return 0;
}

