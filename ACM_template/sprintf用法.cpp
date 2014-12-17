
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <cmath>  
using namespace std ;  
   
typedef long long LL ;  
#define rep( i , a , b ) for ( int i = a ; i < b ; ++ i )  
#define For( i , a , b ) for ( int i = a ; i <= b ; ++ i )  
#define rev( i , a , b ) for ( int i = a ; i >= b ; -- i )  
#define travel( e , H , u ) for ( Edge* e = H[u] ; e ; e = e -> next )  
#define clr( a , x ) memset ( a , x , sizeof a )  
#define cpy( a , x ) memcpy ( a , x , sizeof a )  
   
const int MAXN = 65 ;  
const int MAXE = 10005 ;  
const int MAXH = 10005 ;  
   
LL n , k ;  
LL a[MAXN] ;  
   
struct String {  
    char s[MAXN] ;  
} s[MAXN] ;  
int cnt = 0 ;  
   
LL pow ( int a , int b ) {  
    LL res = 1 , tmp = a ;  
    while ( b ) {  
        if ( b & 1 ) res *= tmp ;  
        tmp *= tmp ;  
        b >>= 1 ;  
    }  
    return res ;  
}  
   
int cmp ( const String& a , const String& b ) {  
    return strcmp ( a.s , b.s ) < 0 ;  
}  
   
void solve () {  
    cnt = 0 ;  
    a[cnt ++] = k ;  
    For ( i , 1 , 18 ) {  
        LL tmp = pow ( 10 , i ) ;  
        if ( tmp > n ) break ;  
        tmp = tmp + ( k - ( tmp - 1 ) % k - 1 ) ;  
        if ( tmp <= k ) continue ;  
        if ( tmp > n ) break ;  
        a[cnt ++] = tmp ;  
    }  
    rep ( i , 0 , cnt ) sprintf ( s[i].s , "%lld" , a[i] ) ;  
    sort ( s , s + cnt , cmp ) ;  
    printf ( "%s\n" , s[0].s ) ;  
}  
   
int main () {  
    while ( ~scanf ( "%lld%lld" , &n , &k ) && ( n || k ) ) solve () ;  
    return 0 ;  
}  
