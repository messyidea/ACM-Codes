#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

char s[1000];

int main() {
    freopen("B-large.in", "r",stdin);
    freopen("out", "w",stdout);
    int T;
    scanf("%d",&T);
    int pos = 1;
    while(T--) {
        scanf("%s", s);
        int len = strlen(s);
        int count = 0;
        for(int i=1;i < len; ++i) {
            if(s[i] == s[i-1]) continue;
            else count ++;
        }
        if(s[len-1] == '-') count ++;
        printf("Case #%d: %d\n", pos++, count);
    }

    return 0;
}