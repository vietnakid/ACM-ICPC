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

ll n;

string toBase26(int x) {
	string res = "";
	do {
		int du = x % 26;
		x /= 26;
		char l = 'A' + du;
		res = l + res;
	}
	while (x > 0);
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("input", "r", stdin);d
	// freopen("output", "w", stdout);
	cin >> n;
	ll h = 26, k;
	int leng = 0;
	FORE(i, 1, 7) {
		k = i * h;
		if (n - k < 0) {
			leng = i;
			break;
		} else {
			n -= k;
		}
		h *= 26;
	}
	h = (h / 26) * leng;
	char x = 'A';
	int cnt = 0;
	// cout << x << " " << cnt << " " << leng << " " << h <<  " " << n << endl;
	while (n - h >= 0) {
		n -= h;
		x++;
	}
	// cout << x << " " << cnt << " " << leng << " " << h <<  " " << n << endl;
	
	while (n - leng >= 0) {
		n -= leng;
		cnt++;
	}
	// cout << x << " " << cnt << " " << leng << " " << h <<  " " << n << endl;
	string res = toBase26(cnt);
	while (res.size() < leng - 1) res = 'A' + res;
	res = x + res;
	// cout << res << " " << n << endl;
	cout << res[n] << endl;
    return 0;
}