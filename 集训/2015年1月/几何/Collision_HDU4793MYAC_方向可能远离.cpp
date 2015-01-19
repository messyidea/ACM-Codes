/***********************************************\
 |Author: YMC
 |Created Time: 2015-1-19 12:46:08
 |File Name: Collision.cpp
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
	//计算点积
	return a.x*b.x+a.y*b.y;
}
double Cross(Vector a,Vector b)
{
	//计算叉积
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
Vector Normal(Vector a)
{
    //计算向量的单位法线，即左转90度，长度归一化。
    //用前确保A不是零向量
    double l=Length(a);
    return Vector(-a.y/l,a.x/l);
}
struct Line
{
    Point v;
    Point p;
    Point point(double a)
    {
        return v+a*(p-v);
    }
};

struct Circle
{
    Point c;
    double r;
    Circle()
    {

    }
    Circle(Point cc,double rr)
    {
        c=cc;
        r=rr;
    }
    Point point(double a)
    {
        //通过圆心角来求坐标
        return Point(c.x+cos(a)*r,c.y+sin(a)*r);
    }
};
int getLineCircleIntersection(Line l,Circle cc,double& t1,double& t2,vector<Point>& sol)
{
    //直线和圆的交点，直线为AB,圆的圆心为C，半径为R，第一种方法是解方程组
    //设交点为P＝A+t*(B-A),代入圆方程整理后先得到 (a*t+b)^2+(c*t+d)^2=r^2
    //进一步整理后得到一元二次方程 e*t^2+f*t+g=0
    //根据判别式的值可以区分3种情况，
    //
    //函数返回的是交点个数，参数sol存放的是交点本身
    //没有清空，可以反复调用函数，把所有的交点放在一个sol里
    //---
    //另一种方法是几何法
    //先求C在AB上的投影P,AB的单位向量V
    //交点P－LV，P+LV，由勾股定理算出
    double a=l.p.x - l.v.x;
    double b=l.v.x;
    double c=l.p.y - l.v.y;
    double d=l.v.y;
    double e=a*a+c*c;
    double f=2*(a*b+c*d);
    double g=b*b+d*d-cc.r*cc.r;
    double delta=f*f-4*e*g;//判别式
    if(dcmp(delta)<0)
    {
        return 0;//相离
    }
    if(dcmp(delta)==0)
    {
        t1=t2=-f/(2*e);
        sol.push_back(l.point(t1));
        return 1;//相切
    }
    t1=(-f-sqrt(delta))/(2*e);
    sol.push_back(l.point(t1));
    t2=(-f+sqrt(delta))/(2*e);                                                                                                                                  
    sol.push_back(l.point(t2));
    return 2;//相交
}

double rm,rr,r,x,y,vx,vy;
double dis2(Point a,Point b) {
    double d = (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
    return d;
}
double DistanceToLine(Point p,Point a,Point b)
{
	//计算点P到直线AB距离
	Point v1=b-a;
	Point v2=p-a;
	return fabs(Cross(v1,v2))/Length(v1);
	//如果不取绝对值，得的是有向距离
}
void pr(Point t) {
    cout<<"point == "<<t.x<<"   "<<t.y<<endl;
}
int main() {
	//freopen("input.txt","r",stdin); 
    while(scanf("%lf %lf %lf %lf %lf %lf %lf",&rm,&rr,&r,&x,&y,&vx,&vy) != EOF) {
        Line ml;
        ml.v.x = x;ml.v.y = y;
        ml.p.x = x + vx  ;
        ml.p.y = y + vy ;
        Circle cen,cen2;
        cen.c.x = 0;cen.c.y = 0;
        cen.r = rm + r;
        vector<Point> vp1,vp2;
        vp1.clear(); vp2.clear();
        Point ppp1,ppp2,ppp3;
        ppp3 = Point(x,y);
        double t1,t2;
        if(Dot(Point(x,y),Point(vx,vy)) >= 0) {
            printf("%lf\n",0.0);
            continue;
        }
        int an = getLineCircleIntersection(ml,cen,t1,t2,vp1);

        if(an == 2) {
            double d1 = dis2(vp1[0],ppp3);
            double d2 = dis2(vp1[1],ppp3);
            if(d1 < d2) ppp1 = vp1[0];
            else ppp1 = vp1[1];
        } else if(an == 1) {
            ppp1 = vp1[0];
        } 
        cen2.c.x = 0;cen2.c.y = 0;
        cen2.r = rr + r;
        int bn = getLineCircleIntersection(ml,cen2,t1,t2,vp2);
        if(bn == 2) {
            double d1 = dis2(vp2[0],ppp3);
            double d2 = dis2(vp2[1],ppp3);
            if(d1 < d2) ppp2 = vp2[0];
            else ppp2 = vp2[1];
        } else if(bn == 1) {
            printf("%lf\n",0.0);
            continue;
        } else {
            printf("%lf\n",0.0);
            continue;
        }
        if(bn == 2 && (an == 0 || an == 1)) {
            double dd = DistanceToLine(Point(0,0),vp2[0],vp2[1]);
            dd = dd * dd;
            dd = cen2.r * cen2.r - dd;
            dd = sqrt(dd);
            dd *= 2;
            dd /= sqrt(vx*vx + vy*vy);
            printf("%lf\n",dd);

        } else {
            double dd = dis2(ppp1,ppp2);
            dd = sqrt(dd);
            dd *= 2;
            dd /= sqrt(vx*vx + vy*vy);
            printf("%lf\n",dd);
        }
    }
	return 0;
}

