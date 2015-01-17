
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
Point pp[1005];
Point pp2[1005];
int Convex(int n) {
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
    return sqrt(d);
}
int main() {
	//freopen("input.txt","r",stdin); 
    while(scanf("%d %d",&n,&m) != EOF) {
        rep(i,n) scanf("%lf %lf",&pp[i].x,&pp[i].y);
        int mm = Convex(n);
        double all = 0;
        //rep(i,mm+1) printf("%lf %lf\n",pp2[i].x,pp2[i].y);
        for(int i=1;i<=mm;++i) {
            all += dis(pp2[i],pp2[i-1]);
        }
        all += 2 * pi * m;
        int alln = all + 0.5;
        printf("%d\n",alln);
    }
	return 0;
}
