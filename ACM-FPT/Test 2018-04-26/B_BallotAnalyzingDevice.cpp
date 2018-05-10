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

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

vi arr;
int n, m;
vector<string> names;

int analysis(string s) {
	int res = -1;
	FOR(i, 0, s.size()) {
		if (s[i] == 'X') {
			if (res == -1) {
				res = i;
			} else {
				res = -2;
			}
		}
	}
	return res;
}

float toPercent(double a, double m) {
	double s = round(a/m * 10000) / 100.;
	return s;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    
    cin >> n >> m;
    arr = vi(n, 0);
    names = vector<string>(n);
    FOR(i, 0, n) {
    	cin >> names[i];
    }
    FOR(j, 0, m) {
    	string s;
    	cin >> s;
    	int voted = analysis(s);
    	if (voted >= 0) {
    		arr[voted]++;
    	}
    }
    vii brr;
    FOR(i, 0, n) {
    	brr.push_back({arr[i], n-i});
    }
    sort(brr.begin(), brr.end(), greater<ii>());
    int has = 0;
    FOR(i, 0, n) {
    	printf("%s %.2lf%%\n",names[n - brr[i].second].c_str(), toPercent(brr[i].first, m));
    	has += brr[i].first;
    }
   	printf("Invalid %.2lf%%\n", toPercent(m-has, m));
    return 0;
}