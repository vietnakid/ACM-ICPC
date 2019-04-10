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

vii arr;
int n, k;
vvii f(4);

int mycmp(ii a, ii b) {
    if (a.second != b.second) return a.second < b.second;
    return a.first < b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        arr.push_back({l, r});
    }
    if (k == 0) {
        cout << -1 << "\n";
        return 0;
    }
    arr.push_back({0, 0});
    f[0].push_back({0, 0});
    sort(arr.begin(), arr.end(), mycmp);
    for (int i = 1; i <= n; i++) {
        int l = arr[i].first;
        int r = arr[i].second;
        for (int j = 1; j <= k; j++) {
            int p = distance(f[j-1].begin(), lower_bound(f[j-1].begin(), f[j-1].end(), make_pair(l, 0))) - 1;
            // cerr << l << " " << r << " " << j << " " << p << "\n";
            if (p >= 0) {
                ll sum = (r - l) + f[j-1][p].second;
                if (f[j].size() == 0) {
                    f[j].push_back({r, sum});
                } else {
                    if (sum > f[j].back().second) {
                        f[j].push_back({r, sum});
                    }
                    // if (r > arr[i-1].second) {
                    //     if (sum > f[j].back().second) {
                    //         f[j].push_back({r, sum});
                    //     }
                    // } else {
                    //     if (sum > f[j].back().second) {
                    //         f[j][f[j].size() - 1] = {r, sum};
                    //     }
                    // }
                }
                // cerr << f[j].size() << " " << f[j].back().second << "\n";
            }
        }
    }
    if (f[k].size() > 0)
        cout << f[k].back().second << "\n";
    else {
        cout << "-1\n";
    }
 	cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}