
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define BASE 10000//进制
#define SIZE 201 //默认长度  最大表示长度为SIZE*4
struct BigInteger{
    int len,data[SIZE],neg; //长度,数据,是否为负

    BigInteger() { len=neg=0; }
    BigInteger(int v) {len=neg=0; if(v<0){neg=1;v=-v;} for(;v;v/=BASE)data[len++]=v%BASE; }
    BigInteger(char *s);
    BigInteger(const BigInteger&v) { len=v.len; neg=v.neg; memcpy(data,v.data,len*sizeof(*data)); }
    //以上构造函数
    BigInteger& operator=(const BigInteger&v);
    BigInteger& operator<<(const int cnt);
    int&operator[](int index){return data[index];}
    int operator[](int index)const{return data[index];}
    friend bool operator==(const BigInteger&a,const BigInteger&b);
    friend bool operator <(const BigInteger&a,const BigInteger&b);
    
    friend BigInteger operator+(const BigInteger&a,const BigInteger&b);
    friend BigInteger operator-(const BigInteger&a,const BigInteger&b);
    friend BigInteger operator*(const BigInteger&a,const BigInteger&b);
    friend BigInteger operator/(const BigInteger&a,const BigInteger&b);
    friend BigInteger operator%(const BigInteger&a,const BigInteger&b);
    
    void print(char* result); //将这个BigInteger放到result里面
    void print();             //直接输出到屏幕上,并换行
};
BigInteger::BigInteger(char *p){
    len=neg=0;
    if( p[0]=='-' ) { neg=1; p++; };
    for(int j=strlen(p)-4;j>-4;j-=4){
        int tmp=0;
        for(int k=j;k<j+4;k++){
            if( k>=0 ) tmp=10*tmp+p[k]-'0';
        }
        data[len++]=tmp;
    }
    while( len && data[len-1]==0 )len--; //前导0
}
BigInteger& BigInteger::operator=(const BigInteger&v){
    len=v.len;
    neg=v.neg;
    memcpy(data,v.data,len*sizeof(*data));
    return *this;
}
BigInteger& BigInteger::operator<<(const int cnt){
    if(len==0||cnt<=0)return *this;
    memcpy(data+cnt,data,len*sizeof(*data));
    memset(data,0,cnt*sizeof(*data));
    len+=cnt;
    return *this;
}
int _cmp(const BigInteger&a,const BigInteger&b){
    int i;
    if(a.neg==1&&b.neg==0)return -1;
    if(a.neg==0&&b.neg==1)return 1;
    if(a.neg==0){
        if(a.len!=b.len)return a.len>b.len?1:-1;
        for(i=a.len-1;i>=0&&a[i]==b[i];i--);
        if(i<0)return 0;
        return a[i]>b[i]?1:-1;
    }else{
        if(a.len!=b.len)return a.len>b.len?-1:1;
        for(i=a.len-1;i>=0&&a[i]==b[i];i--);
        if(i<0)return 0;
        return a[i]>b[i]?-1:1;
    }
}
bool operator==(const BigInteger&a,const BigInteger&b){return _cmp(a,b)==0;}
bool operator< (const BigInteger&a,const BigInteger&b){return _cmp(a,b)<0;}

BigInteger operator+(const BigInteger&a,const BigInteger&b){
    BigInteger ret;
    int i,c=0;
    if(a.neg==b.neg){
        for(i=0;i<a.len||i<b.len||c;i++){
            if(i<a.len)c+=a[i];
            if(i<b.len)c+=b[i];
            ret[i]=c%BASE;
            c/=BASE;
        }ret.len=i;
        ret.neg=a.neg;
    }else{
        BigInteger va=a,vb=b;
        va.neg=0;
        vb.neg=0;
        ret=va-vb;
        if(a.neg)ret.neg=!ret.neg;
    }
    return ret;
}
BigInteger operator-(const BigInteger&a,const BigInteger&b){
    BigInteger ret;
    int i,c=0;
    if(a.neg==b.neg){
        if( a.neg==1 ){
            BigInteger ta=a, tb=b;
            ta.neg=tb.neg=0;
            return tb-ta;
        }
        if(a<b){
            ret=b-a;
            ret.neg=1;
        }else{
            for(i=0;i<a.len;i++){
                ret[i]=a[i]-c;
                if(i<b.len)ret[i]-=b[i];
                if(ret[i]<0){c=1;ret[i]+=BASE;}
                else c=0;
            }while(i>0&&ret[i-1]==0)i--;
            ret.len=i;
            ret.neg=0;
        }
    }else{
        BigInteger vb=b;
        vb.neg=!b.neg;
        ret=a+vb;
    }
    return ret;
}
BigInteger operator*(const BigInteger&a,const BigInteger&b){
    int i,j;
    if(!b.len)return 0;
    BigInteger ret;
    for(i=0;i<a.len;i++){
        int c=0;
        for(j=0;j<b.len||c;j++){
            if(j<b.len)c+=(int)a[i]*(int)b[j];
            if(i+j<ret.len){
                c+=ret[i+j];
                ret[i+j]=c%BASE;
            }else ret[ret.len++]=c%BASE;
            c/=BASE;
        }
    }ret.neg=a.neg^b.neg;
    return ret;
}
BigInteger operator/(const BigInteger&a,const BigInteger&b){
    BigInteger ret,c;
    if( b.neg==1 ){
        ret=a; c=b;
        ret.neg=!ret.neg; c.neg=!c.neg;
        return ret/c;
    }
    int i,lo,hi,mid;
    for(i=a.len-1;i>=0;i--){
        c=(c<<1)+a[i];
        lo=0;
        hi=BASE-1;
        while(lo<hi){
            mid=(lo+hi+1)/2;
            if(_cmp(b*mid,c)<=0)lo=mid;
            else hi=mid-1;
        }ret[i]=lo;
        c=c-b*lo;
    }ret.len=a.len;
    while(ret.len&&ret[ret.len-1]==0)ret.len--;
    if(ret.len)ret.neg=a.neg^b.neg;
    else ret.neg=0;
    return ret;
}
BigInteger operator%(const BigInteger&a,const BigInteger&b){
    BigInteger c;
    int i,lo,hi,mid;
    for(i=a.len-1;i>=0;i--){
        c=(c<<1)+a[i];
        lo=0;
        hi=BASE-1;
        while(lo<hi){
            mid=(lo+hi+1)/2;
            if(_cmp(b*mid,c)<=0)lo=mid;
            else hi=mid-1;
        }c=c-b*lo;
    }c.neg=a.neg^b.neg;
    return c;
}
void BigInteger::print(){
    if(len==0){ puts("0"); return; }
    if(neg==1) printf("-");
    printf("%d",data[len-1]);
    for(int i=len-2;i>=0;i--)
        printf("%04d",data[i]);
    puts("");
}
void BigInteger::print(char* s){
    if(len==0){s[0]='0';s[1]=0;return;}
    if(neg==1){*s='-';s++;}
    sprintf(s,"%d",data[len-1]);
    int i;
    for(i=len-2;i>=0;i--)
        sprintf(s+strlen(s),"%04d",data[i]);
}
///////////////////////////////////////////////////////////

char s[30];
int main(){
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        scanf("%s",s);
        BigInteger x(s);
        BigInteger ans=x*x*8-x*7+1;
        printf("Case #%d: ",i);
        ans.print();
    }
}
