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

#define REP(i, a, b) \
    for (int i = (a); i < (b); i++)
#define TRvi(c, it) \
    for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
    for (vii::iterator it = (c).begin(); it != (c).end(); it++)

#define INF 2000000000 // 2e9
#define INFLL 2000000000000000000 // 2e18
#define esp 0.0000000001
#define PI 3.14159265

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

string s;
int n, pos;

int costchange(char x, char y) {
	return min(abs(x-y), min(abs((x-('a' - 1) + 'z')-y), abs(x-(y-('a' - 1) + 'z'))));
}

int solve() {
	int low = INF, high = -1;
	ll res = 0;
	REP(i, 0, n/2) {
		if (s[i] != s[n-1-i]) {
			if (pos < n/2) {
				low = min(low, i);
				high = max(high, i);
			}
			else {
				low = min(low, n-1-i);
				high = max(high, n-1-i);
			}

			res += costchange(s[i], s[n-1-i]);
		}
	}

	// cout << res << " " << low << " " << high << endl;
	if (high == -1) return res;

	if (pos >= low && pos <= high) {
		res += high - low;
		res += min(pos - low, high - pos);	
	} else if (pos >= high) {
		res += pos - low;
	} else if (pos <= low) {
		res += high - pos;
	}
	return res;
}

int main()
{
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);
	// cout << costchange('z' , 'a') << endl;
    int TC;
    cin >> TC;
    while(TC--) {
    	cin >> n >> pos;
    	pos--;
    	cin >> s;
    	cout << solve() << endl;
    }
    return 0;
}