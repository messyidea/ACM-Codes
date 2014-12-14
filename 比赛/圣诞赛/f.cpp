#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
const int maxn = 1005;
const double eps = 1e-8,pi = acos(-1.0);
struct point {
    double x,y;
    point(double _x = 0,double _y = 0):x(_x),y(_y) {}
} p1,p2,p,q;
struct circle {
    point p; double r;
} cir[maxn],cirt[maxn];
point operator-(const point& lhs,const point& rhs) {
    return point(lhs.x - rhs.x,lhs.y - rhs.y);
}
point operator+(const point& lhs,const point& rhs) {
    return point(lhs.x + rhs.x,lhs.y + rhs.y);
}
point operator*(const point& p,const double& x) {
    return point(p.x * x,p.y * x);
}
struct seg {
    double l,r;
    point st,ed;
} b[maxn];
inline bool operator<(const circle& lhs,const circle& rhs) {
    return lhs.r > rhs.r;
}
inline bool operator<(const seg& lhs,const seg& rhs) {
    return lhs.l - rhs.l < -eps || (lhs.l - rhs.l < eps && lhs.r - rhs.r < -eps);
}
inline double SQR(const double& x) {
    return x * x;
}
inline double dis(const point& lhs,const point& rhs) {
    return SQR(lhs.x - rhs.x) + SQR(lhs.y - rhs.y);
}
double angle,last,ans;
int n,m;
inline void prepare() {
    std::sort(cir,cir + n);
    int m = 0; bool bo;
    for (int i = 0; i < n; ++i) {
        if (cir[i].r == 0) break;
        bo = false;
        for (int j = 0; j < m; ++j)
            if (dis(cir[i].p,cirt[j].p) <= SQR(cir[i].r - cirt[j].r)) {
                bo = true; break;
            }
        if (bo) continue;
        cirt[m++] = cir[i];
    }
    n = m;
    memcpy(cir,cirt,sizeof(cirt));
}
point rotate(const point& p,const double& cosh,const double& sinh) {
    return point(p.x * cosh - p.y * sinh,p.x * sinh + p.y * cosh); 
}
void GET(const circle& p1,const circle& p2,point& q1,point& q2) {
    point p = p2.p - p1.p;
    double D = dis(p1.p,p2.p);
    double cosh = (SQR(p1.r) + D - SQR(p2.r)) / (2.0 * p1.r * sqrt(D)),
    sinh = sqrt(1 - SQR(cosh));
    q1 = rotate(p,cosh,-sinh) * (p1.r / sqrt(D));
    q2 = rotate(p,cosh,sinh)  * (p1.r / sqrt(D));
}
void work() {
    ans = 0;
    for (int i = 0; i < n; ++i) {
        m = 0;
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (dis(cir[i].p,cir[j].p) >= SQR(cir[i].r + cir[j].r)) continue;   
            GET(cir[i],cir[j],p1,p2);
            double l = atan2(p1.y,p1.x),
                   r = atan2(p2.y,p2.x);
            if (l < r) {
                b[m].st = p1 + cir[i].p;
                b[m].ed = p2 + cir[i].p;
                b[m].l = l; b[m++].r = r;
            }
            else {
                b[m].st = p1 + cir[i].p;
                b[m].ed = cir[i].p; b[m].ed.x -= cir[i].r;
                b[m].l = l;   b[m++].r = pi;
                b[m].st = cir[i].p; b[m].st.x -= cir[i].r;
                b[m].ed = p2 + cir[i].p;
                b[m].l = -pi; b[m++].r = r;
            }
        }
        if (m != 0) {
            std::sort(b,b + m);
            last = b[0].r; p = b[0].ed;
            for (int j = 0; j < m; ++j) 
                if (b[j].l < last) {
                    if (b[j].r > last) last = b[j].r,p = b[j].ed;
                }
                else {
                    angle = b[j].l - last;
                    ans += 0.5 * SQR(cir[i].r) * (angle - sin(angle));
                    q = b[j].st;
                    ans += (p.x * q.y - p.y * q.x) / 2;
                    p = b[j].ed; last = b[j].r;
                }
            angle = 2 * pi - last + b[0].l;
            ans += 0.5 * SQR(cir[i].r) * (angle - sin(angle));
            q = b[0].st;
            ans += (p.x * q.y - p.y * q.x) / 2;
        }
        else ans += SQR(cir[i].r) * pi;
    }
    printf("%.3lf\n",ans);
}
int main() {
    //freopen("ciru.in","r",stdin); freopen("ciru.out","w",stdout);
    while (scanf("%d",&n) != EOF) {
        for (int i = 0; i < n; ++i) 
            scanf("%lf%lf%lf",&cir[i].p.x,&cir[i].p.y,&cir[i].r); 
        prepare();
        work();
    }
    //fclose(stdin); fclose(stdout);
}

