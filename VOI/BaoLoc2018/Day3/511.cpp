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

int dp[512][51];
int arr[51];
int n;

int calDP(int state, int step) {
    if (state == 511) return true;
    if (step == n) return false;
    int& res = dp[state][step];
    if (res != -1) return res;
    res = false;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if ((state | arr[i]) == state) cnt++;
    }
    if ((cnt > step) && (!calDP(state, step+1))) {
        res = true;
    }

    for (int i = 0; i < n; i++) {
        if ((state | arr[i]) != state && !calDP(state | arr[i], step+1)) {
            res = true;
        }
    }
    // cerr << state << " " << step << " " << cnt << " " << res << endl;
    return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if (calDP(0, 0)) {
        cout << "FoxCiel" << endl;
    } else {
        cout << "Toastman" << endl;
    }
    return 0;
}