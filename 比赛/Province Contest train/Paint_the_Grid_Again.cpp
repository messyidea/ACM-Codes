/***********************************************\
 |Author: YMC
 |Created Time: 2015/4/5 20:15:01
 |File Name: Paint_the_Grid_Again.cpp
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
int n;
char s[505][505];
stack <pair<char,int> > st;
bool done() {
    srep(i,n) {
        srep(j,n) {
            if(s[i][j] != '-') return false;
        }
    }
    return true;
}
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        srep(i,n) {
            scanf("%s",s[i]+1);
        }
        /*srep(i,n) {
            srep(j,n) {
                printf("%c",s[i][j]);
            }
            puts("");
        }*/
        //st.clear();
        while(!st.empty()) st.pop();
        int tar;
        bool fg;
        bool fg2;   //有没有新进展
        bool fg3 = true;
        bool fg4;
        while(!done()) {
            fg2 = false;
            for(int i=n;i>=1;--i) {
                fg = true;
                fg4 = false;
                srep(j,n) {
                    if(s[i][j] != '-') fg4 = true;
                    if(s[i][j] == 'O') fg = false;
                }
                if(fg && fg4) {
                    fg2 = true;
                    srep(j,n) {
                        s[i][j] = '-';
                    }
                    st.push(MP('R',i));
                }
            }
            for(int i=n;i>=1;--i) {
                fg = true;
                fg4 = false;
                srep(j,n) {
                    if(s[j][i] != '-') fg4 = true;
                    if(s[j][i] == 'X') fg = false;
                }
                if(fg && fg4) {
                    fg2 = true;
                    srep(j,n) {
                        s[j][i] = '-';
                    }
                    st.push(MP('C',i));
                }
            }
            if(!fg2) {
                fg3 = false;
                break;
            }
        }
        pair<int,int> pp;
        if(fg3 == false) {
            puts("No solution");
        } else {
            pp = st.top();
            st.pop();
            printf("%c%d",pp.first,pp.second);
            while(!st.empty()) {
                pp = st.top();
                st.pop();
                printf(" %c%d",pp.first,pp.second);
            }
            puts("");
        }
    }
	return 0;
}

