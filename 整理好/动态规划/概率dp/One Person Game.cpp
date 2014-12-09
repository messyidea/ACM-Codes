/***********************************************\
 |Author: YMC
 |Created Time: 2014/7/4 20:35:54
 |File Name: One Person Game.cpp
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

using namespace std;
int n,k1,k2,k3,a,b,c;
double p[505];
double A[505],B[505];
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d%d%d%d",&n,&k1,&k2,&k3,&a,&b,&c);
        memset(p,0,sizeof(p));
        double pp = 1.0/k1/k2/k3;
        for(int i=1;i<=k1;++i){
            for(int j=1;j<=k2;++j){
                for(int k=1;k<=k3;++k){
                    if(i!=a || j!=b || k!=c){
                        p[i+j+k] += pp;
                    }
                }
            }
        }
        memset(A,0,sizeof(A));
        memset(B,0,sizeof(B));
        //A[n] = B[n] = 0;
        for(int i=n;i>=0;--i){
            A[i] = 0;
            B[i] = 0;
            for(int j=1;j<=k1+k2+k3;++j){
                A[i] += p[j]*A[i+j];
                B[i] += p[j]*B[i+j];
            }
            A[i] += pp;
            B[i] += 1;
        }
        printf("%.15lf\n",B[0]/(1-A[0]));
    }
	return 0;
}

