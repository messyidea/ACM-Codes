// LA2659 Sudoku
// Rujia Liu
#include<cstdio>
#include<cstring>
#include<vector>
#include <iostream>

using namespace std;

const int maxr = 5000;
const int maxn = 2000;
const int maxnode = 20000;

// 行编号从1开始，列编号为1~n，结点0是表头结点; 结点1~n是各列顶部的虚拟结点
struct DLX {
  int n, sz; // 列数，结点总数
  int S[maxn]; // 各列结点数

  int row[maxnode], col[maxnode]; // 各结点行列编号
  int L[maxnode], R[maxnode], U[maxnode], D[maxnode]; // 十字链表

  int ansd, ans[maxr]; // 解

  void init(int n) { // n是列数
    this->n = n;

    // 虚拟结点
    for(int i = 0 ; i <= n; i++) {
      U[i] = i; D[i] = i; L[i] = i-1, R[i] = i+1;
    }
    R[n] = 0; L[0] = n;

    sz = n + 1;
    memset(S, 0, sizeof(S));
  }

  void addRow(int r, vector<int> columns) {
    int first = sz;
    for(int i = 0; i < columns.size(); i++) {
      int c = columns[i];
      L[sz] = sz - 1; R[sz] = sz + 1; D[sz] = c; U[sz] = U[c];
      D[U[c]] = sz; U[c] = sz;
      row[sz] = r; col[sz] = c;
      S[c]++; sz++;
    }
    R[sz - 1] = first; L[first] = sz - 1;
  }

  // 顺着链表A，遍历除s外的其他元素
  #define FOR(i,A,s) for(int i = A[s]; i != s; i = A[i]) 

  void remove(int c) {
    L[R[c]] = L[c];
    R[L[c]] = R[c];
    FOR(i,D,c)
      FOR(j,R,i) { U[D[j]] = U[j]; D[U[j]] = D[j]; --S[col[j]]; }
  }

  void restore(int c) {
    FOR(i,U,c)
      FOR(j,L,i) { ++S[col[j]]; U[D[j]] = j; D[U[j]] = j; }
    L[R[c]] = c;
    R[L[c]] = c;
  }

  // d为递归深度
  bool dfs(int d) {
    if (R[0] == 0) { // 找到解
      ansd = d; // 记录解的长度
      return true;
    }

    // 找S最小的列c
    int c = R[0]; // 第一个未删除的列
    FOR(i,R,0) if(S[i] < S[c]) c = i;

    remove(c); // 删除第c列
    FOR(i,D,c) { // 用结点i所在行覆盖第c列
      ans[d] = row[i];
      FOR(j,R,i) remove(col[j]); // 删除结点i所在行能覆盖的所有其他列
      if(dfs(d+1)) return true;
      FOR(j,L,i) restore(col[j]); // 恢复结点i所在行能覆盖的所有其他列
    }
    restore(c); // 恢复第c列

    return false;
  }

  bool solve(vector<int>& v) {
    v.clear();
    if(!dfs(0)) return false;
    for(int i = 0; i < ansd; i++) v.push_back(ans[i]);
    return true;
  }

};

////////////// 题目相关
#include<cassert>

DLX solver;

const int SLOT = 0;
const int ROW = 1;
const int COL = 2;
const int SUB = 3;

// 行/列的统一编解码函数。从1开始编号
int encode(int a, int b, int c) {
  return a*81+b*9+c+1;
}

void decode(int code, int& a, int& b, int& c) {
  code--;
  c = code%9; code /= 9;
  b = code%9; code /= 9;
  a = code;
}

char puzzle[100];

bool read() {
  scanf("%s",puzzle);
    if(puzzle[0]!='e') return true;
    return false;
}

int main() {
	freopen("input.txt","r",stdin); 
  while(read()) {
    solver.init(324);
    for(int r = 0; r < 9; r++)
      for(int c = 0; c < 9; c++) 
        for(int v = 1; v <= 9; v++)
          if(puzzle[r*9+c] == '.' || puzzle[r*9+c] == v+'0') {
            vector<int> columns;
            columns.push_back(encode(SLOT, r, c));
            columns.push_back(encode(ROW, r, v-1));
            columns.push_back(encode(COL, c, v-1));
            columns.push_back(encode(SUB, (r/3)*3+c/3, v-1));
            solver.addRow(encode(r, c, v-1), columns);
          }

    vector<int> ans;
    assert(solver.solve(ans));
    for(int i = 0; i < ans.size(); i++) {
      int r, c, v;
      decode(ans[i], r, c, v);
      puzzle[r*9+c] = '0'+v+1;
    }
    printf("%s\n", puzzle);
  }
  return 0;
}
