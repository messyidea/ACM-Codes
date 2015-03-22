#include <cstdio>
#include <iostream>
#include <algorithm>
#include<cstring>  
using namespace std;  
int s[100],e[100],a[100][100],n; 
int gauss(){  
    int i;
    for(i=0;i<60;){  
        int k=i;  
        for(;k<60;k++)  
            if(a[k][i]!=0)  
                break; 
        if(k == 60) return -1;
        if(a[k][i]) { 
        for(int j=0;j<=60;j++)  
            swap(a[i][j],a[k][j]);  
        for(int j=0;j<60;j++)  
            if(i!=j&&a[j][i])  
                for(int k=0;k<=60;k++)  
                    a[j][k]=a[i][k]^a[j][k]; 
        i++; 
        }
    } 
    for(int j=i;j<60;j++)  
        if(a[j][60])  
            return -1;  
    
    return 1; 
}  


char sss[100];
int aa[100];
int main(){  
    //freopen("input.txt","r",stdin);
    int t,i,j;  
    scanf("%d",&t); 
    int hehe = 0; 
    while(t--){  
        if(hehe ++ != 0) puts("");
        n = 3*4*5;
        memset(a,0,sizeof(a));  
        int ttt = 0;
        for(i=0;i<15;i++)  {
            scanf("%s",sss);
            int len = strlen(sss); 
            for(int ii=0;ii<len;++ii) {
                s[ttt ++] = sss[ii] - '0';
                //cout<<s[ttt-1];
            }
        }
        for(int j=0;j<n;++j) {
            if(s[j] != 1) a[j][n] = 1;
        }
        for(int i=0;i<n;++i) {
            a[i][i] = 1;
            if(i - 12 >= 0)  a[i][i-12] = 1;
            if(i + 12 < 60) a[i][i+12] = 1;
            int t = i % 12;
            if(t >= 0 && t < 8) {
                a[i][i+4] = 1;
            }
            if(t >= 4 && t < 12) {
                a[i][i-4] = 1;
            }
            if(!((t+1) % 4 == 0)) {
                a[i][i+1] = 1;
            }
            if(!(t%4 == 0)) {
                a[i][i-1] = 1;
            }

        }
        int ans=gauss(); 
        
        if(ans==-1)  
            puts("Oh,my Boring!");  
        else{
            for(int i=0;i<n;++i) {
                printf("%d",a[i][60]);
                if((i+1) % 4 == 0) {
                    puts("");
                }
            }
        } 
        //puts(""); 
            
    }  
    return 0;  
}  
