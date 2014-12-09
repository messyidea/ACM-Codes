
#include <iostream>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define MX 1100000
using namespace std;

int a[MX], an;
int vis[MX], prv[MX];

int main() {
    
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
    
    int i, k;
    scanf("%d", &an);
        
    for (i = 0; i < an; i++) scanf("%d", a + i);
    sort(a, a + an); an = unique(a, a + an) - a;
    
    if (an == 1) {
        printf("0\n");
        return 0;   
    }
    for (i = 0; i < an; i++) vis[a[i]] = 1;
    
    k = -1;
    for (i = 1; i <= 1000000; i++) {
        prv[i] = k;
        if (vis[i]) k = i;
    }

    int ans = 0;
    for (i = an - 2; i >= 0; i--) {
        if (ans > a[i]) break;
        int u = a[i], v;
        for (k = 2; ; k++) {
            u += a[i];
            if (u > 1000000) v = a[an - 1];
            else v = prv[u];
            ans = max(ans, v % a[i]);
            
            if (u > a[an - 1]) break;
        }
    }
    printf("%d\n", ans);
    return 0;   
}
