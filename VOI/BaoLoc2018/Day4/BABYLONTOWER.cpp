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

struct block{
    ll a, b, h;

    int operator < (const block & other) const {
        return make_pair(a, b) < make_pair(other.a, other.b);
    }
};

int n, m;
vector<block> arr;
ll dp[1205];

ll calDP(int u) {
    ll & res = dp[u];
    if (res != -1) return res;
    res = arr[u].h;
    for (int i = 1; i < m; i++) {
        if (arr[u].a < arr[i].a && arr[u].b < arr[i].b) {
            res = max(res, calDP(i) + arr[u].h);
        }
    }
    
    return res;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    while (cin >> n) {
        if (n == 0) break;
        arr.resize(0);
        for (int i = 0; i < n; i++) {
            vi in(3);
            vi permu = {0, 1, 2};
            cin >> in[0] >> in[1] >> in[2];
            do {
                arr.push_back({in[permu[0]], in[permu[1]], in[permu[2]]});
            } while (next_permutation(permu.begin(), permu.end()));
        }
        arr.push_back({0, 0, 0});
        sort(arr.begin(), arr.end());
        memset(dp, -1, sizeof(dp));
        m = arr.size();
        cout << calDP(0) << endl;
    }
    return 0;
}