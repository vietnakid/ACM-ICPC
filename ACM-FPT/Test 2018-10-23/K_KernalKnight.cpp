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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int n;
    cin >> n;
    vi brr(2*n+1, 0), cnt(2*n+1, 0), isFree(2*n+1, true);
    FORE(i, 1, 2*n) {
        int x;
        cin >> x;
        brr[i] = x;
        cnt[x]++;
    }
    set<int> res;
    set<int> cnt0;

    FORE(i, 1, 2*n) {
        if (cnt[i] == 0) {
            cnt0.insert(i);
        }
    }

    while (cnt0.size() > 0) {
        int x = *cnt0.begin();
        cnt0.erase(cnt0.begin());
        res.insert(x);
        isFree[x] = false;
        if (!isFree[brr[x]]) continue;
        isFree[brr[x]] = false;
        cnt[brr[brr[x]]]--;

        // cerr << x << " " << brr[x] << " " << brr[brr[x]] << " " << cnt[brr[brr[x]]] << endl;
        if (cnt[brr[brr[x]]] == 0) {
            cnt0.insert(brr[brr[x]]);
        }
    }

    FORE(i, 1, 2*n) {
        if (isFree[i]) {
            res.insert(i);
            isFree[i] = false;
            isFree[brr[i]] = false;
        }
    }

    for (set<int>::iterator it = res.begin(); it != res.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}