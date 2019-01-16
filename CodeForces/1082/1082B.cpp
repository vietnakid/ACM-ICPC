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

#define FOR(i, a, b) \
    for (__typeof(b) i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (__typeof(b) i = (a); i <= (b); i++)
#define FORD(i, a, b) \
    for (__typeof(b) i = (a); i >= (b); i--)
#define REP(i, begin, end) \
    for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))


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
    int n; cin >> n;
    string s;
    cin >> s;
    vi arr, brr;
    int state = 2;
    FOR(i, 0, n) {
        if (s[i] == 'G') {
            if (state == 1) {
                arr[arr.size() - 1]++;
            } else {
                state = 1;
                arr.push_back(1);
            }
        } else {
            if (state == -1) {
                brr[brr.size() - 1]++;
            } else if (state == 1) {
                state = -1;
                brr.push_back(1);
            }
        }
    }

    // REP(it, arr.begin(), arr.end()) {
    //     cerr << *it << " ";
    // }
    // cerr << endl;
    // REP(it, brr.begin(), brr.end()) {
    //     cerr << *it << " ";
    // }
    // cerr << endl;
    if (arr.size() == 0) {
        cout << 0 << endl;
    } else if (arr.size() == 1) {
        cout << arr[0] << endl;
    } else {
        int res = *max_element(arr.begin(), arr.end()) + 1;
        FOR(i, 0, arr.size() - 1) {
            if (brr[i] == 1) {
                if (arr.size() > 2) {
                    res = max(res, arr[i] + arr[i+1] + 1);
                } else {
                    res = max(res, arr[i] + arr[i+1]);
                }
            }
        }
        cout << res << endl;
    }

    return 0;
}