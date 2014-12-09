/***********************************************\
 |Author: YMC
 |Created Time: 2014/10/25 19:11:54
 |File Name: b.cpp
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
int ty;
string a,b,c,d;
int s[20];
map<string,string> m1;
map<string,string> m2;
int x2[10] = {1,2,4,8,16,32};
string ge(int a) {
    string an = "";
    while(a) {
        if(a % 2 == 0) an += '0';
        else an += '1';
        a /= 2;
    }
    reverse(an.begin(),an.end());
    //cout<<an<<endl;
    while(an.length() != 5) an = '0' + an;
    return an;
}
int gl(string s) {
    int ans = 0;
    for(int i=0;i<5;++i) {
        ans += (s[i] - '0') * x2[4-i];
    }
    return ans;
}
int main() {
	//freopen("input.txt","r",stdin);
    //cout<<gl("01010")<<endl;
    //cout<<gl("10100")<<endl; 
    //cout<<ge(4)<<endl;
    //cout<<ge(10)<<endl;
    ios::sync_with_stdio(false);
    m1["ADD"] = "000001";
    m1["SUB"] = "000010";
    m1["DIV"] = "000011";
    m1["MUL"] = "000100";
    m1["MOVE"] = "000101";
    m1["SET"] = "000110";
    m2["000001"] = "ADD";
    m2["000010"] = "SUB";
    m2["000011"] = "DIV";
    m2["000100"] = "MUL";
    m2["000101"] = "MOVE";
    m2["000110"] = "SET";

    while(cin>>ty) {
        if(ty == 1) {
            cin>>a>>b;
            int p = 0;
            bool fg = false;
            memset(s,0,sizeof(s));
            for(int i=0;i<b.length();++i) {
                if(b[i] >= '0' && b[i] <= '9') {
                    if(!fg){
                        p ++;
                        fg = true;
                    }
                    s[p] = s[p]*10 + b[i] - '0';
                } else {
                    if(p == 0) continue;
                    else p ++;
                }
            }
            //cout<<s[1]<<" "<<s[3]<<endl;
            if(a != "SET") {
            	string t1 = ge(s[1]);
            	string t2 = ge(s[3]);
            	cout<<m1[a]<<t1<<t2<<endl;
            } else {
            	string t1 = ge(s[1]);
       			cout<<m1[a]<<t1<<"00000"<<endl; 
            }
        } else {
            cin>>a;
            if(a.length() != 16){
                cout<<"Error!\n";
                continue;
            }
            string a1 = a.substr(0,6);
            string a2 = a.substr(6,5);
            string a3 = a.substr(11);
            //cout<<a1<<" "<<a2<<" "<<a3<<endl;
            if(m2.count(a1) == 0) {
                cout<<"Error!\n";
                continue;
            } else {
                string a4 = m2[a1];
                if(a4 == "SET" && a3 != "00000") {
                    cout<<"Error!\n";
                    continue;
                }
                if(a4 == "SET") {
                    int tp = gl(a2);
                    if(tp == 0) {
                        cout<<"Error!\n";
                        continue;
                    }
                    cout<<"SET R"<<tp<<endl;
                } else {
                    int tp1 = gl(a2);
                    int tp2 = gl(a3);
                    if(tp1 == 0 || tp2 == 0) {
                        cout<<"Error!\n";
                        continue;
                    }
                    cout<<a4<<" R"<<tp1<<",R"<<tp2<<endl;
                }
            }
        }
    }    
	return 0;
}

