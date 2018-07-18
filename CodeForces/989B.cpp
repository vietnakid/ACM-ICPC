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
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    bool isOk = false;
    FOR(i, 0, n-p) {
        if (s[i] == '.') {
            if (i - p >= 0) {
                if (s[i-p] == '0') {
                    s[i] = '1';
                    isOk = true;
                    break;
                } else if (s[i-p] == '1') {
                    s[i] = '0';
                    isOk = true;
                    break;
                } else {
                    s[i] = '0';
                    s[i-p] = '1';
                    isOk = true;
                    break;
                }
            }
            if (i + p < n) {
                if (s[i+p] == '0') {
                    s[i] = '1';
                    isOk = true;
                    break;
                } else if (s[i+p] == '1') {
                    s[i] = '0';
                    isOk = true;
                    break;
                } else {
                    s[i] = '0';
                    s[i+p] = '1';
                    isOk = true;
                    break;
                }
            }
        }
    }
    if (!isOk) {
        cout << "No" << endl;
    } else {
        FOR(i, 0, n) {
            if (s[i] != '.') {
                cout << s[i];
            } else {
                cout << '0';
            }
        }
        cout << endl;
    }
    return 0;
}