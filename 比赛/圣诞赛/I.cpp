/***********************************************\
 |Author: YMC
 |Created Time: 2014/12/14 13:57:55
 |File Name: h.cpp
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
const double eps=1e-2 ;
const double pi=acos (-1.0);
typedef long long ll;

using namespace std;
struct Point {
    double x,y;
    Point (double x = 0,double y = 0):x(x),y(y) {}
};
int dcmp(double x) {
	if(fabs(x) < eps) return 0;
	else return x < 0? -1 : 1;
}
typedef Point Vector;
Vector operator - (Point A,Point B) {
    return Vector(A.x - B.x,A.y - B.y);
}
bool operator == (const Point& a,const Point& b) {
	return dcmp(a.x- b.x) == 0 && dcmp(a.y - b.y) == 0;
}

double Dot(Vector A,Vector B) {
	return A.x*B.x + A.y*B.y;
}
double Length(Vector A) {
	return sqrt(Dot(A,A));
}
struct Circle {
    Point c;
    double r;
    
    //Circle (Point c,double r):c(c),r(r){}
    Point point(double a) {
        return Point(c.x + cos(a) * r,c.y + sin(a) * r);
    } 
};
double angle(Vector v) {
    return atan2(v.y,v.x);
}
int getCir(Circle c1,Circle c2,vector<Point> & sol) {
    double d = Length(c1.c - c2.c);
    if(dcmp(d) == 0) {
        if(dcmp(c1.r - c2.r) == 0) return 0;
        return 0;
    }
    if(dcmp(c1.r + c2.r - d) < 0) return 0;
    if(dcmp(fabs(c1.r - c2.r) - d) > 0) return 0;
    double a = angle(c2.c - c1.c) ;
    double da = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
    Point p1 = c1.point(a - da),p2 = c1.point(a + da);
    sol.push_back(p1);
    if(p1 == p2) return 1;
    sol.push_back(p2);
    return 2;
}
bool cmp(Point a,Point b) {
	if(a.x != b.x) return a.x < b.x;
	else return a.y< b.y;
}
int main() {
	//freopen("input.txt","r",stdin); 
	int T;
	scanf("%d",&T);
	double xx1,yy1,xx2,yy2,rr1,rr2;
	while(T--) {
		scanf("%lf %lf %lf %lf %lf %lf",&xx1,&yy1,&rr1,&xx2,&yy2,&rr2);
		Circle a,b;
		a.c = Point(xx1,yy1);
		a.r = rr1;
		b.c = Point(xx2,yy2);
		b.r = rr2;
		vector <Point> tt;
		tt.clear();
		int num = getCir(a,b,tt);
		printf("%d\n",num);
		if(num == 1) {
			printf("%.2lf %.2lf\n",tt[0].x,tt[0].y);
		} else if(num == 2) {
			sort(tt.begin(),tt.end(),cmp);
			printf("%.2lf %.2lf\n",tt[0].x,tt[0].y);
			printf("%.2lf %.2lf\n",tt[1].x,tt[1].y);
		}
	}
	return 0;
}

