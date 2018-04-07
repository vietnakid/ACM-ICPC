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

vvi arr;
vi colors, resarr;
int numBlack, res = 0, n, m;

void backTrack(int node) {
	if (node == n+1) {
		if (res < numBlack) {
			res = numBlack;
			resarr.clear();
			FORE(i, 1, n) {
				if (colors[i] == 0) resarr.push_back(i);
			}
		}
		return;
	}

	bool check = true;
	FOR(i, 0, arr[node].size()) {
		int u = arr[node][i];
		if (colors[u] == 0) {
			check = false;
		}
	}

	if (check) {
		colors[node] = 0;
		numBlack++;
		// cout << node << " " << numBlack << endl;
		backTrack(node+1);
		numBlack--;
	}
	
	colors[node] = 1;
	backTrack(node+1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);
    int TC; cin >> TC;
    while (TC--) {
    	cin >> n >> m;
    	arr = vvi(n+1);
    	FOR(i, 0, m) {
    		int x, y;
    		cin >> x >> y;
    		arr[x].push_back(y);
    		arr[y].push_back(x);
    	}

    	colors = vi(n+1, 1);
    	numBlack = 0;
    	res = 0;
    	backTrack(1);
    	cout << res << endl;
    	FOR(i, 0, resarr.size()-1) {
    		cout << resarr[i] << " ";
    	}
    	cout << resarr[resarr.size() - 1];
    	cout << endl;
    }
    return 0;
}