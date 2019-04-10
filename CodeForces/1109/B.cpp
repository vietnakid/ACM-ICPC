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

int solve(string s) {
    if (s.size() % 2 == 1) {
        return 2;
    }
    string lf = s.substr(0, s.size() / 2);
    string rg = s.substr(s.size() / 2, s.size());
    if (lf != rg) {
        return 1;
    }
    return solve(lf);
}

int cnt[256];

void vietnakid() {
    string s;
    cin >> s;
    
    for (auto x : s) {
        cnt[x]++;
    }
    int n = s.size();
    if (n <= 3) {
        cout << "Impossible" << "\n";
        return;
    }
    cerr << cnt['o'];
    if (*max_element(cnt, cnt+256) >= n - 1) {
        cout << "Impossible" << "\n";
        return;
    }
    if (n % 2 == 1) {
        cout << 2 << "\n";
    } else {
        cout << solve(s) << "\n";
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