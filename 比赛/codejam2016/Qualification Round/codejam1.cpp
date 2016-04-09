#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int vis[10];
int t;

bool check() {
    for(int i=0; i<10; ++i) {
        if(vis[i] == 0) return false;
    }
    return true;
}

void doit(int t) {
    int k;
    while(t) {
        vis[t % 10] = 1;
        t /= 10;
    }
}
int solve(int t) {
    memset(vis, 0, sizeof(vis));
    int o = t;
    while(1) {
        doit(t);
        if(check()) return t;
        t += o;
    }
}

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("out", "w",stdout);
    int N;
    int pos = 0;
    int ans;
    while(~scanf("%d", &N)) {
        pos = 1;
        while(N--) {
            scanf("%d", &t);
            if(t == 0) {
                printf("Case #%d: INSOMNIA\n", pos++);
                continue;
            }
            ans = solve(t);
            printf("Case #%d: %d\n", pos++, ans);
        }
    }
    return 0;
}