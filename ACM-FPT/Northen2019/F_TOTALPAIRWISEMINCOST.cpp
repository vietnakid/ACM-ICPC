#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector< vector<ll> > vvi;
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;
typedef pair<ll, ll> ii;
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
vvi dist(305, vi(305, INT_MAX));
vector<pair<ii, ll>> edge(1005);

ll minLeng(int i, int j, int u, int v) {
    ll res = INT_MAX;

    // i -> u -> v -> j
    ll leng = dist[i][u] + dist[j][v] + 1;
    res = min(res, leng);

    // i -> v -> u -> j
    leng = dist[i][v] + dist[j][u] + 1;
    res = min(res, leng);

    return res;
}

void vietnakid() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        ll c; 
        cin >> u >> v >> c;
        edge[i] = {{u, v}, c};
        dist[u][v] = 1;
        dist[v][u] = 1;
    }
    for (int i = 0; i <= n; i++) {
        dist[i][i] = 0;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    bool isGreater = false;
    ll result = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            if (dist[i][j] != INT_MAX) {
                ll c = LLONG_MAX;
                for (int k = 0; k < m; k++) {
                    int u = edge[k].first.first;
                    int v = edge[k].first.second;
                    if (dist[i][u] == INT_MAX)
                        continue;

                    ll _c = edge[k].second;
                    ll len = minLeng(i, j, u, v);
                    
                    c = min(c, _c * len);
                }
                // cerr << i << " " << j << " " << c << "\n";
                if (result + c > 1000000000) {
                    isGreater = true;
                }
                result = (result + c) % 1000000000;
            }
        }
    }
    if (!isGreater) {
        cout << result << "\n";
    } else {
        string r = to_string(result);
        while (r.size() < 9) {
            r = '0' + r;
        }
        cout << r << "\n";
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
 	cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}