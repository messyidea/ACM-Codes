/***********************************************\
 |Author: YMC
 |Created Time: 2014/11/11 23:13:52
 |File Name: b.cpp
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
int ma[105][105];
int mb[105][105];
int n,m;
int main() {
	//freopen("input.txt","r",stdin); 
    //cin>>n>>m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            ma[i][j] = -1;
        }
    }
    srep(i,n) {
        srep(j,m) {
            //cin>>mb[i][j];
            scanf("%d",&mb[i][j]);
            if(mb[i][j] == 0) {
                srep(k,n) {
                    ma[k][j] = 0;
                }
                srep(k,m) {
                    ma[i][k] = 0;
                }
            }
        }
    }
    bool flag = true;
    srep(i,n) {
        srep(j,m) {
            if(mb[i][j] == 1) {
                bool fg = false;
                srep(k,n) {
                    if(ma[k][j] == 0) continue;
                    if(ma[k][j] == -1) {
                        ma[k][j] = 1;
                        fg = true;
                    } else if(ma[k][j] == 1) {
                        fg = true;
                    }
                }
                //cout<<"fg =="<<fg<<endl;
                srep(k,m) {
                    if(ma[i][k] == 0) continue;
                    if(ma[i][k] == -1) {
                        ma[i][k] = 1;
                        fg = true;
                    } else if(ma[i][k] == 1){
                        fg = true;
                    }
                }
                if(!fg) {
                    flag = false;
                    goto Z;
                }
                //cout<<"fg =="<<fg<<endl;
            }
        }
    }
Z:
    ;
    if(!flag) {
        puts("NO");
    } else {
        puts("YES");
        srep(i,n) {
            srep(j,m) {
                if(ma[i][j] == -1) ma[i][j] = 1;
                printf("%d ",ma[i][j]);
            }
            puts("");
        }
    }

	return 0;
}

