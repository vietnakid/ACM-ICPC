#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
 
#define N 102
char mat[N][N];
int dis[N][N][N], f[1 << 11][N], n, m;
int qu[2*N*N], lo, hi, x[12], y[12], dirt, robotx, roboty;
bool vst[N][N];
int d[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
 
bool enter() {
	if(scanf("%d%d", &n, &m) == EOF || n == 0 || m == 0) return 0;
	for(int i = 0; i < m; ++i) scanf("%s", mat[i]);
	return 1;
}
 
void bfs(int i) {
	lo = hi = 0; qu[hi++] = x[i]; qu[hi++] = y[i];
	memset(vst, 0, sizeof vst); vst[x[i]][y[i]] = 1;
	for(int step = 0; lo != hi; ++step) {
		//printf("%d %d\n", lo, hi);
		for(int k = (hi-lo)/2; k > 0; --k) {
			int x = qu[lo++], y = qu[lo++];
			dis[i][x][y] = step;
			//printf("%d %d %d %d\n", i, x, y, step);
			for(int j = 0; j < 4; ++j) {
				int xx = x + d[j][0], yy = y + d[j][1];
				if(xx >= 0 && xx < m && yy >= 0 && yy < n && !vst[xx][yy] && mat[xx][yy] != 'x') {
					//printf("%d %d %d %d\n", x, y, xx, yy);
					vst[xx][yy] = 1;
					qu[hi++] = xx; qu[hi++] = yy;
					//printf("%d %d\n", lo, hi);
				}
			}
		}
	}
	//printf("BFS(%d)\n", i);
}
 
inline int F(int state, int t) {
	int & res = f[state][t];
	if(res != -1) return res;
	if(state == 0) return res = dis[t][robotx][roboty];
	res = 1 << 30;
	for(int i = 0; i < dirt; ++i) if(state & 1 << i && dis[t][x[i]][y[i]] != -1)
		res = min(res, max(dis[t][x[i]][y[i]] + F(state & ~(1 << i), i), -1));
	return res;
}
 
void solve() {
	dirt = 0; bool findRob = 0;
	for(int i = 0; i < m; ++i)
		for(int j = 0; j < n; ++j)
			if(mat[i][j] == '*') { x[dirt] = i; y[dirt++] = j; }
			else if(mat[i][j] == 'o') { robotx = i; roboty = j; findRob = 1; }
	if(dirt == 0) { printf("0\n"); return; }
	if(!findRob) { printf("-1\n"); return; }
	//for(int i = 0; i < dirt; ++i) printf("Dirt: %d %d\n", x[i], y[i]);
	memset(dis, -1, sizeof dis);
	for(int i = 0; i < dirt; ++i) bfs(i);
	/*for(int i = 0; i < dirt; ++i) {
		for(int x = 0; x < m; ++x) {
			for(int y = 0; y < n; ++y) printf("%d ", dis[i][x][y]);
			putchar(10);
		}
		putchar(10);
	}*/
	memset(f, -1, sizeof f);
	int res = 1 << 30;
	for(int i = 0; i < dirt; ++i)
		res = min(res, F((1 << dirt) - 1 & ~(1 << i), i));
	printf("%d\n", res == 1 << 30 ? -1 : res);
}
 
int main() {
	enter();
    solve();
	return 0;
}