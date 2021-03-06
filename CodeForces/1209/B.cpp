#include <bits/stdc++.h>
#include <unistd.h>

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

void vietnakid() {
    int n; cin >> n;
    string s; cin >> s;
    vector<string> state(1000, s);
    vii arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    for (int id = 0; id < n; id++) {
        for (int i = arr[id].second; i < 1000; i++) {
            if ((i - arr[id].second) % arr[id].first == 0) {
                state[i][id] = (1 - (state[i-1][id] - '0')) + '0';
            } else {
                state[i][id] = state[i-1][id];
            }
        }
    }
    int res = 0;
    for (int i = 0; i < 1000; i++) {
        int cnt = 0;
        // cerr << state[i] << "\n";
        for (int j = 0; j < n; j++) {
            cnt += state[i][j] == '1';
        }
        res = max(res, cnt);
    }
    cout << res << "\n";
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