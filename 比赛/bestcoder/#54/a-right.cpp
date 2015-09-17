
#include <cstdio>
#include <algorithm>
#include <vector>
typedef long long LL;
using namespace std;
#define rep(i,n) for(int i = 0;i < n;i ++)

vector<int> fac;
int main() {
    int T, n, x;

    scanf("%d", &T);
    rep(cas, T) {
        scanf("%d", &n);
        fac.clear();
        rep(i, n) {
            scanf("%d", &x);
            for(LL y = 2; y * y <= x; y ++) {
                while(x % y == 0) {
                    fac.push_back(y);
                    x /= y;
                }
            }
            if(x > 1)
                fac.push_back(x);
        }
        LL answer = 1;
        sort(fac.begin(), fac.end());
        if(fac.size() >= 2) {
            answer = answer * fac[0] * fac[1];
        }
        if(answer == 1) {
            puts("-1");
        } else
            printf("%I64d\n", answer);
    }
    return 0;
}
