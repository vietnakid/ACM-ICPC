#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
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

vii arr, sorted;
int n, m;
vii edge;
ll sumA[300005], sumB[300005];
ll res[300005];

void vietnakid() {
    cin >> n >> m;
    arr.resize(n+1); edge.resize(m);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].first >> arr[i].second;
        sorted.push_back({arr[i].first - arr[i].second, i});
    }
    for (int i = 0; i < m; i++) {
        cin >> edge[i].first >> edge[i].second;
    }
    sort(sorted.begin(), sorted.end());
    for (int i = 1; i <= n; i++) {
        sumA[i] = sumA[i-1] + arr[sorted[i-1].second].first;
        sumB[i] = sumB[i-1] + arr[sorted[i-1].second].second;
    }
    for (int i = 0; i < n; i++) {
        int u = sorted[i].second;
        res[u] = sumA[i] + (i*arr[u].second) + (sumB[n] - sumB[i+1]) + (n-i-1) * arr[u].first;
        // cerr << u << " " << i << " sumB = " << sumA[i] + (i*arr[u].second)  << " | SumA = " << (sumB[n] - sumB[i+1]) + (n-i-1) * arr[u].first << "\n";
        // cerr << sumB[n] - sumB[i+1] << "\n";
    }
    for (int i = 0; i < m; i++) {
        int a = edge[i].first, b = edge[i].second;
        ll r = min(arr[a].first + arr[b].second, arr[a].second + arr[b].first);
        res[a] -= r; res[b] -= r;
    }
    for (int i = 1; i <= n; i++) {
        cout << res[i] << " "; 
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