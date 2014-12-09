/***********************************************\
 |Author: YMC
 |Created Time: 2014/11/23 19:05:46
 |File Name: e.cpp
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
char s[100005][10];
int num[100005];
int len[100005];
int ttt[15];
int kk[15] = {1,10,100,1000,10000,100000,1000000,10000000,100000000};
int main() {
	//freopen("input.txt","r",stdin); 
    scanf("%d",&n);
    int maxn = -1;
    bool fg = true;
    rep(i,n) {
        scanf("%s",s[i]);
        len[i] = strlen(s[i]);
        if(len[i] >= maxn) maxn = len[i];
        else fg = false;
    }
    if(fg == false) {
        puts("NO");
        return 0;
    }
    int p = 0;
    if(s[0][0] == '?') s[0][0] = '1';
    for(int i=1;i<len[0];++i) {
        if(s[0][i] == '?') {
            s[0][i] = '0';
        }
    }
    int t;
    bool flag = true;
    for(int i=1;i<n;++i) {
        //printf("%s\n",s[i-1]);
        if(len[i] > len[i-1]) {
            if(s[i][0] == '?') s[i][0] = '1';
            rep(j,len[i]) {
                if(s[i][j] == '?') s[i][j] = '0';
            }
            continue;
        }
        /*while(now < num[i-1]) {
            for(int j=0;i<len[i];++j) {
                if(s[i][j] == '?'){
                    for(int k=9;k >= 0;--k) {
                        if(now + k * kk[len[i] - j - 1] <= num[i-1]){
                            now += k * kk[len[i] - j - 1];
                            ttt[j] = k;
                            break; 
                        }
                    }
                }
            }
            for(int j = len[i-1];j >= 0;--j) {
                if(s[i][j] == '?') {
                    for(int k = ttt[j]+1;k <= 9; ++k) {
                        if(now + (k - ttt[j])*kk[len[i] - j - 1] > num[i-1]) {
                            now += (k - ttt[j])*kk[len[i] - j - 1];
                        }
                    }
                }
            }
            for(int i=)
        }*/
        bool ff = true;
        int fff = -1;
        int tf[10];
        int tott = 0;
        int haha = -1;
        bool sf = false;
        bool bf = false;
        for(int j=0;j<len[i];++j) {
            if(s[i][j] == s[i-1][j]) continue;
            if(s[i][j] == '?') {
                ttt[j] = s[i-1][j];
                if(s[i-1][j] != '9') {
                    fff = j;
                }
                haha = j;
                bf = true;
                tf[tott ++] = j;
            } else if(s[i][j] > s[i-1][j] && ff) {
                haha = j;
                bf = false;
                break;
            } else {
                haha = fff;
                sf = true;
                break;
            }
        }
        if(haha == -1) {
            //cout<<i<<endl;
            flag = false;
            break;
        }
        if(sf == true || bf) {
            for(int j=0;j<=haha;++j) {
                if(s[i][j] == '?') s[i][j] = s[i-1][j];
            }
            s[i][fff] ++;
            for(int j=haha+1;j<len[i];++j) {
                if(s[i][j] == '?') s[i][j] = '0';
            }
        } else {
            for(int j=0;j<=haha;++j) {
                if(s[i][j] == '?') s[i][j] = s[i-1][j];
            }
            for(int j=haha+1;j<len[i];++j) {
                if(s[i][j] == '?') s[i][j] = '0';
            }
        }
    }
    if(!flag) {
        puts("NO");
    } else {
        puts("YES");
        rep(i,n) {
            printf("%s\n",s[i]);
        }
    }
	return 0;
}

