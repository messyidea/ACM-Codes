
/***********************************************\
 |Author: YMC
 |Created Time: 2015-1-17 13:54:46
 |File Name: san.cpp
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
int xx1,yy1,xx2,yy2,xx3,yy3;
int gcd(int a,int b) {
    return b == 0 ? a : gcd(b, a%b);
}
int ge(int xx1,int yy1,int xx2,int yy2) {
    int t = abs(xx2 - xx1);
    int t2 = abs(yy2 - yy1);
    return gcd(t,t2);
}
int main() {
	//freopen("input.txt","r",stdin); 
    while(scanf("%d %d %d %d %d %d",&xx1,&yy1,&xx2,&yy2,&xx3,&yy3)!=EOF) {
       if(xx1 == 0 && xx2 == 0 && xx3 == 0 && yy1 == 0 && yy2 == 0 && yy3 == 0) break;
       Point a,b,c;
       a.x = xx1,a.y = yy1;
       b.x = xx2,b.y = yy2;
       c.x = xx3,c.y = yy3;
       Vector aa = c-a;
       Vector vv = b-a;
       double ss = Cross(aa,vv);
       ss = fabs(ss) / 2;
       //cout<<ss<<endl;
       ss += 1;
       int aa1 = ge(xx1,yy1,xx2,yy2);
       int aa2 = ge(xx1,yy1,xx3,yy3);
       int aa3 = ge(xx2,yy2,xx3,yy3);
       int all = aa1 + aa2 + aa3 ;
       double all2 = all * 1.0 / 2;
       //cout<<"all2 == "<<all2<<endl;
       ss -= all2;
       //cout<<ss<<endl;
       int ans = ss + eps;
       printf("%d\n",ans);
    }
	return 0;
}
