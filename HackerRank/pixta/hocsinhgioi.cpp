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

int n, m, k;
int mark[105], clas[105];
map<int, multiset<int> > mp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> mark[i];
        mark[i] = -mark[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> clas[i];
        mp[clas[i]].insert(mark[i]);
    }
    int res = 0;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        x--;
        if (*mp[clas[x]].begin() != mark[x]) {
            res++;
        }
        // cerr << mark[x] << "\n";
    }
    cout << res << "\n";
    return 0;
}