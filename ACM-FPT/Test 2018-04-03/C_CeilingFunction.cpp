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

int n, k;
set<string> result;
vi arr;
vi tree(1048577);

void construct() {
	fill(tree.begin(), tree.end(), 0);
	FOR(i, 0, k) {

		int node = 0;
		while (tree[node] != 0) {
			if (tree[node] < arr[i]) {
				node = node * 2 + 1;
			} else {
				node = node * 2 + 2;
			}
		}
		tree[node] = arr[i];
	}
	string s = "";
	FOR (i, 0, 1048577) {
		if (tree[i] == 0) s += '0';
		else s+= '1';
	}
	result.insert(s);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("input", "r", stdin);d
	// freopen("output", "w", stdout);	
	cin >> n >> k;
	FOR(i, 0, n) {
		arr.clear();
		FOR(j ,0, k) {
			int x;
			cin >> x;
			arr.push_back(x);
		}
		construct();
	}
	cout << result.size() << endl;
    return 0;
}