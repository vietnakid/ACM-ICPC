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

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

vvi arr;
int n;
vi isFree;
vi rr;

void DFS(int u) {
    isFree[u] = false;
    if (arr[u].size() == 1) {
        rr.push_back(u);
    }
    FOR(i, 0, arr[u].size()) {
        int v = arr[u][i];
        if (isFree[v]) {
            DFS(v);
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    cin >> n;
    int res = 0, resu = 0;
    arr = vvi(n+1);
    FOR(i, 0, n-1) {
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    int cnt = 0;
    FORE(i, 1, n) {
        if (arr[i].size() > 2) {
            cnt++;
        }
        if (arr[i].size() > res) {
            res = arr[i].size();
            resu = i;
        }
    }
    if (cnt > 1) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        if (n == 2) {
            cout << "1" << endl << "1 2" << endl;
        } else {
            cout << res << endl;
            isFree = vi(n+1, true);
            DFS(res);
            FOR(i, 0, rr.size()) {
                cout << resu << " " << rr[i] << endl;
            }
        }
        
        
    }
    return 0;
}