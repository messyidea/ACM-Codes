/***********************************************\
 |Author: YMC
 |Created Time: 2015-1-18 13:13:47
 |File Name: EXOCENTER_OF_A_TRIANGLE.cpp
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
#define srep(i,n) for(i = 1;i <= n;i ++)
#define MP make_pair
const int inf=0x3f3f3f3f ;
const double eps=1e-8 ;
const double pi=acos (-1.0);
typedef long long ll;

using namespace std;
struct Point
{
	double x,y;
	Point(double xx,double yy)
	{
		x=xx;
		y=yy;
	}
	Point()
	{
		x=0;
		y=0;
	}
};
typedef Point Vector;
Vector operator+(Vector A,Vector B)
{
	return Vector(A.x+B.x,A.y+B.y);
}
Vector operator-(Point A,Point B)
{
	return Vector(A.x-B.x,A.y-B.y);
}
Vector operator*(Vector A,double p)
{
	return Vector(A.x*p,A.y*p);
}
Vector operator/(Vector A,double p)
{
	return Vector(A.x/p,A.y/p);
}
Vector operator*(double p,Vector A)
{
	return Vector(A.x*p,A.y*p);
}
Vector operator/(double p,Vector A)
{
	return Vector(A.x/p,A.y/p);
}
bool operator<(const Point& a,const Point& b)
{
	return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
int dcmp(double x)
{
    if(fabs(x)<eps)
    {
        return 0;
    }
    else
    return x<0?-1:1;
}
bool operator==(const Point& a,const Point& b)
{
    return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;
}
double Dot(Vector a,Vector b)
{
	return a.x*b.x+a.y*b.y;
}
double Cross(Vector a,Vector b)
{
	return a.x*b.y-a.y*b.x;
}
struct Line {
    Point p;
    Vector v;
    double ang;
    Line() {}
    Line(Point P,Vector v) : p(P),v(v) {ang = atan2(v.y, v.x);}
    bool operator < (const Line & L) const {
        return ang < L.ang;
    }
};
Point GetLineIntersection(Line a,Line b) {
    Vector u = a.p - b.p;
    double t = Cross(b.v,u) / Cross(a.v,b.v);
    return a.p + a.v * t;
}
Point pp[5];
int main() {
	//freopen("input.txt","r",stdin); 
    int n;
    while(scanf("%d",&n) != EOF) {
        while(n --) {
        rep(i,3) {
            scanf("%lf %lf",&pp[i].x,&pp[i].y);
        }
        Vector tv = pp[2]-pp[1];
        Vector tt = Vector(tv.y,-tv.x);
        Line a = Line(pp[0],tt);
        tv = pp[2] - pp[0];
        tt = Vector(tv.y,-tv.x);
        Line b = Line(pp[1],tt);
        Point ans = GetLineIntersection(a,b);
        printf("%.4lf %.4lf\n",ans.x,ans.y);
    }
    }
	return 0;
}

