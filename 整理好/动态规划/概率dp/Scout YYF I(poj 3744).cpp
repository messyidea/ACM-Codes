/***********************************************\
 |Author: YMC
 |Created Time: 2014/7/4 19:03:33
 |File Name: Scout YYF I.cpp
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
#define rep(i,n) for(int i=0;i<n;++i)
struct metric{
    double mat[2][2];
};
metric mul(metric a,metric b){
    metric ret;
    for(int i=0;i<2;++i){
        for(int j=0;j<2;++j){
            ret.mat[i][j] = 0;
            for(int k=0;k<2;++k){
                ret.mat[i][j] += a.mat[i][k]*b.mat[k][j];
            }
        }
    }
    return ret;
}
metric m_pow(metric x,long long t){
    metric ret;
    memset(ret.mat,0,sizeof(ret.mat));
    for(int i=0;i<2;++i) ret.mat[i][i] = 1;
    while(t > 0){
        if(t & 1) ret = mul(ret,x);
        x = mul(x,x);
        t >>= 1;
    }
    return ret;
}
int n;
double p;
int data[15];
double cal(int i,int j){
    i++;
    metric a;
    a.mat[0][0] = p;
    a.mat[0][1] = 1-p;
    a.mat[1][0] = 1;
    a.mat[1][1] = 0;
    metric me = m_pow(a,j-i);
    return 1-me.mat[0][0];
}
int main() {
	//freopen("input.txt","r",stdin); 
    while(cin>>n>>p){
        rep(i,n){
            cin>>data[i];
        }
        sort(data,data+n);
        double ret = 0;
        ret = cal(0,data[0]);
        for(int i=0;i<n-1;++i){
            ret *= cal(data[i],data[i+1]);
        }
        printf("%.7f\n",ret);
    } 
	return 0;
}

