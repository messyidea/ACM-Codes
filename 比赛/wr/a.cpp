/***********************************************\
 |Author: YMC
 |Created Time: 2015/8/2 19:08:34
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
string s;
int len;
char buffer[9000];
int tot;
bool isFirst;
bool lue;
inline bool isletter(char a) {
    if(a >= 'a' && a <= 'z') return true;
    if(a >= 'A' && a <= 'Z') return true;
    return false;
} 
inline char bebig(char a) {
    if(a >= 'a' && a <= 'z') a += 'A' - 'a';
    return a;
}
inline char besmall(char a) {
    if(a >= 'A' && a <= 'Z') a += 'a' - 'A';
    return a;
}
int main() {
	//freopen("input.txt","r",stdin); 
    while(getline(cin,s)) {
        len = s.length();
        tot = 0;
        isFirst = true;
        lue = false;
        rep(i,len) {
            if(s[i] == ' ') {
                if(lue) {
                    continue;
                }
                if(!isFirst) {
                    buffer[tot ++] = 0;
                    printf("%s",buffer);
                    lue = true;
                    tot = 0;
                }
            } else if(isletter(s[i])) {
                if(lue) {
                    lue = false;
                    printf(" ");
                }
                if(isFirst) {
                    buffer[tot ++] = bebig(s[i]);
                    isFirst = false;
                } else {
                    buffer[tot ++] = besmall(s[i]);
                }
            } else {
                if(tot != 0) {
                    buffer[tot ++] = 0;
                    printf("%s",buffer);
                    tot = 0;
                }
                if(s[i] == '.') {
                    isFirst = true;
                }
                printf("%c",s[i]);
                lue = true;
            }

        }
        puts("");
    }
	return 0;
}

