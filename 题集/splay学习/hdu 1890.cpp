
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std ;

const int maxn = 100011 ;
int col[maxn] , id[maxn] , num[maxn] ;
int size[maxn] , son[2][maxn] , fa[maxn] , tot , t[maxn] ;

void push_down ( int rt ) {
    if ( col[rt] ) {
        int ls = son[0][rt] , rs = son[1][rt] ;
        if ( ls ) col[ls] += col[rt] ;
        if ( rs ) col[rs] += col[rt] ;
        if ( col[rt] % 2 ) son[0][rt] = rs , son[1][rt] = ls ;
        col[rt] = 0 ;
    }
}

void push_up ( int rt ) {
    size[rt] = 1 ;
    if ( son[0][rt] ) size[rt] += size[son[0][rt]] ;
    if ( son[1][rt] ) size[rt] += size[son[1][rt]] ;
}

int new_node ( int v ) {
    size[++tot] = 1 ;
    son[0][tot] = son[1][tot] = fa[tot] = 0 ;
    col[tot] = 0 ;
    id[v] = tot ;
    return tot ;
}

int build ( int l , int r ) {
    if ( l > r ) return 0 ;
    int mid = l + r >> 1 ;
    int temp = new_node ( num[mid] ) ;
    son[0][temp] = build ( l , mid - 1 ) ;
    if ( son[0][temp] ) fa[son[0][temp]] = temp , size[temp] += size[son[0][temp]] ;
    son[1][temp] = build ( mid + 1 , r ) ;
    if ( son[1][temp] ) fa[son[1][temp]] = temp , size[temp] += size[son[1][temp]] ;
    return temp ;
}

void rot ( int rt , int c ) {
    int y = fa[rt] , z = fa[y] ;
    push_down ( y ) , push_down ( rt ) ;
    son[!c][y] = son[c][rt] ;
    if ( son[c][rt] ) fa[son[c][rt]] = y ;
    fa[rt] = z ;
    if ( z ) {
        if ( y == son[0][z] ) son[0][z] = rt ;
        else son[1][z] = rt ;
    }
    son[c][rt] = y , fa[y] = rt ;
    push_up ( y ) ;
}

void splay ( int x , int to ) {
    push_down ( x ) ;
    while ( fa[x] != to ) {
        if ( fa[fa[x]] == to ) rot ( x , x == son[0][fa[x]] ) ;
        else {
            int y = fa[x] , z = fa[y] ;
            if ( x == son[0][y] ) {
                if ( y == son[0][z] ) rot ( y , 1 ) , rot ( x , 1 ) ;
                else rot ( x , 1 ) , rot ( x , 0 ) ;
            }
            else {
                if ( y == son[1][z] ) rot ( y , 0 ) , rot ( x , 0 ) ;
                else rot ( x , 0 ) , rot ( x , 1 ) ;
            }
        }
    }
    push_up ( x ) ;
}

int jion ( int r1 , int r2 , int root ) {
    int x = r1 ;
    push_down ( x ) ;
    while ( son[1][x] ) {
        x = son[1][x] ;
        push_down ( x ) ;
    }
    splay ( x , root ) ;
    son[1][x] = son[1][root] ;
    if ( son[1][root] ) fa[son[1][root]] = x ;
    return x ;
}

int cmp ( int i , int j ) { 
    if ( num[i] == num[j] ) return i < j ;
    return num[i] < num[j] ;
}

void search ( int x , int to ) {
    if ( x == to ) {
        push_down ( x ) ;
        return ;
    }
    search ( fa[x] , to ) ;
    push_down ( x ) ;
}

int main () {
    int n , i , j , k ;
    while ( scanf ( "%d" , &n ) != EOF ) {
        if ( n == 0 ) break ;
        for ( i = 1 ; i <= n ; i ++ ) scanf ( "%d" , &num[i] ) , t[i] = i ;
        sort ( t + 1 , t + n + 1 , cmp ) ;
        for ( i = 1 ; i <= n ; i ++ ) num[t[i]] = i ;
        tot = 0 ;
        int rt = build ( 1 , n ) ;
        for ( i = 1 ; i <= n ; i ++ ) {
            search ( id[i] , rt ) ;
            splay ( id[i] , 0 ) ;
            rt = id[i] ;
            int ans = i ;
            if ( son[0][rt] ) ans += size[son[0][rt]] , col[son[0][rt]] ++ ;
            printf ( "%d" , ans ) ;
            if ( i != n ) {
                printf ( " " ) ;
                if ( !son[0][rt] ) rt = son[1][rt] ;
                else rt = jion ( son[0][rt] , son[1][rt] , rt ) ;
                fa[rt] = 0 ;
            }
        }
        puts ( "" ) ;
    }
}
/*
10
7 8 4 6 3 5 1 9 10 2
*/
