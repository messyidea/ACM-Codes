
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
typedef long long LL;
//#define double long double
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
const double inf = 1e20;
const double eps = 1e-6;
#define MAX_N 1024
struct Line {
	double x, y1, y2;
	Line(double x=0, double y1=0, double y2=0):x(x), y1(y1), y2(y2) {
	}
}lines[MAX_N];
struct Point {
	double x, y;
	Point(double x=0, double y=0):x(x), y(y) {
	}
}points[MAX_N];
double dist[MAX_N][MAX_N];
double Cross(double x1, double y1, double x2, double y2) {
	return x1 * y2 - y1 * x2;
}
int dcmp(double x) {
	if(fabs(x) < eps)	return 0;
	return x < 0 ? -1: 1;
}
double calc(Point a, Point b, int m) {
	rep(i, m) {
		if(dcmp(a.x - lines[i].x) < 0 && dcmp(b.x - lines[i].x) < 0)	continue;
		if(dcmp(a.x - lines[i].x) > 0 && dcmp(b.x - lines[i].x) > 0)	continue;
		if(a.x == b.x)	continue;
		double d1 = Cross(a.x - lines[i].x, a.y - lines[i].y1, b.x - lines[i].x, b.y - lines[i].y1);
		double d2 = Cross(a.x - lines[i].x, a.y - lines[i].y2, b.x - lines[i].x, b.y - lines[i].y2);
		if(dcmp(d1 * d2) < 0)
			return inf;
	}
	double ret = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
	ret = sqrt(ret);
	return ret;
}
inline void checkmin(double &x, double val) { if(x > val) x = val; }
int main() {
	int n, m, N;
	while(~scanf("%d", &N) && ~N) {
		n = 0, m = 0;
		points[n ++] = Point(0, 5);
		points[n ++] = Point(10, 5);
		rep(i, N) {
			double x, yy[5];
			cin >> x;
			rep(_, 4) 
				cin >> yy[_];
			points[n ++] = Point(x, yy[0]);
			points[n ++] = Point(x, yy[1]);
			points[n ++] = Point(x, yy[2]);
			points[n ++] = Point(x, yy[3]);
			lines[m ++] = Line(x, 0, yy[0]);
			lines[m ++] = Line(x, yy[1], yy[2]);
			lines[m ++] = Line(x, yy[3], 10);
		}
		rep(i, n)
			rep(j, n)
				dist[i][j] = inf;
		rep(i, n)
			for(int j = i + 1; j < n; j ++) {
				dist[j][i] = dist[i][j] = calc(points[i], points[j], m);
			}
		rep(k, n)
			rep(i, n)
				rep(j, n) {
					if(i == j)	continue;
					if(dist[i][k] != inf && dist[k][j] != inf) {
						checkmin(dist[i][j], dist[i][k] + dist[k][j]);
					}
				}
		printf("%.2f\n", dist[0][1]);
	}
	return 0;
}
