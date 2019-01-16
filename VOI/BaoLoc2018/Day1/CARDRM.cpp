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
string arr[55];
bool isMatch[55][55];
int f[55][55], g[55][55];

bool check(string & a, string & b) {
    int cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            cnt += a[i] == b[j];
        }
    }
    return cnt >= 2;
}

int calF(int l, int r) {
    if (f[l][r] != -1) {
        return f[l][r];
    }
    if (r-l <= 1) return true;
    f[l][r] = false;
    for (int i = l+1; i < r; i++) {
        if (calF(l, i) && calF(i, r) && isMatch[l][r]) {
            f[l][r] = true;
            break;
        }
    }
    return f[l][r];
}

int calG(int l, int r) {
    if (g[l][r] != -1) {
        return g[l][r];
    }
    if (calF(l, r)) {
        g[l][r] = r-l-1;
        return g[l][r];
    }
    int ans = 0;
    for (int i = l+1; i < r; i++) {
        ans = max(ans, calG(l, i) + calG(i, r));
    }
    g[l][r] = ans;
    return g[l][r];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    memset(isMatch, false, sizeof(isMatch));
    memset(f, -1, sizeof(f));
    memset(g, -1, sizeof(g));

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            isMatch[i][j] = check(arr[i], arr[j]);
        }
    }

    cout << calG(1, n) << endl;
    return 0;
}