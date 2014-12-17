
#include <cstdio>  
#include <cmath>  
  
#define MAXN 100000  
  
double a[MAXN];  
  
int main() {  
    int n;  
    int i;  
    double ans;  
  
    a[0] = 0;  
    for (i=1; i<MAXN; ++i)  
        a[i] = a[i-1]+1.0/i;  
  
    while (scanf("%d", &n) != EOF) {  
        if (n < MAXN) {  
            ans = a[n];  
        } else {  
            ans = log(n*1.0)+0.57721566490153286060651209;  
        }  
        printf("%.4lf\n", ans);  
    }  
  
    return 0;  
}  
