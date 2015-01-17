
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
double xx1,yy1,xx2,yy2;
double ta,tb;
pair<double ,double > line[5005];
pair<double ,double > pp[5005];
int tot1,tot2;
int ans[5005];
void pr(Vector a) {
    cout<<"VECTOR "<<a.x<<" "<<a.y<<endl;
}
bool lef(int mid,int id) {
    double ta = line[id].first,tb = line[id].second;
    Point pa = Point(ta,yy1);
    Point pb = Point(tb,yy2);
    Point pc = Point(pp[mid].first,pp[mid].second);
    Vector aa = pb - pa;
    Vector bb = pc - pa;
    //pr(pa);pr(pb);pr(pc);pr(aa);pr(bb);
    if(Cross(aa,bb) > 0) return true;
    else return false;
}
void addto(int id) {
    int l = 0,r = n-1;
    int mid = (l + r) >> 1;
    while(l < r - 1) {
        if(lef(id,mid)) l = mid;
        else r = mid;
        mid = (l + r) >> 1;
    }
    if(!lef(id,mid)) {
        ans[mid] ++;
        return ;
    }
    mid++;
    if(!lef(id,mid)) {
        ans[mid] ++;
        return ;
    }
    mid++;
    ans[mid] ++;
    return ;
    /*for(int i=0;i<n;++i){
        if(!lef(id,i)) {
            ans[i] ++;
            return ;
        }
    }
    ans[n] ++;*/
}
void solve() {
    memset(ans,0,sizeof(ans));
    rep(i,m) {
        addto(i);
    }
    rep(i,n+1) {
        printf("%d: %d\n",i,ans[i]);
    }
}
int main() {
	//freopen("input.txt","r",stdin); 
    int cc = 0;
    while(scanf("%d",&n) && n) {
        if(cc++) puts("");
        scanf("%d",&m);
        scanf("%lf %lf %lf %lf",&xx1,&yy1,&xx2,&yy2);
        rep(i,n) {
            scanf("%lf %lf",&line[i].first,&line[i].second);
        }
        rep(i,m) {
            scanf("%lf %lf",&pp[i].first,&pp[i].second);
        }
        //sort(pp,pp+m);
        solve();
    }
	return 0;
}
