
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string.h>
#include <algorithm>
typedef long long ll;
#define inf 0x3f3f3f3f
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
char s[10000];
int a[10000];
int tot;
int main() {
    //freopen("input.txt","r",stdin);
    while(scanf("%s",s) != EOF) {
        int len = strlen(s);
        tot = 0;
        bool fg = true;
        rep(i,len) {
            if(s[i] == '.') {
                a[tot ++] = i;
                continue;
            }
            if(!(s[i] >= '0' && s[i] <= '9')) {
                fg = false;
            }
        }
        if(tot != 3) fg = false;
        int t = 0;
        for(int i=0;i<a[0];++i) {
            t*=10;
            t = t + s[i] - '0';
        }
        if(t<0 || t > 255) {
            fg = false;
            goto Z;
        }
        //cout<<"t == "<<t<<endl;
        t = 0;
        if(s[0] == '0' && a[0] - (-1) != 2) fg = false;
        if(s[a[0]+1] == '0' && a[1]-a[0] != 2) fg = false;
        if(s[a[1] + 1] == '0' && a[2]-a[1] != 2) fg =false;
        if(s[a[2]+1] == '0' && len - a[2] != 2) fg = false;
        if(a[0] == '.') fg = false;
        if(a[1] - a[0] == 1) fg = false;
        if(a[2] - a[1] == 1) fg = false;
        if(len - a[2] == 1) fg = false;
        if(fg == false) goto Z;
        for(int i=a[0]+1;i<a[1];++i) {
            t*=10;
            t+=s[i]-'0';
        }
        if(t<0 || t > 255) {
            fg = false;
            goto Z;
        }
        //cout<<"t == "<<t<<endl;
        t = 0;
        for(int i=a[1]+1;i<a[2];++i) {
            t*=10;
            t+=s[i]-'0';
        }
        if(t<0 || t > 255) {
            fg = false;
            goto Z;
        }
        //cout<<"t == "<<t<<endl;
        t = 0;
        for(int i=a[2]+1;i<len;++i) {
            t*=10;
            t+=s[i]-'0';
        }
        if(t<0 || t > 255) {
            fg = false;
            goto Z;
        }
        //cout<<"t == "<<t<<endl;
 
Z:
        if(fg) puts("Ip");
        else puts("Not");
    }
    return 0;
}
 
/**************************************************************
    Problem: 1552
    User: 2015AK01
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:1724 kb
****************************************************************/
