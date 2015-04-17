/***********************************************\
 |Author: YMC
 |Created Time: 2015/4/17 21:10:20
 |File Name: a.cpp
 |Description: 
\***********************************************/
#include <iostream>
#include <cstdio>
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
typedef long long ll;

using namespace std;
char mouth[12][12] = {
    "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" , "December"
};
char s1[12],s2[12];
int d1,yy1,d2,yy2,m1,m2;
int ge(char s[12]) {
    rep(i,12) {
        if(strcmp(mouth[i],s) == 0) return i+1;
    }
}
bool isrui(int y) {
    if(y % 4 != 0) return false;
    if(y % 400 == 0) return true;
    if(y % 100 == 0) return false;
    return true;
}
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    int cas = 1;
    int ans;
    scanf("%d",&T);
    while(T--) {
        ans = 0;
        scanf("%s %d, %d",s1,&d1,&yy1);
        scanf("%s %d, %d",s2,&d2,&yy2);
        m1 = ge(s1); m2 = ge(s2);
        if(yy1 == yy2) {
            ans = 0;
            if(isrui(yy1)) {
                if((m1<2 || (m1 == 2 && d1 <= 29)) && (m2>=3 ||(m2 == 2 && d2 >= 29))) ans = 1;
            } 
            printf("Case #%d: %d\n",cas ++,ans);
            continue;
        }
        if(isrui(yy1)) {
            if(m1 < 2) ans ++;
            else if(m1 == 2 && d1 <= 29) ans ++;
        } 
        if(isrui(yy2)) {
            if(m2>=3) ans ++;
            else if(m2==2 && d2 >= 29) ans ++;
        }
        yy1 ++;
        yy2 --;
        /*for(int i=yy1;i<=yy2;++i) {
            if(isrui(i)) ans ++;
        }*/
        while(yy1 <= yy2) {
            if(yy1 % 400 == 0) break;
            if(isrui(yy1)) ans ++;
            yy1 ++;
        }
        while(yy1 <= yy2) {
            if(yy2 % 400 == 0) break;
            if(isrui(yy2)) ans ++;
            yy2 --;
        }
        if(yy1 == yy2) ans ++;
        if(yy2 > yy1) {
            ans += (yy2 - yy1) / 400 * 97;
        }
        printf("Case #%d: %d\n",cas ++,ans);
    }
	return 0;
}

