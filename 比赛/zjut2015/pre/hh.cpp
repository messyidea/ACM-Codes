
#include<iostream>  
#include<cstdio>  
#include<cstring>  
using namespace std;  
using namespace std; 
int le = 60;
int a[61][61];  //系数矩阵  
int ans[61];  
void gauss(){  
    for(int i=0;i<60;i++){  
        int k=i;  
        for(;k<60;k++)  
            if(a[k][i]!=0)  
                break;  
        for(int j=0;j<=60;j++)  
            swap(a[i][j],a[k][j]);  
        for(int j=0;j<60;j++)  
            if(i!=j&&a[j][i])  
                for(int k=0;k<=60;k++)  
                    a[j][k]=a[i][k]^a[j][k];  
    }  
}  
char sss[100];
int aa[100];
int main(){  
    freopen("input.txt","r",stdin);
    int t,tt=0;  
    scanf("%d",&t);  
    while(t--){  
        memset(a,0,sizeof(a));  
        int ttt = 0;
        for(int i=0;i<5;i++){  
            //scanf("%s",&a[i][30]); 
            scanf("%s",sss);
            int len = strlen(sss);
            for(int j=0;j<len;++j) {
                a[ttt++][60] = sss[j] - '0';
                ans[ttt-1] = 0;
            } 
            //ans[i]=0;  
        }  
        for(int i=0;i<60;++i) {
            a[i][i] = 1;
            aa[0] = i + 12;
            aa[1] = i + 1;
            aa[2] = i - 1;
            aa[3] = i + 4;
            aa[4] = i - 4;
            aa[5] = i - 12;
            for(int kk=0;kk<=6;++kk) {
                if(aa[i] >= 0 && aa[i] < 60) {
                    a[i][aa[i]] = 1;
                }
            }
        }
        /*for(int i=0;i<60;i++){  
            a[i][i]=1;  
            if(i%6!=0)  
                a[i-1][i]=1;  
            if(i%6!=5)  
                a[i+1][i]=1;  
            if(i>5)  
                a[i-6][i]=1;  
            if(i<24)  
                a[i+6][i]=1;  
        } */ 
        gauss();  
        /*for(int i=0;i<30;i++){ 
        for(int j=0;j<=30;j++) 
        printf("%d ",a[i][j]); 
        printf("\n"); 
        }*/  
        for(int j=0;j<60;j++)    
             ans[j]=a[j][60];     
            //printf("PUZZLE #%d\n",++tt);  
            for(int i=0;i<60;i++){  
            printf("%d",ans[i]);  
            if((i+1)%4==0)  
            printf("\n");  
            else  
            printf(" ");  
                }  
    }  
    return 0;  
}  
