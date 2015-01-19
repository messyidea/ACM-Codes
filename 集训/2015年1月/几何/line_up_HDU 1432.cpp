/***********************************************\
 |Author: YMC
 |Created Time: 2015-1-19 13:31:19
 |File Name: line_up.cpp
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
Point pp[705];
double li[1000];
//int cou[1000];
int tot;
int n;
int main() {
	//freopen("input.txt","r",stdin); 
    while(scanf("%d",&n) != EOF) {
        rep(i,n) {
            scanf("%lf %lf",&pp[i].x,&pp[i].y);
        }
        Point t1,t2;
        int ans = 2;
        for(int i=0;i<n;++i) {
            tot = 0;
            //memset(cou,0,sizeof(cou));
            for(int j=i+1;j<n;++j) {
                t1 = pp[i];t2 = pp[j];
                if(t1.x > t2.x) swap(t1,t2);
                double k;
                if(fabs(t1.x - t2.x) <= eps) k = inf; 
                else k = (t2.y - t1.y) / (t2.x - t1.x);
                li[tot ++] = k;
                /*bool fg = true;
                for(int ii = 0;ii < tot; ++ ii) {
                    if(fabs(k - li[ii]) < eps) {
                        fg = false;
                        cou[i] ++;
                    }
                }
                if(fg){
                    li[tot ++] = k;
                    cou[tot-1] = 1;
                }*/
            }
            sort(li,li + tot);
            int maxa = -1;
            int now = 1;
            for(int i=1;i<tot;++i) {
                if(fabs(li[i] - li[i-1]) < eps) {
                    now ++;
                } else {
                    if(now > maxa) maxa = now;
                    now = 1;
                }
            }
            if(now > maxa) maxa = now;
            ans = max(ans,maxa + 1);
        }
        //ans = max(ans,2);
        printf("%d\n",ans);
    }
	return 0;
}

