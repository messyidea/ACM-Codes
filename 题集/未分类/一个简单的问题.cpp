


/*
 * CTU Open Contest 2013
 *
 * Sample solution: Flower Pots
 * Author: Jan Stoklasa
 */
 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <cassert>
#include <cstring>
#include <ctime>
 
using namespace std;
 
const int NCellsInPiece = 5;
const int NPentominos = 12;
const int NDimensions = 2;
const int NTransforms = 8;
 
int pentomino[NPentominos][NCellsInPiece][NDimensions] = {{{0,1},{1,0},{1,1},{2,1},{2,2}},   // F                                  
                                                          {{0,0},{1,0},{2,0},{3,0},{4,0}},   // I
                                                          {{0,0},{0,1},{1,0},{2,0},{3,0}},   // L
                                                          {{1,0},{2,0},{2,1},{3,1},{4,1}},   // N
                                                          {{2,0},{3,0},{3,1},{4,0},{4,1}},   // P 
                                                          {{2,1},{3,1},{4,0},{4,1},{4,2}},   // T
                                                          {{3,0},{3,1},{3,2},{4,0},{4,2}},   // U
                                                          {{2,0},{2,1},{2,2},{3,0},{4,0}},   // V
                                                          {{2,1},{2,2},{3,0},{3,1},{4,0}},   // W
                                                          {{2,1},{3,0},{3,1},{3,2},{4,1}},   // X
                                                          {{1,1},{2,1},{3,0},{3,1},{4,1}},   // Y
                                                          {{2,1},{2,2},{3,1},{4,0},{4,1}}};  // Z
 
int transformation[NTransforms][NDimensions][NDimensions] = {{{ 1, 0}, { 0, 1}}, {{ 0, 1}, {-1, 0}}, {{-1, 0}, { 0,-1}}, {{ 0,-1}, { 1, 0}}, {{ 0, 1}, { 1, 0}}, {{ 1, 0}, { 0,-1}}, {{ 0,-1}, {-1, 0}}, {{-1, 0}, { 0, 1}}};
 
int comparePoints(const void* px, const void* py)
{
    const int* x = reinterpret_cast<const int*>(px);
    const int* y = reinterpret_cast<const int*>(py);
    if (x[0] != y[0])
        return x[0] - y[0];
    else
        return x[1] - y[1];
}
 
void transform(int x[2], int t[2][2], int r[2])
{
    r[0] = x[0]*t[0][0] + x[1]*t[0][1];
    r[1] = x[0]*t[1][0] + x[1]*t[1][1];
}
 
template <int N>
class Polynomino
{
public:
    void dbg() const
    {
        int x[N][N];
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
            {
                x[i][j]=0;
            }
        for(int i=0;i<N;i++)
        {
            x[p[i][0]][p[i][1]] = 1;
        }
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if (x[i][j]!=0)
                    cout << 'O';
                else 
                    cout << ' ';
            }
            cout << endl;
        }
    }
 
    int p[N][NDimensions];
 
    Polynomino()
    {
    }
 
    Polynomino(int x[N][NDimensions])
    {
        memcpy(p,x,sizeof(p));
    }
 
    bool operator==(const Polynomino<N>& x) const
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < NDimensions; j++)
            {
              if (p[i][j] != x.p[i][j])
                  return false;
            }
          return true;
    }
 
    class Comparer
    {
    public:
 
        bool operator()(const Polynomino<N>& x, const Polynomino<N>& y)
        {
            for (int i = 0; i < N; i++)
            for (int j = 0; j < NDimensions; j++)
            {
                if (x.p[i][j] < y.p[i][j])
                    return true;
                else if (x.p[i][j] > y.p[i][j])
                    return false;
            }
            return false;
        }
    };
 
    Polynomino<N> canonicalOrientation()
    {
        Polynomino min = *this;
        for (int i = 0; i < NTransforms; i++)
        {
           Polynomino p = transform(transformation[i]);
           if (Comparer()(p, min))
               min = p;
        }
        return min;
    }
 
    void normalize()
    {
        int minx = p[0][0];
        int miny = p[0][1];
        for (int i = 0; i < N; i++)
        {
            if (p[i][0] < minx)
                minx = p[i][0];
            if (p[i][1] < miny)
                miny = p[i][1];
        }
        for (int i = 0; i < N; i++)
        {
            p[i][0] -= minx;
            p[i][1] -= miny;
        }
        qsort(p,N,sizeof(int[2]),comparePoints);
    }
 
    Polynomino<N> transform(int t[2][2])
    {
        Polynomino<N> q;
        for (int i=0;i<N;i++)
        {
            ::transform(p[i],t,q.p[i]);
        }
        q.normalize();
        return q;
    }
 
    void getUniqueOrientedPentominos(vector<Polynomino<N> >& v)
    {
        for (int i=0;i<NTransforms;i++)
        {
            v.push_back(transform(transformation[i]));
        }
        sort(v.begin(), v.end(), typename Polynomino<N>::Comparer());
        v.erase(unique(v.begin(), v.end()), v.end());
    }
};
 
