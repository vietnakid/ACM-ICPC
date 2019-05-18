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

int n;
vii arr;

void vietnakid() {
    cin >> n;
    arr.resize(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    vi res{1};
    {
        int u = arr[1].first;
        int v = arr[1].second;
        if (arr[u].first == v || arr[u].second == v) {
            res.push_back(u);
            res.push_back(v);
        } else {
            res.push_back(v);
            res.push_back(u);
        }
    }
    while (res.size() < n) {
        int v = res[res.size() - 1];
        int u = res[res.size() - 2];
        if (arr[u].first == v) {
            res.push_back(arr[u].second);
        } else {
            res.push_back(arr[u].first);
        }
    }
    for (auto x : res) {
        cout << x << " ";
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