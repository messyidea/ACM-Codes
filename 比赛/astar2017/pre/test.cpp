#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int le;
bool test1(int a) {
	int c = 0;
	for(int i = 0; i < le; ++i) {
		int t = (a >> i) & 1;
		if (t == 1) c ++;
		//printf("%d\n", t);
	}
	if (c == le / 2) return true;
	else return false;
}

bool test2(int a) {
	int c = 0;
	for(int i = 0; i < le; ++i) {
		int t = (a >> i) & 1;
		if (t == 1) {
			c ++;
		} else {
			c --;
		}
		if (c < 0) return  false;
		//printf("%d\n", t);
	}
	return true;
}
void pp(int a) {
	for(int i = 0; i < le; ++i) {
		int t = (a >> i) & 1;
		printf("%d",t); 
	}
	puts("");
}
int main() {
	//test1(10); 
	//printf("%d\n", 1<<8);
	le = 8;
	int count = 0;
	for(int i = 0; i < (1 << le); ++i) {
		if(!test1(i)) continue;
		if(!test2(i)) continue;
		count ++;
		//printf("%d\n", i);
		pp(i);
	}
	printf("%d\n", count);
	return 0;
}