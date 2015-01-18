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
double Length(Vector a)
{
    //计算长度
	return sqrt(Dot(a,a));
}
double Angle(Vector A,Vector B)
{
    //计算AB夹角
    return acos(Dot(A,B)/Length(A)/Length(B));
}
double Area2(Point A,Point B,Point C)
{
    //计算三角形ABC的面积的二倍
    return Cross(B-A,C-A);
}
Vector Rotate(Vector a,double rad)
{
    //向量逆时针旋转rad角
    //rad弧度
    return Vector(a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad));
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
void danwei(Vector& j) {
    double t = j.x*j.x + j.y*j.y;
    t = sqrt(t);
    j.x /= t;
    j.y /= t;
}
double DistanceToLine(Point p,Point a,Point b)
{
	//计算点P到直线AB距离
	Point v1=b-a;
	Point v2=p-a;
	return fabs(Cross(v1,v2))/Length(v1);
	//如果不取绝对值，得的是有向距离
}
inline double dis(Point a,Point b) {
    double d =  (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
    return sqrt(d);
}
Point pp[5];
int main() {
	//freopen("input.txt","r",stdin); 
    int n;
    while(scanf("%lf %lf %lf %lf %lf %lf",&pp[0].x,&pp[0].y,&pp[1].x,&pp[1].y,&pp[2].x,&pp[2].y) != EOF) {
        Vector j1,j2;
        j1 = pp[1] - pp[0];
        j2.x = j1.y;
        j2.y = -j1.x;
        Line aaa = Line((pp[0] + pp[1])/2,j2);
        j1 = pp[2] - pp[1];
        j2.x = j1.y;
        j2.y = -j1.x;
        Line bbb = Line((pp[1] + pp[2])/2,j2);
        Point cen = GetLineIntersection(aaa,bbb);
        //cout<<cen.x<<"  "<<cen.y<<endl; 
        double rr = dis(pp[1],cen);
        //cout<<rr<<endl;
        double a = cen.x,b = cen.y;
        if(a >= 0 && b >= 0) {
            printf("(x - %.3lf)^2 + (y - %.3lf)^2 = %.3lf^2\n",cen.x,cen.y,rr);
        } else if(a >= 0 && b < 0) {
            printf("(x - %.3lf)^2 + (y + %.3lf)^2 = %.3lf^2\n",cen.x,-cen.y,rr);
        } else if(a < 0 && b >= 0) {
            printf("(x + %.3lf)^2 + (y - %.3lf)^2 = %.3lf^2\n",-cen.x,cen.y,rr);
        } else {
            printf("(x + %.3lf)^2 + (y + %.3lf)^2 = %.3lf^2\n",-cen.x,-cen.y,rr);
        }
        double aa = -2.0 * cen.x,bb = -2.0 * cen.y,cc = cen.x*cen.x + cen.y*cen.y - rr*rr;
        printf("x^2 + y^2");
        if(aa >= 0) printf(" + %.3lfx",aa);
        else if(aa < 0) printf(" - %.3lfx",-aa);
        if(bb >= 0) printf(" + %.3lfy",bb);
        else if(bb < 0) printf(" - %.3lfy",-bb);
        if(cc >= 0) printf(" + %.3lf",cc);
        else if(cc < 0) printf(" - %.3lf",-cc);
        puts(" = 0");
        puts("");
//(x - 3.000)^2 + (y + 2.000)^2 = 5.000^2
//x^2 + y^2 - 6.000x + 4.000y - 12.000 = 0
        

    }
	return 0;
}

