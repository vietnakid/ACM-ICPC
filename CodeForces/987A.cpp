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

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    set<string> ss;
    int n; cin >> n;
    FOR(i, 0, n) {
        string s;
        cin >> s;
        ss.insert(s);
    }
    int res = 0;
    if (find(ss.begin(), ss.end(), "purple") == ss.end()) {
        res++;
    }
    if (find(ss.begin(), ss.end(), "green") == ss.end()) {
        res++;
    }
    if (find(ss.begin(), ss.end(), "blue") == ss.end()) {
        res++;
    }
    if (find(ss.begin(), ss.end(), "orange") == ss.end()) {
        res++;
    }
    if (find(ss.begin(), ss.end(), "red") == ss.end()) {
        res++;
    }
    if (find(ss.begin(), ss.end(), "yellow") == ss.end()) {
        res++;
    }
    cout << res << endl;
    if (find(ss.begin(), ss.end(), "purple") == ss.end()) {
        cout << "Power" << endl;
    }
    if (find(ss.begin(), ss.end(), "green") == ss.end()) {
        cout << "Time" << endl;
    }
    if (find(ss.begin(), ss.end(), "blue") == ss.end()) {
        cout << "Space" << endl;
    }
    if (find(ss.begin(), ss.end(), "orange") == ss.end()) {
        cout << "Soul" << endl;
    }
    if (find(ss.begin(), ss.end(), "red") == ss.end()) {
        cout << "Reality" << endl;
    }
    if (find(ss.begin(), ss.end(), "yellow") == ss.end()) {
        cout << "Mind" << endl;
    }
    return 0;
}