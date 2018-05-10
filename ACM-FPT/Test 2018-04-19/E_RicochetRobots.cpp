#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define FOR(i, a, b) \
    for (int i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) \
    for (int i = (a); i >= (b); i--)

#define INF 2e9 // 2e9
#define INFLL 2e18 // 2e18
#define esp 1e-9
#define PI 3.14159265

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

int n, w, h, l;
vector<vector<char> > arr;
map< vii, int > mp;
int res = 11;
queue<vii> q;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void makeMove(vii & state) {
	FOR(i, 0, n) {
		FOR (ii, 0, 4) {
			int x = state[i].first;
			int y = state[i].second;
			while (true) {
				int xx = x + dx[ii];
				int yy = y + dy[ii];
				bool ok = true;
				if ((xx < 0 || xx >= h || yy < 0 || yy >= w || arr[xx][yy] == 'W')) {
					ok = false;
					break;
				}

				FOR(k, 0, n) {
					if (k != i && state[k].first == xx && state[k].second == yy) {
						ok = false;
						break;
					}
				}
				if (ok) {
					x = xx; y = yy;
				} else {
					break;
				}
			}

			vii tmp = state;
			int move = mp[state] + 1;
			tmp[i] = {x, y};
			if (mp.find(tmp) == mp.end()) {
				mp[tmp] = move;
				q.push(tmp);
			}
		}
	}
}

void bfs() {
	while (!q.empty()) {
		vii state = q.front();
		q.pop();
		if (arr[state[0].first][state[0].second] == 'X') {
			res = mp[state];
			return;
		}
		makeMove(state);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    scanf("%d %d %d %d", &n, &w, &h, &l);
    char c;
    scanf("%c", &c);
    arr = vector<vector<char> >(h, vector<char> (w));
    vii state(n);
    FOR(i, 0, h) {
    	FOR(j, 0, w) {
    		scanf("%c", &arr[i][j]);
    		// cout << arr[i][j] << ' ' << i << ' ' << j << endl;
    		if (arr[i][j] >= '1' && arr[i][j] <= '4') {
    			state[arr[i][j] - '0' - 1] = {i, j};
    		}
    	}
    	char c;
    	scanf("%c", &c);
    }
    
	q.push(state);
	mp[state] = 0;
    bfs();
    if (res > l) {
    	printf("NO SOLUTION\n");
    } else {
    	printf("%d\n", res);
    }
    return 0;
}