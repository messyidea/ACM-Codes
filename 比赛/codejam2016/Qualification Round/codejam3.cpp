#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int n, m;
int wei[100];
long long int son[100];

long long Montgomery(long long n,long long p,long long m)
{ //快速计算(n^p)%m的值
    long long k=1;
    n%=m;
    while(p!=1)
    {
        if(0!=(p&1))k=(k*n)%m;
        n=(n*n)%m;
        p>>=1;
    }
    return(n*k)%m;
}

bool IsPrime3(long long n)
{
    puts("1");
    static unsigned aPrimeList[] = {
            2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
            43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97
    };
    const int nListNum = sizeof(aPrimeList) / sizeof(unsigned);
    for (int i=0;i<nListNum;++i)
    {
        // 按照素数表中的数对当前素数进行判断
        if (1!=Montgomery(aPrimeList[i],n-1,n)) // 蒙格马利算法
        {
//            printf("%d\n", aPrimeList[i]);
            return false;
        }
    }
    return true;
}

bool get_son(long long a,int b) {
    printf("test %lld\n", a);
//    if(IsPrime3(a)) return false;
    long long i = 2;
    for(; i*i <= a; ++i) {
        if(a % i == 0) {
            son[b] = i;
            return true;
        }
    }
    return false;
}

long long int getnum(int len, int i) {
    long long ans = 0;
    for(int t = len-1; t >=0; --t) {
        ans *= (long long int)i;
        ans += wei[t];
    }
    return ans;
}

bool check(long long t, int n) {
    int len = 0;
    wei[len++] = 1;
    while(t) {
        if(t & 1) wei[len++] = 1;
        else wei[len++] = 0;
        t >>= 1;
    }
    while(len < n-1) wei[len ++] = 0;
    wei[len ++] = 1;
    wei[len] = 0;
    long long a, b, c;
    //0 - len-1
    for(int i = 2; i <= 10; ++i) {
        a = getnum(len, i);
        if(!get_son(a, i)) {
            return false;
        }
    }
    return true;
}

void do_print(long long t, int n) {
    int len = n;
    for(int i=len-1; i >= 0; --i) {
        printf("%d", wei[i]);
    }
    for(int j = 2; j <= 10; ++j) {
        printf(" %lld", son[j]);
    }
    puts("");
}

void solve(int n, int m) {
    int count = 0;
    long long int t = 0;
//    printf("%lu\n", t);
    while(1) {
        printf("judge %lld\n", t);
        if(check(t, n)) {
            count ++;
            do_print(t, n);
            if(count == m) return ;
        }
        t ++;
    }
}

int main() {
    freopen("input.in", "r",stdin);
//    freopen("out", "w",stdout);

//    printf("IsPrime3  = %d\n", IsPrime3(13*97));
    int T;
    scanf("%d",&T);
    int pos = 1;
    while(T--) {
        scanf("%d %d", &n, &m);
        printf("Case #%d:\n", pos++);
        solve(n, m);
    }

    return 0;
}