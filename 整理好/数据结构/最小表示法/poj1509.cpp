/***********************************************\
 |Author: YMC
 |Created Time: 2014/7/7 21:24:13
 |File Name: poj1509.cpp
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

using namespace std;
char s[10005];
int solve(char* s){
    int i=0,j=1,k=0,x,y;
    int len = strlen(s);
    while(i<len && j<len && k<len){
        x = (i+k)%len;
        y = (j+k)%len;
        if(s[x] > s[y]){
            i = i+k+1;
            k=0;
        }
        else if(s[x] < s[y]){
            j = j+k+1;
            k=0;
        }
        else k++;
        if(i == j) j++;
    }
    return min(i,j);
}
int main() {
	//freopen("input.txt","r",stdin); 
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",s);
        printf("%d\n",solve(s)+1);
    }
	return 0;
}

