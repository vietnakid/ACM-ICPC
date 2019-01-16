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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll res = 0;
    ll i = 0, s1 = 1, s2 = 1;
    while (s[i] == s[i+1]) {
        i++;
        s1++;
    }
    i = n-1;
    while (s[i] == s[i-1]) {
        i--;
        s2++;
    }
    if (s1 == n) {
        res = (n*(n+1)/2) + 1;
    } else if (s[0] == s[n-1]) {
        res = (s1+1) * (s2+1);
    } else {
        res = s2 + s1 + 1;
    }
    res = res % 998244353;
    cout << res << endl;
    return 0;
}