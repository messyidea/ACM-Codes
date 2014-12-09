/***********************************************\
 |Author: YMC
 |Created Time: 2014/7/11 22:23:43
 |File Name: Police and Thief.cpp
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

#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
const double EPS = 1E-8;
typedef vector<double> vec;
typedef vector<vec> mat;
vec gauss_jordan(const mat& A,const vec& b){
    int n = A.size();
    mat B(n,vec(n+1));
    rep(i,n) rep(j,n) B[i][j] = A[i][j];
    rep(i,n) B[i][n] = b[i];
    rep(i,n){
        int piort = i;
        for(int j=i;j<n;++j) if(abs(B[j][i]) > abs(B[piort][i])) piort = j;
        swap(B[i],B[piort]);
        if(abs(B[i][i]) < EPS) return vec();
        for(int j=i+1;j<=n;++j) B[i][j] /= B[i][i];
        rep(j,n){
            if(i != j){
                for(int k=i+1;k<=n;++k) B[j][k] -= B[j][i]*B[i][k];
            }
        }
    }
    vec x(n);
    for(int i=0;i<n;++i) x[i] = B[i][n];
    return x;
}
int n,p;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
bool isok(int x,int y){
    if(x < 0 || x>=n) return false;
    if(y < 0 || y>=n) return false;
    return true;
}
double ga[100];
bool cmp(double a,double b){
	return a>b;
}
int main() {
	freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&p);
        mat A(n*n,vec(n*n,0));
        vec b(n*n,0);
        int move = 0;
        rep(x,n){
            rep(y,n){
            	//if(x == n-1 && y== n-1)
                rep(k,4){
                    int move = 0;
                    int xx = x + dx[k];
                    int yy = y + dy[k];
                    if(xx>=0 && yy>=0){
                        if(xx >= n) xx = 2*n - xx;
                        if(yy >= n) yy = 2*n - yy;
                        A[x*n+y][xx*n+yy] = -1;
                        move ++;
                    }
                }
                b[x*n+y] = A[x*n+y][x*n+y] = move;
            }
        }
        vec res = gauss_jordan(A,b);
        //cout<<res.size()<<endl;
        int cnt = 0;
        for(int i=0;i<n;++i){
        	ga[cnt++] = res[i]*1/4;
        	ga[cnt++] = res[i]*1/4;
        	ga[cnt++] = res[i]*1/4;
        	ga[cnt++] = res[i]*1/4;
        }
        sort(ga,ga+cnt,cmp);
        int pos = 0;
        for(int i=0;i<cnt;++i){
        	if(p <= 0){
	        	pos = i;break;
	        }
	        else{
        		p -= ga[i]*100;
        	}
        }
        printf("%d\n",pos+1);
    }
	return 0;
}

