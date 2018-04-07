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
typedef set<int> si;

#define FOR(i, a, b) \
    for (int i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (int i = (a); i <= (b); i++)

#define INF 2e9 // 2e9
#define INFLL 2e18 // 2e18
#define esp 1e-9
#define PI 3.14159265

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

struct point {
	int x, y;
};

int m, n, k;
point start;
vector<point> points;
vvi f;

int dis(point a, point b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

int cal(int status, int last) {
	
	int newstatus = status & (~(1 << last));

	if (newstatus == 0) f[status][last] = dis(start, points[last]);

	if (f[status][last] != INF) return f[status][last];

	int res = INF;
	FOR(i, 0, k) {
		if (newstatus & (1 << i)) {
			res = min(res, cal(newstatus, i) + dis(points[i], points[last]));
		}
	}
	f[status][last] = res;
	return res;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);
    int TC; cin >> TC;
    while (TC--) {
    	points.clear();

    	cin >> m >> n;
    	cin >> start.x >> start.y;
    	cin >> k;

    	FOR(i, 0, k) {
    		point p;
    		cin >> p.x >> p.y;
    		points.push_back(p);
    	}

    	f = vvi(1 << k);
    	FOR(i, 0, 1 << k) {
    		f[i] = vi(k, INF);
    	}

    	int res = INF;
    	FOR(i, 0, k) {
    		res = min(res, cal((1 << k) - 1, i) + dis(points[i], start));
    	}
    	cout << "The shortest path has length " << res << endl;
    }
    return 0;
}