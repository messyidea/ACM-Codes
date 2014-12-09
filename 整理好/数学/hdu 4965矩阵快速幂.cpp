#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
//#pragma comment(linker, "/STACK:102400000,102400000")
typedef  long long ll;
#define INF 1e9
#define maxn 1050
const ll mod = 6;
#define eps 1e-7
#define pi 3.1415926535897932384626433
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define scan(n) scanf("%d",&n)
#define scan2(n,m) scanf("%d%d",&n,&m)
#define scans(s) scanf("%s",s);
#define ini(a) memset(a,0,sizeof(a))
#define out(n) printf("%d\n",n)
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int P = 6;
const int MOD = 6;
const int MAXN = 1050;
int n, k, m, m2;
void  mat_mul( int  (*a)[MAXN], int (*b)[MAXN], int  (*c)[MAXN], int n, int m,int m2 ) {
    int  i, j, k, L, *p2;
    int  tmp[MAXN], con;
    //memset( c, 0, sizeof( A[0] ) );
    for( i = 0; i < n; ++i ) {
        memset( tmp, 0, sizeof( tmp ) );
        for( k = 0, L = (m & ~15); k < L; ++k ) {
            con = a[i][k];
            for( j = 0, p2 = b[k]; j < m2; ++j, ++p2 )
                tmp[j] += con * (*p2);
            if( ( k & 15 ) == 15 ) {
                for( j = 0; j < m2; ++j ) if(tmp[j] >= P) tmp[j] %= P;
            }
        }

        for( ; k < m; ++k ) {
            con = a[i][k];
            for( j = 0, p2 = b[k]; j < n; ++j, ++p2 )
                tmp[j] += con * (*p2);
        }
        for( j = 0; j < m2; ++j )
            c[i][j] = tmp[j] % P;
    }
}
int d[maxn][maxn];
int tmp[maxn][maxn];
void pow_mod(int (*a)[MAXN],int x, int(*c)[MAXN]) { //优先级低加括号
    ini(d);
    rep(i,m) d[i][i] = 1;
    for (;x;x >>= 1) {
        if (x & 1)
        {
            mat_mul(d, a, tmp, m, m, m2);
            rep(i,m) rep(j,m) d[i][j] = tmp[i][j];
        }
        mat_mul(a, a, tmp, m, m, m2);
        rep(i,m) rep(j,m) a[i][j] = tmp[i][j];
    }
    rep(i,m) rep(j,m) c[i][j] = d[i][j];
}  
int a[MAXN][MAXN],b[MAXN][MAXN],c[MAXN][MAXN];
int ans[MAXN][MAXN];
int in()  //快速输入
{
    char ch;
    int a = 0;
    while((ch = getchar()) == ' ' || ch == '\n');
    a += ch - '0';
    while((ch = getchar()) != ' ' && ch != '\n')
    {
        a *= 10;
        a += ch - '0';
    }
    return a;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    //    freopen("out.txt","w",stdout);
#endif
    while(cin>>n>>k && (n | k))
    {

        rep(i,n) rep(j,k) scan(a[i][j]);
        rep(i,k) rep(j,n) scan(b[i][j]);
        m2 = m = k;
        mat_mul(b, a, c , m ,n, m);    
        pow_mod(c, n * n - 1, ans);
        mat_mul(a, ans, c,n, m, m2);
        mat_mul(c,b,ans,n,m,n);
        ll sum = 0;
        rep(i,n) rep(j,n) sum += ans[i][j];
        cout<<sum<<endl; 
    }
    //    }
    return 0;
}

