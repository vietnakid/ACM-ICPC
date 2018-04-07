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

bool check(string ss) {
	REP (i, 0, 8) {
		if (ss[i] != ss[i%2]) return false;
	}
	return true;
}

void sovle(string s) {
	bool canGo = true;

	while (canGo) {
		canGo = false;

		bool ok = false;
		while (!ok) {
			ok = true;
			// cout << "size = " << s.size() << endl;
			int n = s.size() - 1;
			REP(i, 0, n) {
				// cout << i << endl;
				if (s[i] == s[i+1]) {
					ok = false;
					s = s.erase(i,1);
					s = s.erase(i,1);
					break;
				}
			}

		}

		int n = s.size() - 7;
		REP(i, 0, n) {
			string ss = s.substr(i, 8);
			if (check(ss)) {
				canGo = true;
				s = s.erase(i, 8);
				break;
			}
		}
	}

	if (s == "") {
		cout << "closed" << endl;
	} else {
		cout << "open" << endl;
	}
}

int main()
{
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);
    int n;
    cin >> n;
    while (n--) {
    	string s;
    	cin >> s;
    	sovle(s);
    }
    return 0;
}