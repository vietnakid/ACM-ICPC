#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int n;
vvi arr;
int src;

void solve() {
    int maxx = 0, resDay = 0;
    queue<int> q1, q2;
    vi isFree(n, true);
    isFree[src] = false;
    q1.push(src);
    int day = 0;
    while (true) {
        day++;
        q2 = queue<int>();
        while (!q1.empty()) {
            int u = q1.front();
            q1.pop();
            FOR(i, 0, arr[u].size()) {
                int v = arr[u][i];
                if (isFree[v]) {
                    q2.push(v);
                    isFree[v] = false;
                }
            }
        }

        q1 = q2;
        int cnt = q2.size();
        if (cnt > maxx) {
            maxx = cnt;
            resDay = day;
        }
        if (cnt == 0) {
            break;
        }
    }
    if (maxx == 0) {
        cout << 0 << endl;
    } else {
        cout << maxx << " " << resDay << endl;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    cin >> n;
    arr = vvi(n);
    FOR(i, 0, n) {
        int m;
        cin >> m;
        FOR(j, 0, m) {
            int x;
            cin >> x;
            arr[i].push_back(x);
        }
    }
    int TC;
    cin >> TC;
    while (TC--) {
        cin >> src;
        solve();
    }
    return 0;
}