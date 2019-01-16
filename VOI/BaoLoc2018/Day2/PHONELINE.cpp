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

ll n, m, k;
vvii arr;

bool canConnect(int cost) {
    vvii brr(n+1);
    for (int i = 1; i <= n; i++) {
        int leng = arr[i].size();
        for (int j = 0; j < leng; j++) {
            if (arr[i][j].second > cost) 
                brr[i].push_back({arr[i][j].first, 1});
            else
                brr[i].push_back({arr[i][j].first, 0});
        }
    }
    vi d(n+1, INF);
    bitset<1001> isFree;
    isFree.set();
    d[1] = 0;
    isFree[1] = false;
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        ii state = pq.top();
        pq.pop();
        int u = state.second;
        if (u == n) {
            return d[u] <= k;
        }
        for (int i = 0; i < brr[u].size(); i++) {
            int v = brr[u][i].first;
            int cost = brr[u][i].second;
            if (d[v] > d[u] + cost) {
                d[v] = d[u] + cost;
                pq.push({d[v], v});
            }
        }
    }   
    return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    cin >> n >> m >> k;
    arr.resize(n+1);
    ll left = 0, right = 0;
    for (int i = 0; i < m; i++) {
        ll u, v, c;
        cin >> u >> v >> c;
        arr[u].push_back({v, c});
        arr[v].push_back({u, c});
        right = max(right, c);
    }
    int res = -1;
    for (int t = 0; t < 100; t++) {
        if (left > right) break;
        int mid = (left + right) / 2;
        if (canConnect(mid)) {
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << res << endl;
    return 0;
}