template<int N, int M>
bool canJoin(const Polynomino<N>& lhs, int x, int y, const Polynomino<M>& rhs)       
{
    assert(0 <= x && x <= N && 0 <= y && y <= N);
    bool connected = false;
    static long int counter = 0;
    static long int xx[N+M][N+M];
    if (counter == 0) 
        memset(xx,0,sizeof(xx));
    for (int i = 0; i < N; i++)
    {
        xx[lhs.p[i][0]][lhs.p[i][1]] = counter + 1;
    }
    for (int j = 0; j < M; j++)
    {
        int rx = rhs.p[j][0]+x;
        int ry = rhs.p[j][1]+y;
        if (xx[rx][ry] == counter + 1)
        {
            counter += 3;
            return false;
        }
        xx[rx][ry] = counter + 2;
        connected |= (xx[rx+1][ry] == counter + 1) || (xx[rx][ry+1] == counter + 1) || (xx[rx-1][ry] == counter + 1) || (xx[rx][ry-1] == counter + 1);
    }
    counter += 3;
    return connected;
}
 
template<int N, int M>
Polynomino<N+M> join(const Polynomino<N>& lhs, int x, int y, const Polynomino<M>& rhs)
{
    assert(0 <= x && x <= N && 0 <= y && y <= N);
    Polynomino<N+M> q;
    for (int i = 0; i < N; i++)
    {
        q.p[i][0] = lhs.p[i][0];
        q.p[i][1] = lhs.p[i][1];
    }
    for (int j = 0; j < M; j++)
    {
        q.p[j+N][0] = rhs.p[j][0] + x;
        q.p[j+N][1] = rhs.p[j][1] + y;
    }
    q.normalize();
    return q;
}
 
template<int N, int M>
void combine(const Polynomino<N>& lhs, const Polynomino<M>& rhs, vector<Polynomino<N+M> >& result)
{
    for(int i=0;i<=N;i++)
        for(int j=0;j<=N;j++)
        {
            if (canJoin(lhs,i,j,rhs))
            {
                result.push_back(join<N,M>(lhs,i,j,rhs));
            }
        }
}
 
char CC[NPentominos] = {'F','I','L','N','P','T','U','V','W','X','Y','Z'};
int c2i(char c)
{
    assert('A' <= c && c <= 'Z');
               // A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y  Z
    int x[26] = {-1,-1,-1,-1,-1, 0,-1,-1, 1,-1,-1, 2,-1, 3,-1, 4,-1,-1,-1, 5, 6, 7, 8, 9,10,11};
    int r = x[c-'A'];
    assert(0 <= r && r < NPentominos);
    return r;
}
 
Polynomino<5> c2p(char c)
{
    return Polynomino<5>(pentomino[c2i(c)]);
}
 
