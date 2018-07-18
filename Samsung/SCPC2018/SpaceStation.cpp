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

int n, m;
vector<set<int> > arr;
queue<int> degree2;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int TC;
    cin >> TC;
    FORE(tc, 1, TC) {
        cout << "Case #" << tc << endl;
        cin >> n >> m;
        arr = vector<set<int> >(n+1);
        FOR(i, 0, m) {
            int u, v;
            cin >> u >> v;
            arr[u].insert(v);
            arr[v].insert(u);
        }
        FORE(i, 1, n) {
            if (arr[i].size() == 2) {
                degree2.push(i);
            }
        }
        int res = 0;
        while (degree2.size() != 0) {
            int u = degree2.front();
            degree2.pop();
            // cerr << u << endl;
            if (arr[u].size() != 2) {
                continue;
            }
            int v1 = *arr[u].begin();
            arr[u].erase(arr[u].begin());
            int v2 = *arr[u].begin();
            arr[u].erase(arr[u].begin());
            // cerr << u << " " << v1 << " " << v2 << endl;
            if (arr[v1].find(v2) != arr[v1].end()) {
                res++;
                arr[v1].erase(u);
                if (arr[v1].size() == 2) {
                    degree2.push(v1);
                }
                arr[v2].erase(u);
                if (arr[v2].size() == 2) {
                    degree2.push(v2);
                }
            } else {
                arr[u].insert(v1);
                arr[u].insert(v2);
            }
        }
        cout << n - res << endl;
    }
    return 0;
}