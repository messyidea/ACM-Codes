/***********************************************\
 |Author: YMC
 |Created Time: 2015/3/22 15:10:52
 |File Name: g.cpp
 |Description: 
\***********************************************/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#define L(rt) (rt<<1)
#define R(rt) (rt<<1|1)
#define mset(l,n) memset(l,n,sizeof(l))
#define rep(i,n) for(int i=0;i<n;++i)
#define maxx(a) memset(a, 0x3f, sizeof(a))
#define zero(a) memset(a, 0, sizeof(a))
#define srep(i,n) for(int i = 1;i <= n;i ++)
#define MP make_pair
const int inf=0x3f3f3f3f ;
const double eps=1e-8 ;
const double pi=acos (-1.0);
typedef long long ll;

using namespace std;
int da[105][105];
int a,b,c;
int main() {
    //freopen("input.txt","r",stdin); 
    int n;
    while(scanf("%d",&n) != EOF) {
        rep(i,n) {
            rep(j,n) {
                scanf("%d",&da[i][j]);
            }
        }
        bool fg = true;
        for(int i=0;i<n;++i) if(da[i][i] != 0) {
            fg = false;
            break;
        }
        for(int i=0;i<n;++i) {
            for(int j=i+1;j<n;++j) {
                if(da[i][j] != da[j][i]) {
                    fg = false;
                    break;
                }
            }
            if(fg == false) break;
        }
        for(int i=0;i<n;++i) {
            if(fg == false) break;
            for(int j=i+1;j<n;++j) {
                if(fg == false) break;
                for(int k=j+1;k<n;++k) {
                    if(fg == false) break;
                    if(i%2==0 && j%2 == 0 && k%2 == 0) {
                        a = da[i][j];
                        b = da[i][k];
                        c = da[j][k];
                        for(int ii=0;ii<32;++ii) {
                            int count = 0;
                            if((a >> ii) & 1) count ++;
                            if((b >> ii) & 1) count ++;
                            if((c >> ii) & 1) count ++;
                            if(!(count == 3 || count == 1 || count == 0)) {
                                fg = false;
                                break;
                            }
                        }
                    }
                    if(i%2 == 1 && j%2 == 1 && k%2 == 1) {
                        a = da[i][j];
                        b = da[i][k];
                        c = da[j][k];
                        for(int ii=0;ii<32;++ii) {
                            int count = 0;
                            if((a >> ii) & 1) count ++;
                            if((b >> ii) & 1) count ++;
                            if((c >> ii) & 1) count ++;
                            if(!(count == 3 || count == 2 || count == 0)) {
                                fg = false;
                            }
                        }
                    }
                    int cou = 0;
                    if(i % 2) cou++;
                    if(j % 2) cou++;
                    if(k % 2) cou++;
                    if(cou == 1) {
                        if(i % 2) {
                            int a = da[i][j];
                            int b = da[i][k];
                            int c = da[j][k];
                            for(int ii=0;ii < 32;++ii) {
                                if((c >> ii) & 1) {
                                    if(((a >> ii) & 1) != ((b >> ii)&1)) {
                                        fg = false;
                                        break;
                                    }
                                }
                            }
                        }
                        if(j % 2) {
                            int a = da[j][i];
                            int b = da[j][k];
                            int c = da[i][k];
                            for(int ii=0;ii < 32;++ii) {
                                if((c >> ii) & 1) {
                                    if(((a >> ii) & 1) != ((b >> ii)&1)) {
                                        fg = false;
                                        break;
                                    }
                                }
                            }
                        }
                        if(k % 2) {
                            int a = da[i][k];
                            int b = da[j][k];
                            int c = da[i][j];
                            for(int ii=0;ii < 32;++ii) {
                                if((c >> ii) & 1) {
                                    if(((a >> ii) & 1) != ((b >> ii)&1)) {
                                        fg = false;
                                        break;
                                    }
                                }
                            }
                        }
                    } else if(cou == 2) {
                        if(i % 2 == 0) {
                            int a = da[i][j];
                            int b = da[i][k];
                            int c = da[j][k];
                            for(int ii=0;ii < 32;++ii) {
                                if((c >> ii) & 1) {
                                    ;
                                } else {
                                    if(((a >> ii) & 1) != ((b >> ii)&1)) {
                                        fg = false;
                                        break;
                                    }
                                }
                            }
                        }
                        if(j % 2 == 0) {
                            int a = da[i][j];
                            int b = da[k][j];
                            int c = da[i][k];
                            for(int ii=0;ii < 32;++ii) {
                                if((c >> ii) & 1) {
                                    ;
                                } else {
                                    if(((a >> ii) & 1) != ((b >> ii)&1)) {
                                        fg = false;
                                        break;
                                    }
                                }
                            }
                        }
                        if(k % 2 == 0) {
                            int a = da[i][k];
                            int b = da[j][k];
                            int c = da[i][j];
                            for(int ii=0;ii < 32;++ii) {
                                if((c >> ii) & 1) {
                                    ;
                                } else {
                                    if(((a >> ii) & 1) != ((b >> ii)&1)) {
                                        fg = false;
                                        break;
                                    }
                                }
                            }
                        }
                    }

                }
            }
        }
        if(fg == false) {
            puts("NO");
        } else {
            puts("YES");
        }
    }
	return 0;
}

