#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector< vii> vvii;

#define INF 1000000007
#define INFLL 1000000000000000000
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int n, m;
int arr[1001][1001];
vector<set<int> > r(1001), c(1001);
vvi row(1001), col(1001);

void vietnakid() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
			r[i].insert(arr[i][j]);
			c[j].insert(arr[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (auto x : r[i]) {
			row[i].push_back(x);
		}
	}

	for (int i = 0; i < m; i++) {
		for (auto x : c[i]) {
			col[i].push_back(x);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int posx = distance(row[i].begin(), find(row[i].begin(), row[i].end(), arr[i][j])) + 1;
			int lrow = row[i].size() - posx;
			int posy = distance(col[j].begin(), find(col[j].begin(), col[j].end(), arr[i][j])) + 1;
			int lcol = col[j].size() - posy;
			// cerr << posx << " " << posy << "\n";
			printf("%d ",max(posx, posy) + max(lrow, lcol));
		}
		printf("\n");
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	#ifdef LOCAL_KID
	freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
	#else
	// online submission
	#endif
	vietnakid();
 	// cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}