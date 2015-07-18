/***********************************************\
 |Author: YMC
 |Created Time: 2015/7/18 13:22:26
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
char ss[1000006];
int t = 0;
int fg = 0;
int fg2 = 0;
char pre;
bool ff;
int main() {
	freopen("input.txt","r",stdin); 
    char c;
    fg = 0;
    fg2 = 0;
    while(~scanf("%c",&c)) {
        //printf("%c\n",c);
        //printf("flag == %d %d\n", fg, fg2);
        if(c == '0' && fg == 0) {
            fg = 1;
            pre = c;
            continue;
        } 
        if(c == 'k' && fg == 1) {
            fg = 2;
            pre = c;
            continue;
        }
        //cout<<"c == "<<c<<endl;
        if(fg == 2) {
            //cout<<"c == "<<c<<endl;
            if((c >= '0' && c <= '9') || (c >= 'A' && c <= 'E')) {
                ss[t ++] = c;
                if(c != '0') fg2 = 1;
            } else {
                ff = false;
                if(fg == 2 && fg2 == 1) {
                    ss[t ++] = 0;
                    printf("0k%s\n",ss);
                    ff = true;
                }
                if(c == 'k' && pre == '0' && !ff) {
                    fg = 2;
                    fg2 = 0;
                    t = 0;
                } else {
                    fg2 = 0;
                    fg = 0;
                    t = 0;
                }
            }
        } else {
            fg = 0;
            fg2 = 0;
            t = 0;
        }
        pre = c;
    }
    if(fg == 2 && fg2 == 1) {
        ss[t ++] = 0;
        printf("0k%s\n",ss);
    }
	return 0;
}

