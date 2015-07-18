/***********************************************\
 |Author: YMC
 |Created Time: 2015/7/18 16:31:06
 |File Name: a2.cpp
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
char s[100];
int ma[20] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int mo[20] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int mo2[20] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool isrun(int yyy) {
    if(yyy % 400 == 0) return true;
    if(yyy % 4 == 0 && yyy % 100 != 0) return true;
    return false;
}
int y,m,d,yy,mm,dd,cy,cm,cd,co,cot;
/*int cty(int tt) {
    int sum = 0;
    sum += ma[tt / 1000];
    sum += ma[tt / 100 % 10];
    sum += ma[tt / 10 % 10];
    sum += ma[tt % 10];
    return sum;
}*/
int cty() {
    int sum = 0;
    sum += ma[y / 1000];
    sum += ma[y / 100 % 10];
    sum += ma[y / 10 % 10];
    sum += ma[y % 10];
    sum += ma[m /10 ];
    sum += ma[m % 10];
    sum += ma[d / 10];
    sum += ma[d % 10];
    return sum;
}
int dayplus() {
    d ++;
    if(isrun(y)) {
        if(d > mo[m]) {
            m ++;
            d = 1;
            if(m > 12) {
                y ++;
                m = 1;
                d = 1;
            }
        }
    } else {
        if(d > mo2[m]) {
            m ++;
            d = 1;
            if(m > 12) {
                y ++;
                if(y > 2999) return false;
                m = 1;
                d = 1;
            }
        }
    }
    return true;
}
void start() {
    /*while(y <= 2999) {
        int cy = cty(y);
        int ttt = n - cy;
        if(ttt <= 0 || ttt > 26) continue;
        
    }*/
    if(cty() == n) {
        puts("0");
        return ;
    }
    while(dayplus()) {
        cot ++;
        if(cty() == n) {
            printf("%d\n",cot);
            return ;
        }
    }
    puts("-1");
    return ;
}
void solve() {
    y = (s[0]-'0')*1000 + (s[1]-'0')*100 + (s[2]-'0')*10 + (s[3]-'0')*1;
    m = (s[4]-'0') * 10 + (s[5] - '0') * 1;
    d = (s[6]-'0') * 10 + (s[7] - '0') * 1;
    //cout<<y<<"  "<<m<<"  "<<d<<endl;
    //cy = ma[s[0] - '0'] + ma[s[1] - '0'] + ma[s[2] - '0'] + ma[s[3] - '0'];
    //co = ma[s[4] - '0'] + ma[s[5] - '0'] + ma[s[6] - '0'] + ma[s[7] - '0'];
    start();
}
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    //cout<<T<<endl;
    while(T--) {
        cot = 0;
        scanf("%s",s);
        //printf("%s\n",s);
        scanf("%d",&n);
        //cout<<n<<endl;
        solve();
    }
	return 0;
}

