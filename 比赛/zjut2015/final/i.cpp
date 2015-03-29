
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string.h>
#include <cmath>
#include <algorithm>
typedef long long ll;
#define inf 0x3f3f3f3f
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
int main() {
    //freopen("input.txt","r",stdin);
    int n;
    double p,r11,r12,r21,r22;
    while(scanf("%d %lf %lf %lf %lf %lf",&n,&p,&r11,&r12,&r21,&r22) != EOF) {
        if(fabs(p - 1.0) <= 1e-9) {
            printf("%.6lf\n",1);
            continue;
        }
        if(fabs(p - 0.0) <= 1e-9) {
            printf("%.6lf\n",0);
            continue;
        }
        double a = p*r11 * (1- r21);
        double b = (1-p)*r12*(1-r22);
        printf("%.6lf\n",a/(a+b));
    }
    return 0;
}
 
/**************************************************************
    Problem: 1555
    User: 2015AK01
    Language: C++
    Result: Accepted
    Time:44 ms
    Memory:1676 kb
****************************************************************/
