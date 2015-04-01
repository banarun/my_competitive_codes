#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
#include <cmath> 
#include <cstring> 
#include <ctime> 
#include <vector> 
#include <deque> 
#include <set> 
#include <map> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <string> 
#include <algorithm> 
#include <complex> 
#include <climits> 
#include <utility> 
using namespace std; 
#ifdef DEBUG
	#define dbg(args...) { cerr<<#args<<": "; dbgr,args; cerr<<endl;}
#else
	#define dbg(args...)
#endif
struct debugger{template<typename T> debugger& operator , (const T& v){cerr<<v<<" "; return *this; }}dbgr;

typedef pair <int, int> ii;
 
const int Inf = 1000000000;
const int Maxn = 8;
const int Maxd = 8;
const int Maxdo = 4;
const int kdy[Maxd] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int kdx[Maxd] = {-1, 1, -2, 2, -2, 2, -1, 1};
const int rdy[Maxdo] = {-1, 0, 0, 1};
const int rdx[Maxdo] = {0, -1, 1, 0};
const int bdy[Maxdo] = {-1, -1, 1, 1};
const int bdx[Maxdo] = {-1, 1, -1, 1};
 
struct pos {
	ii c1, c2, c3;
	int tim;
	pos(ii c1 = ii(0, 0), ii c2 = ii(0, 0), ii c3 = ii(0, 0), int tim = 0): c1(c1), c2(c2), c3(c3), tim(tim) {}
	bool operator ==(const pos &p) const {
		return c1 == p.c1 && c2 == p.c2 && c3 == p.c3;
	}
};
 
int t;
pos s, e;
int dist[Maxn][Maxn][Maxn][Maxn][Maxn][Maxn][3];
queue <pos> Q;
int res;
 
void Update(const pos &u, int d)
{
	if (d < dist[u.c1.first][u.c1.second][u.c2.first][u.c2.second][u.c3.first][u.c3.second][u.tim]) {
		dist[u.c1.first][u.c1.second][u.c2.first][u.c2.second][u.c3.first][u.c3.second][u.tim] = d;
		Q.push(u);
	}
}
 
void goKnight(const pos &p, int dy, int dx, int d)
{
	pos u(ii(p.c1.first + dy, p.c1.second + dx), p.c2, p.c3, 1);
	if (0 <= u.c1.first && u.c1.first < Maxn && 0 <= u.c1.second && u.c1.second < Maxn && u.c1 != u.c2 && u.c1 != u.c3)
		Update(u, d);
}
 
void goRook(const pos &p, int cy, int cx, int dy, int dx, int d)
{
	pos u(p.c1, ii(p.c2.first + cy, p.c2.second + cx), p.c3, 2);
	if (0 <= u.c2.first && u.c2.first < Maxn && 0 <= u.c2.second && u.c2.second < Maxn && u.c1 != u.c2 && u.c2 != u.c3) {
		Update(u, d); goRook(p, cy + dy, cx + dx, dy, dx, d);
	}
}
 
void goBishop(const pos &p, int cy, int cx, int dy, int dx, int d)
{
	pos u(p.c1, p.c2, ii(p.c3.first + cy, p.c3.second + cx), 0);
	if (0 <= u.c3.first && u.c3.first < Maxn && 0 <= u.c3.second && u.c3.second < Maxn && u.c3 != u.c1 && u.c3 != u.c2) {
		Update(u, d); goBishop(p, cy + dy, cx + dx, dy, dx, d);
	}
}
 
int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d %d %d %d", &s.c1.first, &s.c1.second, &s.c2.first, &s.c2.second, &s.c3.first, &s.c3.second); s.tim = 0;
		e = pos(s.c3, s.c1, s.c2);
		fill((int*)dist, (int*)dist + Maxn * Maxn * Maxn * Maxn * Maxn * Maxn * 3, Inf);
		while (!Q.empty()) Q.pop();
		res = -1;
		dist[s.c1.first][s.c1.second][s.c2.first][s.c2.second][s.c3.first][s.c3.second][s.tim] = 0;
		Q.push(s);
		while (!Q.empty()) {
			s = Q.front(); int d = dist[s.c1.first][s.c1.second][s.c2.first][s.c2.second][s.c3.first][s.c3.second][s.tim]; Q.pop();
			if (s == e) { res = d; break; }
			if (s.tim == 0)
				for (int i = 0; i < Maxd; i++)
					goKnight(s, kdy[i], kdx[i], d + 1);
			else if (s.tim == 1)
					for (int i = 0; i < Maxdo; i++)
						goRook(s, rdy[i], rdx[i], rdy[i], rdx[i], d + 1);
			else for (int i = 0; i < Maxdo; i++)
					goBishop(s, bdy[i], bdx[i], bdy[i], bdx[i], d + 1);
		}
		printf("%d\n", res);
	}
	return 0;
} 
