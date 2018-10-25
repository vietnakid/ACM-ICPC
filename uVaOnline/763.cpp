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
    for (int i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) \
    for (int i = (a); i >= (b); i--)

#define INF 1e9+7
#define INFLL 1e18+7
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    vl fibo(101);
    fibo[0] = 1;
    fibo[1] = 2;
    FOR(i, 2, 101) fibo[i] = fibo[i-1] + fibo[i-2];
    string a, b;
    while (getline(cin, a)) {
        getline(cin, b);
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int s1 = 0, s2 = 0;
        FOR(i, 0, a.size()) {
            s1 += (a[i] - '0') * fibo[i];
        }
        FOR(i, 0, b.size()) {
            s2 += (b[i] - '0') * fibo[i];
        }
        // cerr << a << " " << b << " " << s1 << " " << s2 << endl;
        int s = s1 + s2;
        string res = "";
        FORD(i, 100, 0) {
            if (fibo[i] <= s) {
                cerr << fibo[i] << " " << s << endl;
                s -= fibo[i];
                res += '1';
                i--;
            } else {
                res += '0';
            }
        }
        int i = 0;
        while (res[i] == '0') {
            i++;
        }
        for(;i<res.size();i++) {
            cout << res[i];
        }
        cout << endl;
    }
    return 0;
}