int main(int argc, char* argv[])
{
    vector<vector<Polynomino<5> > > v5;
 
    for (int i=0; i < NPentominos; i++)
    {
        vector<Polynomino<5> > v;
        c2p(CC[i]).getUniqueOrientedPentominos(v);
        v5.push_back(v);
    }
 
    vector<Polynomino<10> > v10[NPentominos][NPentominos];
    for (int i=0; i<NPentominos; i++)
        for (int j=0; j<NPentominos; j++)
            for (int k=0; k < v5[i].size(); k++)
                for (int m=0; m < v5[j].size(); m++)
                    combine<5,5>(v5[i][k], v5[j][m], v10[i][j]);
 
string group1, group2;
while (cin >> group1 >> group2)
{
    assert(1 <= group1.length() && group1.length() <= 3 && 1 <= group2.length() && group2.length() <= 3);
    for(int i=0; i < group1.length(); i++) assert(0 <= c2i(group1[i]) && c2i(group1[i]) < NPentominos);
    for(int i=0; i < group2.length(); i++) assert(0 <= c2i(group2[i]) && c2i(group2[i]) < NPentominos);
    sort(group1.begin(),group1.end());
    sort(group2.begin(),group2.end());
    if (group1 == group2)
        cout << "YES" << endl;
    else if (group1.length() != group2.length())
        cout << "NO" << endl;
    else if (group1.length() == 1)
        cout << "NO" << endl;
    else if (group1.length() == 2)
    {
        map <Polynomino<10>, bool, Polynomino<10>::Comparer> m;
        vector<Polynomino<10> > lhs;
        vector<Polynomino<10> > rhs;
 
        for (int i=0; i < v10[c2i(group1[0])][c2i(group1[1])].size(); i++)
        {
            lhs.push_back(v10[c2i(group1[0])][c2i(group1[1])][i].canonicalOrientation());
        }
        for (int i=0; i < v10[c2i(group1[1])][c2i(group1[0])].size(); i++)
        {
            lhs.push_back(v10[c2i(group1[1])][c2i(group1[0])][i].canonicalOrientation());
        }
        for (int i=0; i < v10[c2i(group2[0])][c2i(group2[1])].size(); i++)
        {
            rhs.push_back(v10[c2i(group2[0])][c2i(group2[1])][i].canonicalOrientation());
        }
        for (int i=0; i < v10[c2i(group2[1])][c2i(group2[0])].size(); i++)
        {
            rhs.push_back(v10[c2i(group2[1])][c2i(group2[0])][i].canonicalOrientation());
        }
        for (int i=0; i < lhs.size(); i++)
        {
            m[lhs[i]] = true;
        }
        for (int j=0; j < rhs.size(); j++)
        {
            if (m[rhs[j]])
            {
                cout << "YES" << endl;
                goto found2;
            }
        }
        cout <<  "NO" << endl;
found2: ;
    }
    else if (group1.length() == 3)
    {
        int remaining[3][2] = {{1,2},{0,2},{0,1}};
        vector<Polynomino<15> > lhs;
        for(int r=0; r < group1.length();  r++)
            for(int i=0; i < v5[c2i(group1[r])].size(); i++)
            {
                for(int j=0; j < v10[c2i(group1[remaining[r][0]])][c2i(group1[remaining[r][1]])].size(); j++)
                {
                    combine<10,5>(v10[c2i(group1[remaining[r][0]])][c2i(group1[remaining[r][1]])][j], v5[c2i(group1[r])][i], lhs);
                }
                for(int j=0; j < v10[c2i(group1[remaining[r][1]])][c2i(group1[remaining[r][0]])].size(); j++)
                {
                    combine<10,5>(v10[c2i(group1[remaining[r][1]])][c2i(group1[remaining[r][0]])][j], v5[c2i(group1[r])][i], lhs);
                }
            }
        for (int i=0; i < lhs.size(); i++)
        {
            lhs[i] = lhs[i].canonicalOrientation();
        }
        vector<Polynomino<15> > rhs;
        for(int r=0; r < group2.length(); r++)
            for(int i=0; i < v5[c2i(group2[r])].size(); i++)
            {
                for(int j=0; j < v10[c2i(group2[remaining[r][0]])][c2i(group2[remaining[r][1]])].size(); j++)
                {
                    combine<10,5>(v10[c2i(group2[remaining[r][0]])][c2i(group2[remaining[r][1]])][j], v5[c2i(group2[r])][i], rhs);
                }
                for(int j=0; j < v10[c2i(group2[remaining[r][1]])][c2i(group2[remaining[r][0]])].size(); j++)
                {
                    combine<10,5>(v10[c2i(group2[remaining[r][1]])][c2i(group2[remaining[r][0]])][j], v5[c2i(group2[r])][i], rhs);
                }
            }
        for (int i=0; i < rhs.size(); i++)
        {
            rhs[i] = rhs[i].canonicalOrientation();
        }
        map <Polynomino<15>, bool, Polynomino<15>::Comparer> m;
        for (int i=0; i < lhs.size(); i++)
        {
            m[lhs[i]] = true;
        }
        for (int j=0; j < rhs.size(); j++)
        {
            if (m[rhs[j]])
            {
                cout << "YES" << endl;
                goto found3;
            }
        }
        cout << "NO" << endl;
found3: ;
    }
}
    return 0;
}
