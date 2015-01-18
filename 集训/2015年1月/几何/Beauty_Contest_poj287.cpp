/***********************************************\
 |Author: YMC
 |Created Time: 2015-1-17 12:02:25
 |File Name: day.cpp
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
const double pi=acos (-1.0);
typedef long long ll;

using namespace std;
struct Point {
    double x,y;
    Point(double x = 0,double y = 0) : x(x),y(y) {}
};
typedef Point Vector;
Vector operator + (Vector A,Vector B) {
    return Vector(A.x + B.x,A.y + B.y);
}
Vector operator - (Vector A,Vector B) {
    return Vector(A.x - B.x,A.y - B.y);
}
Vector operator * (Vector A,double p) {
    return Vector(A.x * p,A.y * p);
}
Vector operator / (Vector A,double p) {
    return Vector(A.x / p,A.y / p);
}
bool operator < (const Point& a,const Point& b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}
const double eps = 1e-10;
int dcmp(double x) {
    if(fabs(x) < eps) return 0;
    else return x < 0 ? -1 : 1;
}
bool operator == (const Point& a,const Point& b) {
    return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}

double Cross (Vector a,Vector b) {
    return a.x * b.y - a.y * b.x;
}
int n,m;
Point pp[50005];
Point pp2[50005];
int Convex(Point pp[5005],int n,Point pp2[50005]) {
    sort(pp,pp+n);
    int m = 0;
    rep(i,n) {
        while(m > 1 && Cross(pp2[m-1]-pp2[m-2],pp[i]-pp2[m-2]) <= 0) m--;
        pp2[m++] = pp[i];
    }
    int k = m;
    for(int i=n-2;i >= 0; i --) {
        while(m > k && Cross(pp2[m-1]-pp2[m-2],pp[i] - pp2[m-2]) <= 0) m --;
        pp2[m ++] = pp[i];
    }
    if(n > 1) m --;
    return m;

}
inline double dis(Point a,Point b) {
    double d =  (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
    return d;
}
double diameter(Point o[50005],int n,Point p[50005]){
    //求点集直径(最大距离),旋转卡壳
    int num=Convex(o,n,p);
    int mi=0,ma=0;
    for(int q=0;q<num;q++){
        if(p[q]<p[mi])mi=q;
        if(p[ma]<p[q])ma=q;
    }
    int v=ma;
    double ans=(p[mi].x-p[ma].x)*(p[mi].x-p[ma].x)+(p[mi].y-p[ma].y)*(p[mi].y-p[ma].y);
    ans=max(ans,(p[num-1].x-p[ma].x)*(p[num-1].x-p[ma].x)+(p[num-1].y-p[ma].y)*(p[num-1].y-p[ma].y));
    ans=max(ans,(p[mi].x-p[ma-1].x)*(p[mi].x-p[ma-1].x)+(p[mi].y-p[ma-1].y)*(p[mi].y-p[ma-1].y));
    ans=max(ans,(p[num-1].x-p[ma-1].x)*(p[num-1].x-p[ma-1].x)+(p[num-1].y-p[ma-1].y)*(p[num-1].y-p[ma-1].y));
    for(;mi<v;mi++){
        for(;;){
            int a=dcmp(Cross(p[mi+1]-p[mi],p[ma+1]-p[ma]));
            if(a==0){
                ans=max(ans,(p[mi].x-p[ma].x)*(p[mi].x-p[ma].x)+(p[mi].y-p[ma].y)*(p[mi].y-p[ma].y));
                ans=max(ans,(p[mi+1].x-p[ma].x)*(p[mi+1].x-p[ma].x)+(p[mi+1].y-p[ma].y)*(p[mi+1].y-p[ma].y));
                ans=max(ans,(p[mi].x-p[ma+1].x)*(p[mi].x-p[ma+1].x)+(p[mi].y-p[ma+1].y)*(p[mi].y-p[ma+1].y));
                ans=max(ans,(p[mi+1].x-p[ma+1].x)*(p[mi+1].x-p[ma+1].x)+(p[mi+1].y-p[ma+1].y)*(p[mi+1].y-p[ma+1].y));
                ma++;
                break;
            }
            if(a>0){
                ans=max(ans,(p[mi].x-p[ma].x)*(p[mi].x-p[ma].x)+(p[mi].y-p[ma].y)*(p[mi].y-p[ma].y));
                ans=max(ans,(p[mi].x-p[ma+1].x)*(p[mi].x-p[ma+1].x)+(p[mi].y-p[ma+1].y)*(p[mi].y-p[ma+1].y));
                ma++;
            }
            if(a<0){
                ans=max(ans,(p[mi+1].x-p[ma].x)*(p[mi+1].x-p[ma].x)+(p[mi+1].y-p[ma].y)*(p[mi+1].y-p[ma].y));
                ans=max(ans,(p[mi+1].x-p[ma+1].x)*(p[mi+1].x-p[ma+1].x)+(p[mi+1].y-p[ma+1].y)*(p[mi+1].y-p[ma+1].y));
                break;
            }
        }
    }
    return ans;
}

int main() {
	//freopen("input.txt","r",stdin); 
    while(scanf("%d",&n) != EOF) {
        rep(i,n) scanf("%lf %lf",&pp[i].x,&pp[i].y);
        double ans = diameter(pp,n,pp2); 
        int anss = ans + eps;
        printf("%d\n",anss);
    }
	return 0;
}


