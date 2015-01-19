#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
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
//Vector operator/(Vector A,double p)
//{
//	return Vector(A.x/p,A.y/p);
//}
Vector operator*(double p,Vector A)
{
	return Vector(A.x*p,A.y*p);
}
//Vector operator/(double p,Vector A)
//{
//	return Vector(A.x/p,A.y/p);
//}
const double eps = 1e-15;
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
struct Line
{
	Point v;
	Point p;
	Point point(double a)
	{
		return v+a*(p-v);
	}
};
inline double sqr(const double& a) {
	return a * a;
}
void ccl(Point a, Point b, Point o, double r, Point ret[], int& num) {
	double x0 = o.x, y0 = o.y;
	double x1 = a.x, y1 = a.y;
	double x2 = b.x, y2 = b.y;
	double dx = x2 - x1, dy = y2 - y1;
	double A = dx * dx + dy * dy;
	double B = 2 * dx * (x1 - x0) + 2 * dy * (y1 - y0);
	double C = sqr(x1 - x0) + sqr(y1 - y0) - sqr(r);
	double delta = B * B - 4 * A * C;
	num = 0;
	if (dcmp(delta) >= 0) {
		double t1 = (-B - sqrt(delta)) / (2 * A);
		double t2 = (-B + sqrt(delta)) / (2 * A);
		ret[num++] = Point(x1 + t1 * dx, y1 + t1 * dy);
		if (dcmp(delta) != 0) {
			ret[num++] = Point(x1 + t2 * dx, y1 + t2 * dy);
		}
	}
}

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
	double a=l.v.x;
	double b=l.p.x-cc.c.x;
	double c=l.v.y;
	double d=l.p.y-cc.c.y;
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

double ans, t1, t2;
Point pr, pm, pro;
Circle coin, medal, rang, tc;
Vector v;
Line p;
Point o(0.0, 0.0);
vector<Point> cp;
Point cpa[2];
const double pi = acos(-1.0);
int t;

int main(void) {
	medal.c = rang.c = tc.c = o;
	while (cin >> medal.r >> rang.r >> coin.r >> coin.c.x >> coin.c.y >> v.x >> v.y) {
		p.v = coin.c;
		p.p = coin.c + v;
		tc.r = rang.r + coin.r;
		ccl(p.v, p.p, tc.c, tc.r, cpa, t);
		//t = getLineCircleIntersection(p, tc, t1, t2, cp);
		if (fabs(Angle(v, o - coin.c)) > pi / 2.0 || t < 2) {
			ans = 0.0;
		} else {
			pr = Length(cpa[0] - coin.c) < Length(cpa[1] - coin.c) ? cpa[0] : cpa[1];
			pro = pr == cpa[0] ? cpa[1] : cpa[0];
			ans = Length(pro - pr) / Length(v);
			tc.r = medal.r + coin.r;
			ccl(p.v, p.p, tc.c, tc.r, cpa, t);
			//t = getLineCircleIntersection(p, tc, t1, t2, cp);
			if (t == 2) {
				pm = Length(cpa[0] - coin.c) < Length(cpa[1] - coin.c) ? cpa[0] : cpa[1];
				ans = Length(pm - pr) * 2.0 / Length(v);
			}
		}
		printf("%.3f\n", ans);
	}
	return 0;
}
