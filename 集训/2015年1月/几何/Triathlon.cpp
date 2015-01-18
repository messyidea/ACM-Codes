/***********************************************\
 |Author: YMC
 |Created Time: 2015-1-18 12:18:25
 |File Name: a.cpp
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
bool OnLeft(Line L,Point p) {
    return Cross(L.v,p-L.p) > 0;
}
Point GetLineIntersection(Line a,Line b) {
    Vector u = a.p - b.p;
    double t = Cross(b.v,u) / Cross(a.v,b.v);
    return a.p + a.v * t;
}
int HalfplaneIntersection(Line l[110],int n,Point poly[110]){
    sort(l,l+n);
    int first,last;
    Point *p=new Point[n];Line *q=new Line[n];
    q[first=last=0]=l[0];
    for(int i=1;i<n;i++){
        while(first<last&&!OnLeft(l[i],p[last-1]))last--;
        while(first<last&&!OnLeft(l[i],p[first]))first++;
        q[++last]=l[i];
        if(fabs(Cross(q[last].v,q[last-1].v))<eps){
            last--;
            if(OnLeft(q[last],l[i].p))q[last]=l[i];
        }
        if(first<last)p[last-1]=GetLineIntersection(q[last-1],q[last]);
    }
    while(first<last&&!OnLeft(q[first],p[last-1]))last--;
    if(last-first<=1)return 0;
    p[last]=GetLineIntersection(q[last],q[first]);
    int m=0;
    for(int i=first;i<=last;i++)poly[m++]=p[i];
    return m;
}
Point poly[110];
Line L[110];
int V[110],U[110],W[110];
int main() {
	//freopen("input.txt","r",stdin); 
    int n;
    while(scanf("%d",&n) != EOF) {
        rep(i,n) scanf("%d %d %d",&V[i],&U[i],&W[i]);
        rep(i,n) {
            bool flag = true;
            int tot = 0;
            double k = 10000;
            rep(j,n) {
                if(i != j) {
                if(V[i] <= V[j] && U[i] <= U[j] && W[i] <= W[j]) {
                    flag = false;
                    break;
                }
                if(V[i] >= V[j] && U[i] >= U[j] && W[i] >= W[j]) continue;  //已经消除了全等于的情况
                //double a = (W[j] - V[j]) / (W[j] * V[j]) - (W[i] - V[i]) / (W[i] * V[i]);
                //double b = (W[j] - U[j]) / (W[j] * U[j]) - (W[i] - U[i]) / (W[i] * U[j]);
                //double c = (W[i] - W[j]) / (W[i] * W[j]);
                double a = (k / V[j] - k / W[j]) - (k / V[i] - k / W[i]);
                double b = (k / U[j] - k / W[j]) - (k / U[i] - k / W[i]);
                double c = k / W[j] - k / W[i];
                Point P;
                Vector v(b,-a);
                if(fabs(a) > fabs(b)) P = Point(-c/a,0);
                else P = Point(0,-c/b);
                L[tot ++] = Line(P,v);
                }
            }
            if(flag) {
                L[tot ++] = Line(Point(0,0),Vector(0,-1));
                L[tot ++] = Line(Point(0,0),Vector(1,0));
                L[tot ++] = Line(Point(0,1),Vector(-1,1));
                if(!HalfplaneIntersection(L,tot,poly)) flag = false;
            }    
            if(flag) puts("Yes");
            else puts("No");
        }
    }
	return 0;
}

