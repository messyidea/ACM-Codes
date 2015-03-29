
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;++i)
#define srep(i,n) for(int i=1;i<=n;++i)
#define inf 0x3f3f3f3f
typedef long long ll;
using namespace std;
char s[10000];
int cal(char a) {
    if(a == '0') return 1;
    if(a == '6') return 1;
    if(a == '8') return 2;
    if(a == '9') return 1;
    return 0;
}
int main() {
    //freopen("input.txt","r",stdin);
    while(scanf("%s",s) != EOF) {
        int len = strlen(s);
        int sum = 0;
        rep(i,len) {
            sum += cal(s[i]);
        }
        printf("%d\n",sum);
    }
    return 0;
}
 
/**************************************************************
    Problem: 1564
    User: 2015AK01
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:1684 kb
****************************************************************/
