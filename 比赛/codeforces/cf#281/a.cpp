/***********************************************\
 |Author: YMC
 |Created Time: 2014/12/9 18:42:29
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
char home[25];
char away[25];
int ho[100];
int aw[100];
int main() {
	//freopen("input.txt","r",stdin); 
    memset(ho,0,sizeof(ho));
    memset(aw,0,sizeof(aw));
    scanf("%s %s",home,away);
    int n;
    scanf("%d",&n);
    int a,b;
    char c,d;
    rep(i,n) {
        scanf("%d %c %d %c",&a,&c,&b,&d);
        {
            if(c == 'h') {
                if(ho[b] == 3) continue;
                if(d == 'r' && ho[b] != 3) {
                    ho[b] = 3;
                    printf("%s %d %d\n",home,b,a);
                    continue;
                }
                if(ho[b] == 1 && d == 'y') {
                    ho[b] = 3;
                    printf("%s %d %d\n",home,b,a);
                } else if(d == 'y'){
                    ho[b] = 1;
                    continue;
                }
            } else {
                if(aw[b] == 3) continue;
                if(d == 'r' && aw[b] != 3) {
                    aw[b] = 3;
                    printf("%s %d %d\n",away,b,a);
                    continue;
                }
                if(aw[b] == 1 && d == 'y') {
                    aw[b] = 3;
                    printf("%s %d %d\n",away,b,a);
                } else if(d == 'y'){
                    aw[b] = 1;
                    continue;
                }
                
            }
            
        }

    }
	return 0;
}

