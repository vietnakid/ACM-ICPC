#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;

#define FOR(i, a, b) \
    for (int i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (int i = (a); i <= (b); i++)

#define INF 2e9 // 2e9
#define INFLL 2e18 // 2e18
#define esp 1e-9
#define PI 3.14159265

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);
    int n;
    cin >> n;
    vi arr(n);
    FOR(i, 0, n)  cin >> arr[i];
    vi f = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vi d;
    FOR(i, 0, 3) {
        FOR(j, 0, 12)
            d.push_back(f[j]);
    }
    f[1] = 29;
    FOR(j, 0, 12)
        d.push_back(f[j]);
    f[1] = 28;
    FOR(i, 0, 3) {
        FOR(j, 0, 12)
            d.push_back(f[j]);
    }
    bool check = false;
    FOR(i, 0, 84 - n + 1) {
        check = true;
        FOR(j, 0, n) {
            if (arr[j] != d[i+j]) check = false;
        }
        if (check) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}