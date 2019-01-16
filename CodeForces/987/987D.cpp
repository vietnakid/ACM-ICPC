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

int n, m, s, k;
vi color;
vvi arr;
vvi cto;
vi visit;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    cin >> n >> m >> s >> k;
    color = vi(n+1);
    FORE(i, 1, n) {
        cin >> color[i];
    }
    arr = vvi(n+1);
    FOR(i, 0, m) {
        int x, y;
        cin >> x >> y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    
    cto = vvi(101, vi(n+1, INF));
    FORE(c, 1, s) {
        visit = vi(n+1, false);
        queue<int> q;
        FORE(u, 1, n) {
            if (color[u] == c) {
                q.push(u);
                visit[u] = true;
                cto[c][u] = 0;
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            FOR(i, 0, arr[u].size()) {
                int v = arr[u][i];
                if (!visit[v]) {
                    q.push(v);
                    visit[v] = true;
                    cto[c][v] = cto[c][u] + 1;
                }
            }
        }
    }
    FORE(i, 1, n) {
        vi res;
        FORE(c, 1, s) {
            res.push_back(cto[c][i]);
        }
        sort(res.begin(), res.end());
        int cnt = 0;
        FOR(j, 0, k) {
            cnt += res[j];
        }
        cout << cnt << " ";
    }
    return 0;   
}