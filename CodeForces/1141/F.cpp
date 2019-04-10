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
#define va second.first
#define nd second.second


ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int n;
int arr[1505];
map<int, vector<pair<int, ii> > > f;
int resVa = 0, res = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> arr[i];
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j >= 0; j--) {
            sum += arr[j];
            pair<int, ii> tmp = {j, {0, 0}};
            int pos = distance(f[sum].begin(), lower_bound(f[sum].begin(), f[sum].end(), tmp));
            pos--;
            if (f[sum].size() == 0) {
                f[sum].push_back({i, {1, j}});
            } else if (pos >= 0) {
                int k = f[sum][pos].va + 1;
                if (k > f[sum].back().va) {
                    f[sum].push_back({i, {k, j}});
                }
            }
            // cerr << j << " -> " << i << "; sum = " << sum <<  " -- pos = " << pos << "; size = " << f[sum].size() << "\n";
            if (f[sum].back().va > res) {
                res = f[sum].back().va;
                resVa = sum;
            }
        }
    }
    cout << res << "\n";
    int r = n;
    for (int i = f[resVa].size() - 1; i >= 0; i--) {
        if (f[resVa][i].first < r) {
            cout << f[resVa][i].nd+1 << " " << f[resVa][i].first+1 << "\n";
            r = f[resVa][i].nd;
        }
    }
 	// cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}