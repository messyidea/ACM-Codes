
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

struct point
{
	double x,y;
	point(double x=0,double y=0):x(x),y(y){}
	double len(){return fabs(sqrt(x*x+y*y));}
}v,p;

double d,Rm,R,r,x,y,vx,vy,ans;

double dot(point p1,point p2)
{
	return p1.x*p2.x+p1.y*p2.y;
}

double cross(point p1,point p2)
{
	return p1.x*p2.y-p2.x*p1.y;	
}

double dis(point v)
{
	point pv=point(-v.y,v.x);
	return fabs(dot(p,pv)/pv.len());
}

int main()
{
    //freopen("input.txt","r",stdin);
	double l1,l2;
	
	while (~scanf("%lf",&Rm))
	{
		scanf("%lf%lf%lf%lf%lf%lf",&R,&r,&x,&y,&vx,&vy);
		p=point(x,y);
		v=point(vx,vy);
		d=dis(v);   //可以画画看
        //cout<<"d == "<<d<<endl;
		if (d>R+r || dot(v,p)>=0)   //>=0是远离的方向
		{
			printf("%.3lf\n",0);
			continue;
		}
		if (d>=Rm+r && d<=R+r) 
		{
			l1=sqrt((R+r)*(R+r)-d*d);
			ans=2*l1/v.len();
		}
		else
		{
			l1=sqrt((R+r)*(R+r)-d*d);
			l2=sqrt((Rm+r)*(Rm+r)-d*d);
			ans=2*(l1-l2)/v.len();
		}
		printf("%.3lf\n",ans);
	}
}
